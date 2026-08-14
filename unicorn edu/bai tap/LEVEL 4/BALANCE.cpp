#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,ps[MM];
struct coord{int c,x;} a[MM];
map<int,int> pos;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].c >> a[i].x;

    // vector<int> v;
    // for(int i = 1;i <= n;i++)
    //     v.push_back( a[i].x );

    // sort(v.begin(),v.end());
    // for(int i = 1;i <= n;i++)
    //     a[i].compx = lower_bound(v.begin(),v.end(),a[i].se) - v.begin();

    int sum = 0,res = 0;
    sort(a+1,a+n+1,[] (coord i,coord j){
        return i.x < j.x;
    });

    for(int i = 1;i <= n;i++) {
        ps[i] = ps[i-1] + (a[i].c == 1 ? 1 : -1);
        // cout << ps[i] << ' ';
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            if(ps[i] - ps[j-1] == 0) {
                res = max(res,a[i].x - a[j].x);
            }
        }
    }
    cout << res;

    // pos[0] = 0;
    // for(int i = 1;i <= n;i++) {
    //     sum += (a[i].c == 1 ? 1 : -1);
    //     if(!pos.count(sum)) pos[sum] = i+1;
    //     else {
    //         res = max(res,a[i].x - a[ pos[sum] ].x);
    //         // cout << pos[sum] << ' ' << a[i].x << '\n';
    //     }
    //     // cout << sum << ' ';
    // }
    // cout << res;

    return 0;
}