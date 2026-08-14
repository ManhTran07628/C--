#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
set<ll> a;
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
    ll A,B,n;
    cin >> A >> B >> n;
    for(int i = 0;A*i <= n;i++) {
        for(int j = 1;j*B + i*A <= n;j++) {
            a.insert(j*B + i*A);
        }
        if(i != 0)
            a.insert(i*A);
    }
    for(auto c : a)
        cout << c << "\n";
    return 0;
}