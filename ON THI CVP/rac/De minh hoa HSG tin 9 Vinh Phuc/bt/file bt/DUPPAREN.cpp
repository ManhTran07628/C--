#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
int main() {
    string s;
    cin >> s;
    ll ngoacmo = 0,ngoacdong = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(' && s[i+1] == '(' && i < s.size()) {
            ngoacmo++;
        }
        else if(s[i] == ')' && s[i+1] == ')' && i < s.size()) {
            ngoacdong += ngoacmo;
        }
    }
    cout << ngoacdong;
    return 0;
}
// )(()())
