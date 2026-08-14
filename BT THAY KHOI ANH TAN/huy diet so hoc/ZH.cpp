#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 2e7+7;
ll p[MAXN];
vector<ll> v;
map<ll,int> lt;
void sieve() {
    fill(p+1,p+MAXN+1,1);
    p[0] = p[1] = 0;
    for(int i = 2;i*i < MAXN-1;i++) 
        if(p[i])
            for(int j = i*2;j < MAXN-1;j+=i)
                p[j] = 0;
    for(int i = 2;i < MAXN-1;i++) if(p[i]) v.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    for(int i = 1;i < v.size();i++) {
        ll p = v[i-1]+v[i+1];
        if(p%2==0 && p/2 == v[i]) lt[v[i]] = 1;
    }
    ll q;
    cin >> q;
    while(q--) {
        ll n;
        cin >> n;
        if(lt[n]!=0) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}