#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e4+7;
int a[MAXN];
map<int,int> dem;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        dem[a[i]]++;
    }
    for(int i = 0;i*i <= 1e9;i++) {
        if(dem[i*i] == 0) {
            cout <<i*i;
            return 0;
        }
    }
    return 0;
}