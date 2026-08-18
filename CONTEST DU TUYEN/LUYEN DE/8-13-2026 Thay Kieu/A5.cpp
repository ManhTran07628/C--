#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    // 1. Đọc dữ liệu vào (Input)
    int n = inf.readInt();
    map<string, int> target_words;
    for (int i = 0; i < n; ++i) {
        string w = inf.readToken("[a-z]+", "word");
        target_words[w]++;
    }

    // 2. Đọc đáp án chuẩn của Ban giám khảo (Jury)
    int jury_m = ans.readInt();

    // 3. Đọc và kiểm tra kết quả của thí sinh (Contestant)
    int user_m = ouf.readInt(1, 1000000, "user_m");
    if (user_m != jury_m) {
        quitf(_wa, "WA", jury_m, user_m);
    }

    string current_buffer = "";
    int printed_count = 0;

    for (int i = 1; i <= user_m; ++i) {
        string op = ouf.readToken();
        if (op.length() != 1) {
            quitf(_pe, "WA", i, op.c_str());
        }

        char c = op[0];
        if (c >= 'a' && c <= 'z') {
            current_buffer += c;
        } else if (c == '-') {
            if (current_buffer.empty()) {
                quitf(_wa, "WA", i);
            }
            current_buffer.pop_back();
        } else if (c == 'P') {
            if (target_words.find(current_buffer) == target_words.end() || target_words[current_buffer] == 0) {
                quitf(_wa, "WA", current_buffer.c_str(), i);
            }
            target_words[current_buffer]--;
            printed_count++;
        } else {
            quitf(_pe, "WA", c, i);
        }
    }

    if (printed_count != n) {
        quitf(_wa, "WA", printed_count, n);
    }

    // Đảm bảo không còn dữ liệu thừa

    quitf(_ok, "AC", user_m);
}