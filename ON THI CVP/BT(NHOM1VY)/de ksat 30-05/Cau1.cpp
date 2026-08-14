#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
const int N = 1e6+1;
int prime[MAXN];
set<int> s;
void sieve()
{
    fill(prime+1,prime+N,1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i*i < N-1;i++)
        if(prime[i])
            for(int j = i*i;j < N-1;j+=i)
                prime[j] = 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    int sum = 0;
    for(auto i:s) {
        if(prime[i]) sum += i;
    }
    cout << sum;
    return 0;
}