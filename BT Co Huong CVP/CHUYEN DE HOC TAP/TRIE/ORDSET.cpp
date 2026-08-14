#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Định nghĩa một ordered_set quản lý các số nguyên tăng dần
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_set;

int q;
ordered_set s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (cin >> q) {
        while (q--) {
            char type;
            int x;
            cin >> type >> x;

            if (type == 'I') {
                s.insert(x); // Tự động bỏ qua nếu đã tồn tại
            } 
            else if (type == 'D') {
                s.erase(x);  // Tự động bỏ qua nếu không tồn tại
            } 
            else if (type == 'K') {
                // x đại diện cho k. Do chỉ số của ordered_set bắt đầu từ 0, ta tìm x - 1
                if (x <= 0 || x > (int)s.size()) {
                    cout << "invalid\n"; // Đề bài yêu cầu in chữ thường 'invalid'
                } else {
                    auto it = s.find_by_order(x - 1);
                    cout << *it << "\n";
                }
            } 
            else if (type == 'C') {
                // order_of_key(x) trả về số lượng phần tử nghiêm ngặt nhỏ hơn x
                cout << s.order_of_key(x) << "\n";
            }
        }
    }
    return 0;
}.