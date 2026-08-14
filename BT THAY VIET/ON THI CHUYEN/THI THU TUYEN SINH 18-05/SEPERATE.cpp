#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN];
int n,ans = 1e18;
unordered_map<int,int> dem;
void recursion(int id,int cnt,int m)
{
    if(cnt == m) {
        int sum = 0,lt = 0,sumM = 0;
        for(int i = 1;i <= n;i++) {
            if(dem[i] == 0)  {  
                sum += a[i];
                lt = max(lt,sum);
            }
            else {
                sum = 0;
                sumM += a[i];
            }
        }
        ans = min(ans,max(sumM,lt));
        return;
    }
    for(int i = id+1;i <= n;i++) {
        if(id <= n && cnt+1 <= m) {
            dem[i] = 1;
            recursion(i,cnt+1,m);
            dem[i] = 0;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        recursion(0,0,i);
    }
    cout << ans;
    return 0;
}