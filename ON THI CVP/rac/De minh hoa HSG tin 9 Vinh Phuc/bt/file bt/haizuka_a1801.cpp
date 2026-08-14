#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],trai[N],phai[N],b[N];
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
    ll n;
    cin >> n;
    if(n == 1 || n == 2 || n == 3) {
        cout << "Hai";
        return 0;
    }
    if(n % 2 == 0 && n % 3 != 0) {
        cout << "Linh";
        return 0;
    }
    cout << "Hai";
    return 0;
}



