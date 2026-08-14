#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int MOD = 1e9 + 7;
ll n,a[MM],Lmax[MM],Lmin[MM],Rmax[MM],Rmin[MM];
ll psmin[MM],psmax[MM];

ll add(ll a,ll b)
{
    return a + b;
}

ll del(ll a,ll b)
{
    return a - b;
}

ll dnc(int L,int R)
{
    if(L == R) return 0;
    
    int mid = (L + R) / 2;
    ll sum = dnc(L,mid) + dnc(mid+1,R);

    Lmax[mid + 1] = -oo;
    Lmin[mid + 1] = oo;
    for(int i = mid;i >= L;i--) {
        Lmax[i] = max(Lmax[i + 1],a[i]);
        Lmin[i] = min(Lmin[i + 1],a[i]);
    }
    
    Rmax[mid] = -oo;
    Rmin[mid] = oo;
    for(int i = mid + 1;i <= R;i++) {
        Rmax[i] = max(Rmax[i - 1],a[i]);
        Rmin[i] = min(Rmin[i - 1],a[i]);
    }

    psmin[L - 1] = psmax[L - 1] = 0;
    for(int i = L;i <= mid;i++) {
        psmin[i] = psmin[i - 1] + Lmin[i];
        psmax[i] = psmax[i - 1] + Lmax[i];
    }

    for(int i = mid, j = mid + 1; j <= R; j++) {
        while(i >= L && Rmax[j] >= Lmax[i]) i--;
        sum += Rmax[j] * (mid - i);
        ll pre = psmax[i] - psmax[L - 1];
        sum += pre;
    }

    for(int i = mid, j = mid + 1; j <= R; j++) {
        while(i >= L && Rmin[j] <= Lmin[i]) i--;
        sum -= Rmin[j] * (mid - i);
        ll pre = psmin[i] - psmin[L - 1];
        sum -= pre;
    }
    return sum;
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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    cout << dnc(1,n);
    return 0;
}