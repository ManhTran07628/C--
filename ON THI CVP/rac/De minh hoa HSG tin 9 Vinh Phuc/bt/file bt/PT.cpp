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
    ll a,b;
    cin >> a >> b;
    if(a == 0 && b == 0) {
        cout << "VSN";
        return 0;
    }
    if(a == 0 && b != 0) {
        cout << "VN";
        return 0;
    }
    cout << "NDN";
    return 0;
}