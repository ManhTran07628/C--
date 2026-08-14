#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int a[MM],mp[11];
multiset<int> ms;
void solve() // cach 1 : greedy
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    memset(mp,0,sizeof(mp));
    int fpos = -1;
    bool ok = 0;
    for(int i = n;i > 1;i--) {
        mp[ a[i] ]++;
        if(a[i-1] < a[i]) {
            mp[ a[i-1] ]++;
            fpos = i-1;
            ok = 1;
            break;
        }
    }
    if(!ok) {
        cout << -1 << '\n';
        return;
    }
    int val = -1;
    for(int i = 0;i <= 9;i++) {
        if(mp[i] && i > a[ fpos ]) {
            val = i;
            break;
        }
    }
    a[ fpos ] = val;
    mp[val]--;
    int first = -1;
    for(int i = 0;i <= 9;i++) 
        if(mp[i]) {
            first = i;
            break;
        }
    for(int i = fpos+1;i <= n;i++) {
        if(mp[ first ]) {
            a[i] = first;
            mp[ first ]--;
        }
        while(!mp[ first ] && first <= 9) first++; 
    }
    for(int i = 1;i <= n;i++) cout << a[i];
    cout << '\n';

}
// cach 2 : stack cac ban tu nghi nhe

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "JNEXT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}