#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int bom[MAXN],cuoi[MAXN],dem[MAXN];
int n,m = 1;
void build()
{
    for(int i = 1;i <= n*2;i++) {
        if(dem[i] == 0) {
            cuoi[m] = i;
            m++;
        }
    }
    sort(bom+1,bom+n+1,greater<int>());
    sort(cuoi+1,cuoi+n+1,greater<int>());
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> bom[i];
        dem[bom[i]]++;
    }
    build();

    int i = 1,j = 1,ans = 0;
    while(i <= n && j <= n) {
        if(bom[i] > cuoi[j]) {
            ans++;
            i++;
            j++;
        }
        else if(bom[i] < cuoi[j]) j++;
    }
    cout << ans;
    return 0;
}