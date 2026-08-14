#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<ll> a;
int main()
{
    ll t1;
    cin >> t1;
    while(t1--) {
        string s,k;
        cin >> s;
        ll kq = 0,bien = 0;
        for(int i = 0;i < s.size();i++) {
            if(isdigit(s[i])) {
                bien = (s[i] - '0') % 2;
            }
            else if(s[i] == '*') {
                i++;
                ll tmp = 0;
                while(isdigit(s[i]) && i < s.size()) {
                    tmp = (s[i] - '0') % 2;
                    i++;
                }
                bien = bien * tmp;
                i--;
            }
            else if(s[i] == '+') {
                kq += bien;
                bien = 0;
            }
        }
        kq += bien;
        cout << (kq % 2 == 0? 0 : 1) << '\n';
    }
    return 0;

}
//5+6+7*3*2*2]
// 5*6*5*2*3+6+2+3+5+7+33341+3
// 123123*51032*51328*31200+5123*12341+52839
