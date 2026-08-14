#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e8+7;
bool p[MAXN];
vector<ll> v;
void prime()
{
    for(int i = 2;i < MAXN;i++) p[i] = 1;
    for(int i = 2;i*i < MAXN;i++) 
        if(p[i])
            for(int j = i*2;j < MAXN;j+=i)
                p[j] = 0;
    for(int i = 2;i < MAXN;i++) if(p[i]) v.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime();
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll n1 = n,sum = 1;
        for(ll i:v) {
            if(n == 1 || i*i > n) break;
            ll id = 0;
            int cnt = 1;
            if(n % i == 0) {
                while(n%i==0) {
                    n /= i;
                    id++;
                    cnt += pow(i,id);
                }
                if(cnt != 0) sum *= cnt;
            }
        }
        if(n > 1) {
            sum *= (1+n);
        }
        cout << sum - n1 << '\n';
    }
    return 0;
}