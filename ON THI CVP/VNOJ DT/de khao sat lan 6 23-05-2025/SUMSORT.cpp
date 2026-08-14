#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN],b[MAXN],c[MAXN],counts[MAXN];
vector<int> d;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    for(int i = 1;i <= x;i++) cin >> a[i];
    for(int i = 1;i <= y;i++) cin >> b[i];
    for(int i = 1;i <= z;i++) cin >> c[i];
    for(int i = 1;i <= x;i++) {
        for(int j = 1;j <= y;j++) {
            d.push_back(a[i]+b[j]);
        }
    }
    sort(d.begin(),d.end(),greater<int>());
    sort(c+1,c+z+1,greater<int>());
    while(k--) {
        int posc = 1;
        while(counts[posc] >= d.size()) posc++;
        if(posc > z) break;
        for(int i = posc;i <= z;i++) {
            if(counts[i] < d.size() && c[i]+d[counts[i]] > c[posc]+d[counts[posc]]) 
                posc = i;
        }
        cout << c[posc]+d[counts[posc]] << ' ';
        counts[posc]++;
    }
    return 0;
}