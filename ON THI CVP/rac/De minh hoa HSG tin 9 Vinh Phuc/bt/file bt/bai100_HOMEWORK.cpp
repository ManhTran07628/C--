#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "HOMEWORK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,s,dem = 0;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        if(s >= a[i]) {
            s+= a[i];
            dem++;
        }
        else 
            break;
    }
    cout << dem;
    return 0;
}