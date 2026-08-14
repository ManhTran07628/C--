#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    int ans = 1;
    for(int x = 1;x <= sqrt(n);x++) {
        if(n % x == 0) {
            int y = n / x;
            ans = max(ans,2*(x+y));
        } 
    }
    cout << ans;
    return 0;
}