#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,k;
ll a[MM],ps[MM];
vector<ll> old,nxt;

ll C(int l,int r)
{
    ll sum = ps[r] - ps[l - 1];
    return sum * sum;
}

void dnc(int l,int r,int optl,int optr)
{
    if(l > r) return;
    int mid = (l + r) / 2;
    ll best_L = oo, pos_L = l;
    for(int i = optl;i <= min(optr,mid);i++) {
        ll cost = old[i - 1] + C(i,mid);
        if(cost < best_L) {
            best_L = cost;
            pos_L = i;
        }
    }
    nxt[mid] = best_L;
    dnc(l,mid - 1,optl,pos_L);
    dnc(mid + 1,r,pos_L,optr);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    old.resize(n + 1);
    nxt.resize(n + 1);
    for(int i = 1;i <= n;i++) {
        old[i] = C(1,i);
    }
    for(int i = 2;i <= k;i++) {
        dnc(1,n,1,n);
        old = nxt;
    }
    cout << old[n];
    return 0;
}