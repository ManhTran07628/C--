#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
map<char,int> mp;

bool isprime(int k)
{
    if(k < 2) return 0;
    for(int i = 2;i * i <= k;i++)
        if(k % i == 0) return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(int c:s) mp[c]++;
    int maxn = 0,minn = s.size();
    for(auto c:mp) {
        maxn = max(maxn,c.se);
        minn = min(minn,c.se);
    }
    if(isprime(maxn - minn)) cout << "Lucky Word" << '\n' << maxn - minn;
    else cout << "No Answer" << '\n' << 0;
    return 0;   
}