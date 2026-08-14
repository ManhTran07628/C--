#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,t,a,b,k[MM];

priority_queue<int,vector<int>,greater<int>> q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t >> a >> b;
    for(int i = 1;i <= n;i++) {
        cin >> k[i];
    }
    int sum = 0,ans = 0;
    for(int i = 1;i <= n;i++) {
        if(t >= a) {
            t -= a;
            q.push(k[i]);
            sum += k[i];
        }
        else {
            if(q.empty()) break;
            if(k[i] > q.top()) {
                while(!q.empty() && t < a) {
                    t = t - b + a;
                    sum -= q.top();
                    q.pop();
                }
                if(t < a) break;
                t -= a;
                sum += k[i];
                q.push(k[i]); 
            }
            else {
                while(!q.empty() && t < b) {
                    t = t - b + a;
                    sum -= q.top();
                    q.pop();
                }
                if(t < b) break;
                t -= b;
            }
        }
        ans = max(ans,sum);
    }
    cout << ans;
    return 0;
}