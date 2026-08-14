#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,m,c,t[MM];

bool check(int k)
{
    int used = 1,cur_length = 0,fpos = 1;
    for(int i = 1;i <= n;i++) {
        if(cur_length > c && i == n) {
            fpos = i;
            used++;
            cur_length = 0;
        }
        
        if(cur_length + 1 > c || t[i] - t[fpos] > k) {
            fpos = i;
            cur_length = 0;
            used++;
        }
        else if(cur_length + 1 <= c && t[i] - t[fpos] <= k) cur_length++;
    }
    return used <= m;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> c;
    for(int i = 1;i <= n;i++) cin >> t[i];
    sort(t+1,t+n+1);
    int L = 0,R = 1e9,res = 0;
    // cout << check(4);
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid)) {
            res = mid;
            R = mid - 1;
        }
        else L = mid + 1;
        // cout << mid << '\n';
    }
    cout << res;
    return 0;
}