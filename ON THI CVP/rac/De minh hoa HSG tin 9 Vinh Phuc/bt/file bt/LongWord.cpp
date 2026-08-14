#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "LongWord"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
        if(n.size() <= 10) {
            cout << n << '\n';
            continue;
        }
        cout << n[0] << n.size()-2 << n[n.size()-1] << '\n';
    }
    return 0;
}