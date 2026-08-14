#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int prime[MAXN];

void sieve()
{
    for(int i = 2;i < MAXN;i++) prime[i] = 1;
    for(int i = 2;i*i < MAXN;i++)
        if(prime[i])
            for(int j = i*i;j < MAXN;j+=i)
                prime[j] = 0;
}

bool check(int k)
{
    int sqrtk = sqrt(k);
    if(prime[sqrtk] && sqrtk*sqrtk == k) return 1;
    return 0;
}

void solve()
{
    int x;
    cin >> x;
    if(check(x)) cout << "YES";
    else cout << "NO";
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    while(n--) {
        solve();
    }
    return 0;
}