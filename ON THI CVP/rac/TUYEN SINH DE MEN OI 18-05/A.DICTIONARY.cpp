#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<int,int> d;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "DICTIONARY"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s,t;
    cin >> s >> t;
    for(auto i:s) d[i] = 1;
    int ans = 0;
    for(int i:t) {
        if(d[i] == 1) ans++;
    }
    cout << t.size()-ans;
    return 0;
}