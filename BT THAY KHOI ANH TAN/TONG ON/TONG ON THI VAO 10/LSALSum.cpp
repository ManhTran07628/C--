#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int ps[MAXN],a[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int pos_l = 1,pos_r = 1;
    int pos_min = 0,ans = LLONG_MIN;
    int Smax = 0;


    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1]+a[i];
        if(ps[i]-ps[pos_min]>ans) {
            ans = ps[i]-ps[pos_min];
            pos_l = pos_min;
            pos_r = i;
        }
        else if(ps[i]-ps[pos_min] == ans) 
            if(i-pos_min > pos_r-pos_l) {
                pos_l = pos_min;
                pos_r = i;
            }
        if(ps[i]<ps[pos_min]) {
            pos_min = i;
        }
        Smax = max(Smax,pos_r-pos_l);
    }
    cout << pos_l+1 << ' ' << pos_r << ' ' << ans;
    return 0;
}

// bai toan tim doan con co tong lon nhat va dai nhat
// longest sum and longest subsequences