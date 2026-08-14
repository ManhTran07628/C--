#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int p[MAXN];
void sieve()
{
    fill(p+1,p+MAXN,1);
    p[0] = p[1] = 0;
    for(int i = 2;i*i < MAXN;i++)
        if(p[i])
            for(int j = i*2;j < MAXN;j+=i)
                p[j] = 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    while(n--) {
        ll x;
        cin >> x;
        ll s = sqrt(x);
        if(s * s == x && p[s]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}