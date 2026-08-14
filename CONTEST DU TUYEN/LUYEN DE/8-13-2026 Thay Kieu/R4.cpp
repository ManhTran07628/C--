#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,q,a[MM],sz;

struct QR{int p,x;} qr[MM];


void coordcompres()
{
    vector<int> vec;
    for(int i = 1;i <= n;i++) vec.push_back(a[i]);
    for(int i = 1;i <= q;i++) vec.push_back(qr[i].x);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i = 1;i <= n;i++) 
        a[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin() + 1;
    for(int i = 1;i <= n;i++) 
        qr[i].x = lower_bound(vec.begin(),vec.end(),qr[i].x) - vec.begin() + 1;
    sz = vec.size();
}

int bit[MM];

namespace subtask1
{
    ll res = 0;
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = i + 1;j <= n;j++) 
                if(a[i] > a[j]) res++;
        }

        for(int t = 1;t <= q;t++) {
            int p = qr[t].p, x = qr[t].x;
            for(int i = 1;i < p;i++) {
                if(a[i] > a[p]) res--;
            }
            for(int i = p + 1;i <= n;i++) {
                if(a[p] > a[i]) res--;
            }

            a[p] = x;

            for(int i = 1;i < p;i++) {
                if(a[i] > a[p]) res++;
            }
            for(int i = p + 1;i <= n;i++) {
                if(a[p] > a[i]) res++;
            }
            cout << res << '\n';
        }
    }
}

namespace subtask2
{
    int bitL[MM],bitR[MM];
    ll res = 0;

    void update(int x,int val,int bit[])
    {
        for(;x <= sz;x += (x & -x)) bit[x] += val;
    }

    int get(int x,int bit[])
    {
        int res = 0;
        for(;x > 0;x -= (x & -x)) res += bit[x];
        return res;
    }

    int get_range(int l,int r,int bit[])
    {
        if(l > r) return 0;
        return get(r,bit) - get(l - 1,bit);
    }

    void solve()
    {

        for(int i = 1;i <= n;i++) {
            res += get_range(a[i] + 1,sz,bitL);
            update(a[i],1,bitL);
        }

        fill(bitL+1,bitL+sz+1,0);

        int pos = qr[1].p;
        for(int i = 1;i < pos;i++) {
            update(a[i],1,bitL);
        }

        for(int i = pos + 1;i <= n;i++) {
            update(a[i],1,bitR);
        }

        // cout << res << '\n';

        for(int i = 1;i <= q;i++) {
            int p = qr[i].p, x = qr[i].x;

            res -= get_range(a[p] + 1,sz,bitL);
            res -= get_range(1,a[p] - 1,bitR);

            // cout << res << '\n';

            a[p] = x;

            res += get_range(a[p] + 1,sz,bitL);
            res += get_range(1,a[p] - 1,bitR);

            cout << res << '\n';
        }
    }
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
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++) cin >> qr[i].p >> qr[i].x;
    coordcompres();
    if(n <= 3000 && q <= 3000) subtask1::solve();
    else subtask2::solve();
    return 0;
}