#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],p[MAXN];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        cin >> a[i];
        p[a[i]]++;
    }
    for(int i = 1;i <= n;i++) p[i] += p[i-1]; 
    int ans = k;
    for(int i = k;i<= n;i++) {
        ans = min(ans,k-(p[i]-p[i-k]));
    }
    cout << ans;
    return 0;
}