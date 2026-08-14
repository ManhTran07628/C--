#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n;
ll a[MM],ps[MM],x;
void init()
{
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
}

namespace subtask2
{
    ll b[MM];
    void solve()
    {
        ll ans = 0;

        for(int i = 1;i <= n;i++) {

            for(int j = 1;j <= n;j++) {

                ll sum = 0;

                for(int k = 1;k <= n;k++) {
                    sum += (a[k] * ((i <= k && k <= j) ? x : 1 ));
                    ans = max(ans,sum);
                    if(sum < 0) sum = 0;
                }


            }


        }

        cout << ans;
    }
}

namespace subtask4
{   
    void solve()
    {
        if(x == 0) x = 1;
        if(x > 0) {
            int min_pos = 0,l = 0,r = 0;
            ll max_seg = 0,ans = 0;
            for(int i = 1;i <= n;i++) {
                ps[i] = ps[i-1] + a[i];
                if(ps[i] - ps[min_pos] > max_seg) {
                    max_seg = ps[i] - ps[min_pos];
                    l = min_pos+1, r = i;
                }
                if(ps[i] < ps[min_pos]) min_pos = i;
            }
            for(int i = l;i <= r;i++) a[i] *= x;
        }
        else {
            int min_pos = 0,l = 0,r = 0;
            ll min_seg = 0;
            for(int i = 1;i <= n;i++) {
                ps[i] = ps[i-1] + a[i];
                if(ps[i] - ps[min_pos] < min_seg) {
                    min_seg = ps[i] - ps[min_pos];
                    l = min_pos+1, r = i;
                }
                if(ps[i] > ps[min_pos]) min_pos = i;
            }
            for(int i = l;i <= r;i++) a[i] *= x;
        }
        ll sum = 0,min_pos = 0;
        for(int i = 1;i <= n;i++) {
            ps[i] = ps[i-1] + a[i];
            if(ps[i] - ps[min_pos] > sum) sum = ps[i] - ps[min_pos];
            if(ps[i] < ps[min_pos]) min_pos = i;
        }
        cout << sum;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "FLOWER"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    subtask4::solve();
    return 0;
}