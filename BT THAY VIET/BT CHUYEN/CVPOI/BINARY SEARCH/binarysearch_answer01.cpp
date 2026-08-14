#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e4+7;
int n,t,d[MM];

bool check(int k)
{
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 1;i <= k;i++) q.push(d[i]); // tg ket thuc

    int i = k+1;
    for(int j = 1;j <= t;j++) {
        while(!q.empty() && q.top() <= j) {
            q.pop();
        }
        while(i <= n && q.size() + 1 <= k) {
            q.push(d[i] + j);
            i++;
        }
        // if(i > n) return 1;
    }
    while(!q.empty()) {
        if(q.top() <= t) q.pop();
        else return 0;
    }
    if(i > n) return 1;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 1;i <= n;i++) cin >> d[i];
    int L = 1,R = n,ans = n;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid)) {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << ans;
    return 0;
}