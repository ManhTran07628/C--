#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdou   t);
    }
    string k;
    cin >> k;
    while(k.size()>0) {
        ll tmp = k[k.size()-1]-'0';
        if(tmp == 0 || tmp == 5) {
            cout << k;
            return 0;
        }
        k.erase(k.size()-1);
    }
    cout << -1;
    return 0;
}