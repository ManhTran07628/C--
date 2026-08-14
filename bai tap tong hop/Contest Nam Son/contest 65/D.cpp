#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

void solve()
{
    ll l,r,n;
    cin >> l >> r >> n;
    int demso = 0;
    for(int i = 2;i <= n;i++) {
        demso += (r-l)/i+1;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}