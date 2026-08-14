#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

int solve(int k)
{
    int ans = 0;
    while(k > 0) {
        int tmp = k % 10;
        ans += tmp * tmp;
        k /= 10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int x,v,n;
    cin >> x >> v >> n;
    cout << x << ' ';
    for(int i = 2;i <= 30;i++) {
        int m = solve(x);
        x = m;
        cout << x << ' ';
    }
    return 0;
}