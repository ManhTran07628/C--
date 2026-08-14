#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int prime[MAXN];
vector<int> v;
void sieve()
{
    fill(prime+1,prime+MAXN+1,1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i*i < MAXN-1;i++)   
        if(prime[i])
            for(int j = i*2;j < MAXN-1;j+=i)
                prime[j] = 0;
    for(int i = 2;i < MAXN-1;i++) if(prime[i]) v.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    int ans = 1;
    while(n--) {
        int a;
        cin >> a;
        int uocso = 1;
        for(auto id:v) {
            if(a < id) break;
            int cnt = 0;
            while(a % id == 0) {
                cnt++;
                a /= id;
            }
            uocso *= (cnt+1);
        }
        if(a > 1) uocso*=2;
        ans = max(ans,uocso);
    }
    cout << ans;
    return 0;
}