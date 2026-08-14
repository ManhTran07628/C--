#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 20 + 7;
int n,k,w[MM];
ll A,B;

vector<ll> sA[MM],sB[MM];

void Try(int l,int r,int id,int cnt,ll sum,vector<ll> adj[])
{
    if(sum > B) return;
    if(id > r) {
        adj[cnt].push_back(sum);
        return;
    }

    Try(l,r,id + 1,cnt + 1,sum + w[id],adj);

    Try(l,r,id + 1,cnt,sum,adj);
}

int bins(ll add_l,int sz,ll lim)
{
    int L = 1, R = sB[sz].size() - 1, res = 0;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(sB[sz][mid] + add_l <= lim) {
            res = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    return res;
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
    for(int i = 1;i <= n;i++) cin >> w[i];
    cin >> A >> B;

    int lenA = n / 2;
    int lenB = n - lenA;

    Try(1,n/2,1,0,0,sA);
    Try(n/2+1,n,n/2+1,0,0,sB);

    for(int i = 0;i <= lenB;i++) {
        sB[i].push_back(0);
        sort(sB[i].begin(),sB[i].end());
    }

    ll res = 0;

    for(int i = 0;i <= lenA;i++) {
        if(sA[i].empty()) continue;
        int sz_a = i, sz_b = k - i;
        if(sz_b > lenB || sz_b < 0) continue;

        for(auto L:sA[sz_a]) {
            int left = bins(L,sz_b,A - 1), right = bins(L,sz_b,B);
            res += right - left;

            // cout << sz_a << ' ' << L << ' ' << left << ' ' << right << '\n';
        } 

    }

    cout << res;
    return 0;
}