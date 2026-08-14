#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],prime_freq[MAXN],n;
bool prime[MAXN];
vector<int> primes;
vector<int> freq[MAXN];
map<int,int> prime_cnt;
void sieve()
{
    for(int i = 2;i < MAXN;i++) prime[i] = 1;
    for(int i = 2;i*i < MAXN;i++)
        if(prime[i])
            for(int j = i*i;j < MAXN;j+=i)
                prime[j] = 0;
    for(int i = 2;i < MAXN;i++)
        if(prime[i])
            primes.push_back(i); 
}

void factorize(int k)
{
    for(auto p:primes) {
        if(p > k) break;
        int cnt = 0;
        if(k % p == 0) {
            while(k % p == 0) {
                cnt++;
                k /= p;
            }
            prime_freq[p]++; // dem tan so xuat hien tsnt p trong mang a[]
            prime_cnt[p] += cnt; // dem so luong cac tsnt p trong mang a[]
        }
        freq[p].push_back(cnt); // phan tich tsnt k thanh cac snt

    }
}

void build()
{
    sieve();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        factorize(a[i]);
    }
    for(auto [p,cnt]:prime_cnt) {
        for(int i = 0;i < n;i++) freq[p].push_back(0);
    }
}

void solve()
{
    build();
    int ans = 1,steps = 0;
    for(auto [p,cnt]:prime_cnt) {
        if(cnt < n) continue;
        int max_p = cnt/n;
        for(int i = 0;i < n;i++)
            if(freq[p][i] < max_p) steps += max_p-freq[p][i];
        int d = pow(p,max_p);
        ans *= d;
    }
    cout << ans << ' ' << steps << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}