#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll f[N];

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
        ll n;
        cin >> n;
        string k;
        cin >> k;
        ll dem = 0;
        for(int i = 0;i < k.size();i++) {
            if(k[i] == '@') dem++;
            else if(k[i] == '*' && k[i+1] == '*') break;
        }
        cout << dem << '\n';

    }
    return 0;
}