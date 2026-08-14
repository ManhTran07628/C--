#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,m,point[MM];
struct dl{int team; string type;} qr[MM];
map<string,int> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> qr[i].team >> qr[i].type;
    }
    for(int i = m;i >= 1;i--) {
        if(!mp[ qr[i].type ]) {
            point[ qr[i].team ]++;
            mp[ qr[i].type ] = 1;  
        }
    }
    for(int i = 1;i <= n;i++) cout << point[i] << ' ';
    return 0;
}