#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ltbn"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll max1 = 1,count = 1;
    for(int i = 2;i <= n;i++) {
        if(a[i] == a[i-1]) count++;
        else {
            max1 = max(max1,count);
            count = 1;
        }
    }
    max1 = max(max1,count);
    cout << max1;
    return 0;
}