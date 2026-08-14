#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<ll> f;

ll printans()
{
    if(f.empty()) return 0;
    ll i = f.size()-1;
    while(i >= 0 && f[i] == 0) {
        i--;
    }
    if(i < 0) return 0;
    else return f[i];
}

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
    while(n--) {
        ll a;
        cin >> a;
        if(a > 0) {
            f.push_back(a);
        }
        if(a < 0) {
            for(int i = 0;i < f.size();i++) {
                if(f[i] == -a) {
                    f[i] = 0;
                    break;
                }
            }
        }
        if(a == 0) {
            f.pop_back();
            ll ans = 0;
        }
        cout << printans() << ' ';
    }
    
    return 0;
}