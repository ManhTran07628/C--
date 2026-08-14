#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int c[30],v[30],dd[30];
int ans = 0;
int n,m,k;
vector<int> lt[30],vt;


void backtracking(int cost,int val)
{
    if(cost > m) return;
    if(ans < val) {
        int sum = 0;
        for(auto i:vt) {
            cout << i << ' ';
            sum += i;
        } 

        cout << sum << '\n';
        ans = val;
    }
    for(int i = 1;i <= n;i++) {
        if(dd[i] == 0) {
            if(lt[i].size() == 0) {
                dd[i] = 1;
                vt.push_back(v[i]);
                backtracking(cost+c[i],val+v[i]);
                vt.pop_back();
                dd[i] = 0;
            }
            else if(lt[i].size() >= 1){
                int totalcost = 0,totalval = 0;
                for(auto p:lt[i]) {
                    vt.push_back(v[p]);
                    totalcost += c[p];
                    totalval += v[p];
                    dd[p] = 1;
                }
                backtracking(cost+totalcost,val+totalval);
                for(auto p:lt[i])  {
                    vt.pop_back();
                    dd[p] = 0;       
                }
            }
        }
    }
}



void solve()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) 
        cin >> c[i] >> v[i];
    for(int i = 1;i <= k;i++) {
        int a,b;
        cin >> a >> b;
        lt[a].push_back(b);
        lt[b].push_back(a);
    }
    backtracking(0,0);
    cout << ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}