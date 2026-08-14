#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<string> v;

void backtracking(int sum, int id) {
    if (id == n) {
        if (sum == x) {
            // In biểu thức đúng định dạng: A1 ? A2 ? A3 ...
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i];
                if (i < v.size() - 1) cout << ' ';
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 1; i <= 5; ++i) {
        string num = to_string(i);

        // Thử cộng
        v.push_back("+");
        v.push_back(num);
        backtracking(sum + i, id + 1);
        v.pop_back();
        v.pop_back();

        // Thử trừ
        v.push_back("-");
        v.push_back(num);
        backtracking(sum - i, id + 1);
        v.pop_back();
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;

    // Chọn phần tử đầu tiên (chỉ là số, không có dấu)
    for (int i = 1; i <= 5; ++i) {
        v.clear();
        v.push_back(to_string(i));
        backtracking(i, 1);
    }

    return 0;
}
