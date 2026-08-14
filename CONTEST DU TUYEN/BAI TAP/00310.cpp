#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n; cin >> n;
    if(n <= 'z' - 'a')  {
        for(int i = 0;i < n;i++) {
            char c = 'a' + i;
            cout << c;
        }
    }
    else {
        while(1) {
            for(int i = 'a';i <= 'z';i++) {
                n--;
                char c = i;
                cout << c;
                if(n == 0) return 0;
            }
        }
    }
    return 0;
}