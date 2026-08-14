#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int cntdivs[MAXN];
bool prime[MAXN];
vector<int> primes;
void sieve()
{
    for(int i = 2;i < MAXN;i++)
        prime[i] = 1;
    for(int i = 2;i*i < MAXN;i++)
        if(prime[i])
            for(int j = i*i;j < MAXN;j+=i)
                prime[j] = 0;
    for(int i = 2;i < MAXN;i++) 
        if(prime[i])
            primes.push_back(i);
}

// void sanguoc()
// {
//     for(int i = 1;i < MAXN;i++)
//         for(int j = i;j < MAXN;j+=i)
//             cntdivs[j]++;
// }

// int brute_force(int l,int r)
// {
//     int cnt = 0;
//     for(int i = l;i <= r;i++) 
//         if(prime[cntdivs[i]] && !prime[i]) cnt++;
//     return cnt;
// }

int answer(int l,int r) {
    int ans = 0;
    for(auto p:primes) {
        for(int i = 2;i <= 39;i++) {
            int powx = pow(p,i);
            if(powx > r) break;
            if(l <= powx && powx <= r && prime[i+1]) ans++; 
        }
    }
    return ans;
}

// void codecheck()
// {
//     int t;
//     cin >> t;
//     while(t--) {
//         int l = rand()%10000+11000;
//         int r = rand()%100000+100000;
//         if(brute_force(l,r) == answer(l,r)) cout << "YES";
//         else {
//             cout << "NO" << ' ' << l << ' ' << r << '\n';
//             cout << brute_force(l,r) << ' ' << answer(l,r) << '\n';
//         }
//         cout << '\n';
//     }
// }


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // srand(time(0));
    // sanguoc();
    sieve();
    solve();
    return 0;
}
