#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N];
struct dl
{
    int l,r,x,p,c;
} tv[N];

bool cmp1(dl a,dl b)
{
    return a.r < b.r;
}
bool cmp2(dl a,dl b)
{
    return a.p < b.p;
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
    ll n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= q;i++) {
        ll l1,r1,x1;
        cin >> l1 >> r1 >> x1;
        tv[i].l = l1;
        tv[i].r = r1;
        tv[i].x = x1;
        tv[i].p = i;
    }
    sort(tv+1,tv+q+1,cmp1);
    for(int i = 1,j = 1;i <= q;i++) {
        while(j <= tv[i].r) {
            l[a[j]] = j;
            j++;
        }
        ll t = tv[i].x;
        tv[i].c = 0;
        for(int k = 1;k*k <= t;k++) {
            if(t % k == 0) {
                ll a1 = k;
                ll b = t / k;
                if(a1 != b && l[a1] >= tv[i].l && l[b] <= tv[i].r && l[a1] <= tv[i].r && l[b] >= tv[i].l) {
                    tv[i].c = 1;
                    break;
                }
            }
        }
    }
    sort(tv+1,tv+q+1,cmp2);
    for(int i = 1;i <= q;i++) {
        if(tv[i].c) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}