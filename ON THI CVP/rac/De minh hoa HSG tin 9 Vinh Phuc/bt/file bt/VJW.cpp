#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

ll ktra(string k)
{
    ll n = k.size();
    if(k[n-2] == 0 && k[n-1] == 0) return 1;
    if(k[n-2] == 2 && k[n-1] == 5) return 1;
    if(k[n-2] == 5 && k[n-1] == 0) return 1;
    if(k[n-2] == 7 && k[n-1] == 5) return 1;
    return 0;
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
    ll t;
    cin >> t;
    while(t--) {
        string k;
        cin >> k;
        ll so0 = 0,so2 = 0,so5 = 0,so7 = 0;
        ll kt;
        for(int i = k.size()-1;i >= 0;i--) {
            if(k[i] == '0')so0++;
            if(k[i] == '2')so2++;
            if(k[i] == '5')so5++;
            if(k[i] == '7')so7++;
            if(so0 == 2 || (so0 == 1 & so5 == 1) || (so2 == 1 && so5 == 1) || (so7 == 1 && so5 == 1)) {
                kt = i;
                break;
            }
        }
        cout << kt << '\n';
    }
    return 0;   
}