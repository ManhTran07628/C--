#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "power"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i = 1;i <= n;i++) {
        if(a[i] < b[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}