#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
ll a[MAXN];
map<ll,ll> s;
vector<ll> f,v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(s[a[i]] == 0) {
            v.push_back(a[i]);
            s[a[i]]++;
        }
    }
    sort(v.begin(),v.end());
    if(v.size() < 2) {
        cout << 0;
        return 0;
    }
    cout << v[v.size()-2] << '\n';
    for(int i = 1;i <= n;i++) {
        if(a[i] == v[v.size()-2]) cout << i << ' ';
    }
    return 0;
}