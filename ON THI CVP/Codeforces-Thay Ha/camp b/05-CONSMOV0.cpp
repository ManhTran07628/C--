#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
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
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1,a+4);
    if(a[2]-a[1] == a[3]-a[2]) {
        cout << 0 << '\n' << 1;
    }
    return 0;
}