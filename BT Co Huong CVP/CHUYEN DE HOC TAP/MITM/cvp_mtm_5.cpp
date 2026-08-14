#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 31;
int n;
ll a[MM],T,res = 1;
vector<ll> A,B;

void Try(int l,int r,int id,ll sum,vector<ll> &f,int cnt)
{
    if(sum > T) return;
    if(id == r + 1) {
        if(cnt == 0) return;
        f.push_back(sum);
        res++;
        return;
    }
    Try(l,r,id + 1,sum + a[id],f,cnt+1);
    Try(l,r,id + 1,sum,f,cnt);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T;
    ll sum = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    Try(1, n/2, 1, 0, A, 0);
    Try(n/2+1, n, n/2+1, 0, B, 0);
    // A.push_back(0);
    sort(B.begin(),B.end());
    for(auto x:A) {
        int R = upper_bound(B.begin(),B.end(),T - x) - B.begin();
        res += R - 1;
    }
    cout << res;
    return 0;
}
