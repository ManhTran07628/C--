#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int p[MAXN],a[MAXN];
vector<ll> v[MAXN];
void min_prime()
{
    for(int i = 2;i*i < MAXN-1;i++)
        if(p[i] == 0)
            for(int j = i;j < MAXN-1;j+=i)
                if(p[j] == 0) p[j] = i;
    for(int i = 2;i < MAXN-1;i++) {
        if(p[i] == 0) p[i] = i;
        v[p[i]].push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    min_prime();
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        int p = upper_bound(v[a[i]].begin(),v[a[i]].end(),k)-v[a[i]].begin();
        cout << p << '\n';
    }
    return 0;
}