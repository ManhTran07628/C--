#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> tk;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BAI3"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    ll dem = 0;
    for(int i = 0;i < m-4;i++) {
        for(int j = i;j < i+n;j++) {
            tk[b[j]]++;
        }
        bool check = 1;
        for(int j = 0;j < n;j++) {
            if(tk[a[j]] == 0) {
                check = 0;
            }
        }
        if(check == 1) dem++;
        tk.clear();
    }
    cout << dem;
    return 0;
}