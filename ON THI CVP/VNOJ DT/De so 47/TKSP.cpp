#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],n,k,b[10001][10001];
unordered_map<ll,ll> m;
set<ll> st;
void sub1()
{
    if(n <= 1000) {
        ll cnt = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = i;j <= n;j++) {
                m[a[j]]++;
                ll kt = 0;
                for(auto c:m) {
                    if(c.se >= k) {
                        kt = 1;
                        break;
                    }
                }
                if(kt) cnt++;
            }
            m.clear();
        }
        cout << cnt;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TKSP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    return 0;
}