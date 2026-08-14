#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "replacedigit"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        string n;
        cin >> n;
        for(int i = 0;i < n.size();i++) {
            if(n[i] == '0') {
                n[i] = '5';
            }
        }
        cout << n << '\n';
    }
    return 0;
}