#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll f[MAXN];
vector<ll> a;

void backtracking(ll x)
{
    for(int i = 0;i < a.size();i++) {
        
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    f[1] = 1;
    a.push_back(1);
    for(int i = 2;i <= MAXN;i++) {
        f[i] = f[i-1] + f[i-2];
        if(f[i] >= 1e18) break;
        a.push_back(f[i]);
    }

    return 0;
}