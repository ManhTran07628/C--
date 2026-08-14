#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
map<ll,ll> b;
vector<ll> f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(b[a[i]] == 0) {
            f.push_back(a[i]);
            b[a[i]]++;
        }
    }
    sort(f.begin(),f.end());
    if (f.size() > 3) cout << "NO";
    else if(f.size() == 1) cout << "YES";
    else if(f.size() == 2) {
        if((f[0] + f[1]) % 2 == 0) cout << "YES"; 
        else cout << "NO";
    }
    else if(f[2] - f[1] == f[1] - f[0]) cout << "YES"; 
    else cout << "NO";
    return 0;
}