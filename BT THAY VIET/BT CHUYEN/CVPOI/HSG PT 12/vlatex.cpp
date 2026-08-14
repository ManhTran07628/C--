#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n;
struct dl{int a,b,c;};
vector<dl> sec, subsec, subsubsec;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        string x,y; cin >> x >> y;
        if(x == "section") {
            cout << sec.size() + 1 << ' ' << y << '\n';
            sec.push_back({(int) sec.size() + 1,0,0});
        }
        else if(x == "subsection") {
            int a,b;
            if(subsec.size() == 0) {
                a = sec.size(), b = 1;
            }
            else {
                a = subsec[ subsec.size() - 1 ].a, b = subsec[ subsec.size() - 1 ].b + 1;
                if(sec.size() != a) {
                    a = sec.size(), b = 1;
                }
            }
            cout << a << "." << b << ' ' << y << '\n';
            subsec.push_back({a,b,0});
        }
        else if(x == "subsubsection") {
            int a,b,c;
            if(subsubsec.size() == 0) {
                int sz = subsec.size();
                a = subsec[sz - 1].a, b = subsec[sz - 1].b, c = 1;
            }
            else {
                int sz = subsubsec.size();
                a = subsubsec[sz - 1].a, b = subsubsec[sz - 1].b, c = subsubsec[sz - 1].c + 1;
                if(subsec[ subsec.size() - 1 ].a != a || subsec[ subsec.size() - 1 ].b != b) {
                    a = subsec[ subsec.size() - 1].a, b = subsec[ subsec.size() - 1].b, c = 1;
                }
            }
            cout << a << "." << b << "." << c << ' ' << y << '\n';
            subsubsec.push_back({a,b,c});
        }

    }
    return 0;   
}