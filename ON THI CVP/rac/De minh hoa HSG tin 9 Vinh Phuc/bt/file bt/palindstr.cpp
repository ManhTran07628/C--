#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "palindstr"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll max1 = 1;
    for(int i = 0;i < n;i++) {
        for(int j = n-1;j >= 0;j--) {
            string tmp;
            for(int t = i;t <= j;t++) {
                tmp += s[t];
            }
            ll kt = 1;
            for(int t = 0;t < tmp.size();t++) {
                if(tmp[t] != tmp[tmp.size()-t-1]) {
                    kt = -1;
                    break;
                }
            }
            ll ans = tmp.size();
            if(kt == 1) max1 = max(max1,ans);
        }
    }
    cout << max1;
    return 0;
}
// 18
// IKACOBEGIGEBOCAHTM