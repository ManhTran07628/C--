#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];

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
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    b[1] = a[1];
    cout << b[1] << ' ';
    for(int i = 2;i <= n;i++) {
        ll m = a[i] * i - b[i-1];
        cout << m << ' ';
        b[i] = b[i-1] + m;
    }
    return 0;
}