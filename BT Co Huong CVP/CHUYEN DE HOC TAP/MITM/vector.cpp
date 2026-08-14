#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 40;
ll n,U,V,res = 0;
pii a[MM];
map<pii,ll> A;


void TryX(int L,int R,int id,ll sumX,ll sumY)
{
    if(id > R) {
        A[make_pair(sumX,sumY)]++;
        return;
    }
    TryX(L,R,id+1,sumX + a[id].fi,sumY + a[id].se);
    TryX(L,R,id+1,sumX,sumY);
}

void TryY(int L,int R,int id,ll sumX,ll sumY)
{
    if(id > R) {
        res += A[make_pair(U - sumX,V - sumY)];
        return;
    }
    TryY(L,R,id+1,sumX + a[id].fi,sumY + a[id].se);
    TryY(L,R,id+1,sumX,sumY);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    cin >> U >> V;
    TryX(1,n/2,1,0,0);
    TryY(n/2+1,n,n/2+1,0,0);

    cout << res;
    return 0;
}