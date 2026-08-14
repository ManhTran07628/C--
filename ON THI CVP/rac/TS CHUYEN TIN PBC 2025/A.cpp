#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
const int Ns = 1e6+5;
int mp[MAXN],ps[MAXN];

void min_prime()
{
    for(int i = 2;i*i < Ns;i++)
        if(mp[i] == 0)
            for(int j = i;j < Ns;j+=i)
                if(mp[j] == 0) mp[j] = i;

    for(int i = 2;i < Ns;i++) if(mp[i] == 0) mp[i] = i;
}

bool check(int k)
{
    int cnt = 0,divisors = 1,pre = mp[k];
    while(k > 1) {
        if(pre != mp[k]) {
            // if(cnt >= 3) return 0;
            divisors *= (cnt+1);
            cnt = 0;
            pre = mp[k];
        }
        k /= mp[k];
        cnt++;
    }
    // if(cnt >= 3) return 0;
    divisors *= (cnt+1);
    if(divisors == 4) return 1;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    min_prime();
    for(int i = 1;i < MAXN-5;i++) {
        if(check(i)) {
            ps[i]++;
        }
        ps[i] += ps[i-1];
    }
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        cout << ps[b]-ps[a-1] << '\n';
    }
    return 0;
}