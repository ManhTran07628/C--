#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e6 + 7;
const int MS = 31700 + 7;
int n,a[MM],prime[MS],nums[MM],cntdiv[MM],ans[MM],ok[MM];
map<int,int> mp[MM];
vector<int> primes; 

void sieve()
{
    for(int i = 2;i < MS;i++) prime[i] = 1;
    for(ll i = 2;i * i < MS;i++)
        if(prime[i]) 
            for(ll j = i * i;j < MS;j += i)
                prime[j] = 0;

    for(int i = 2;i < MS;i++)
        if(prime[i])
            primes.push_back(i);

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cin >> n;

    int L = oo,R = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        L = min(L,a[i]);
        R = max(R,a[i]);
    }

    for(int i = 1;i <= n;i++) {
        ok[ a[i] - L ] = 1;
    }

    for(int i = L;i <= R;i++)
        nums[i - L] = i;

    int len = (R - L + 1);

    for(auto p:primes) {
        ll l = (L + p - 1) / p * p;
        for(ll j = l;j <= R;j += p) {
            if(!ok[j - L]) continue;
            while(nums[j - L] % p == 0) {
                mp[j - L][p]++;
                nums[j - L] /= p;
            }

        }
    }

    for(int i = L;i <= R;i++)
        if(nums[i - L] > 1) 
            mp[i - L][ nums[i - L] ]++;

    for(int i = 1;i <= n;i++) {
        ll res = 1;
        for(auto p: mp[a[i] - L]) res *= (p.se + 1);
        cntdiv[i] = res;
    }
    memset(ans,-1,sizeof(ans));
    stack<int> st;
    a[n + 1] = oo;
    st.push(n+1);
    for(int i = n;i >= 1;i--) {
        while(!st.empty() && cntdiv[ st.top() ] <= cntdiv[i]) st.pop();
        if(!st.empty() && st.top() != oo) ans[i] = a[st.top()];
        st.push(i);
    }
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';

    return 0;
}