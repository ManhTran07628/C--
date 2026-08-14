#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e3+7;
int n;
ll a[MM],k;
vector<ll> A,B;

void Try(int id,int r,ll sum,vector<ll> &f)
{
    if(sum > k) return;
    if(id == r + 1) f.push_back(sum);
    if(id > r) return;
    Try(id + 1,r,sum + a[id],f);
    Try(id + 1,r,sum,f);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    Try(1, n / 2, 0, A);
    Try(n / 2 + 1, n, 0, B);
    sort(B.begin(),B.end());
    ll res = 0;
    for(auto x:A) {
        int l = lower_bound(B.begin(),B.end(),k - x) - B.begin();
        int r = upper_bound(B.begin(),B.end(),k - x) - B.begin();
        res += r - l;
    }
    cout << res;
    return 0;
}