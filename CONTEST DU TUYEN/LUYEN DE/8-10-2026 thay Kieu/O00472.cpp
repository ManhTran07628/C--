#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 20 + 7;
int n,r;
ll T,a[MM];

vector<ll> ssA[MM],ssB[MM];

void Try(int l,int r,int id,int cnt,ll sum,vector<ll> vec[])
{
    if(id > r) {
        vec[cnt].push_back(sum);
        return;
    }

    Try(l,r,id + 1,cnt,sum,vec);
    Try(l,r,id + 1,cnt + 1,sum + a[id],vec);
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
    cin >> n >> r >> T;
    for(int i = 1;i <= n;i++) cin >> a[i];
    Try(1,n / 2,1,0,0,ssA);
    Try(n / 2 + 1,n,n / 2 + 1,0,0,ssB);

    for(int i = 1;i <= n / 2 + 1;i++) {
        sort(ssB[i].begin(),ssB[i].end());
    }

    ll res = oo;

    for(int i = 0;i <= r;i++) {

        int left = i, right = r - i;
        if(right > n - n / 2) continue;

        for(auto Left:ssA[left]) {
            ll pos = upper_bound(ssB[right].begin(),ssB[right].end(),T - Left) - ssB[right].begin();
            if(pos > 0) pos--;
            ll Right = ssB[right][pos];
            res = min(res,abs((Left + Right) - T));
        }
    
    }

    cout << res;
    return 0;
}
