#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
set<ll> a;
map<ll,ll> b;
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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        a.insert(a1);
        b[a1]++;
    }
    for(auto c:a) {
        cout << "Dau sach " << c << ": " << b[c] << " luot" << '\n';
    }
    return 0;
}