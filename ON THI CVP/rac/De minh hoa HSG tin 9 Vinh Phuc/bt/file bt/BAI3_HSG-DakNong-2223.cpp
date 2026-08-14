#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
map<char,ll> nguyento = {{'H', 1},{'O',16},{'N',14},{'C',12}};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PHANTU"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string k;
    cin >> k;
    ll tong = 0;
    for(int i = 0;i < k.size();i++) {
        if(!isdigit(k[i])) {
            ll ans = nguyento[k[i]];
            ll demso = 0;
            if(!isdigit(k[i+1])) {
                tong += ans;
                continue;
            }
            i++;
            while(isdigit(k[i]) && i < k.size()) {
                demso = demso * 10 + (k[i]-'0');
                i++;
            }
            i--;
            tong += ans * demso;
        }
    }
    cout << tong;
    return 0;
}