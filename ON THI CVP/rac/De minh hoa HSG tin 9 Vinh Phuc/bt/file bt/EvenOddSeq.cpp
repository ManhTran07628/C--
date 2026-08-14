#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
vector<ll> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "EvenOddSeq"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        for(int i = 1;i <= n;i++) {
            if(a[i]%2==0) f.push_back(a[i]);
        }
        for(int i = 1;i <= n;i++) {
            if(a[i]%2!=0) f.push_back(a[i]);
        }
        for(auto c:f) {
            cout << c << " ";
        }
        cout << '\n';
        f.clear();
    }
    return 0;
}
