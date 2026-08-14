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
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll a1,b,c,d;
        cin >> a1 >> b >> c >> d; 
        if(c % a1 == 0 && c % b != 0) {
            if(d % b == 0) 
                cout << "YES" << '\n';
            else 
                cout << "NO" << '\n';
        }
        else if(c % b == 0 && c % a1 != 0) {
            if(d % a1 == 0) 
                cout << "YES" << '\n';
            else 
                cout << "NO" << '\n';
        }
        else if(c % b == 0 && c % a1 == 0) {
            if(d % b == 0 || d % a1 == 0) 
                cout << "YES" << '\n';
            else 
                cout << "NO" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}