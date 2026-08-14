#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Strings"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        string a,b,c;
        cin >> a >> b >> c;
        ll kt = 1;
        for(int i = 0;i < a.size();i++) {
            if(a[i] == b[i] && c[i] != a[i]) {
                kt = -1;
                break;
            }
            if(a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) {
                kt = -1;
                break;
            }
        }
        if(kt == -1) {
            cout << "NO" << '\n';
        }
        else cout << "YES" << '\n';
    }
    return 0;
}