#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],low[MAXN],high[MAXN];
map<int,int> dem;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n,B;
    cin >> n >> B;
    int pos = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] == B) pos = i;
    }
    
    return 0;
}
