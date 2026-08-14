#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+1;
ll f[N],p[N];

void cntdiv()
{
    for(ll i = 1;i <= N;i++) {
        for(ll j = i;j <= N;j+=i) {
            f[j]++;
        }
    }
    for(int i = 1;i <= N;i++) {
        p[i] = p[i-1];
        if(f[i] == 4) p[i]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cntdiv();
    ll q;
    cin >> q;
    while(q--) {
        ll l,r;
        cin >> l >> r;
        cout << p[r] - p[l-1] << '\n';
    }
    return 0;
}