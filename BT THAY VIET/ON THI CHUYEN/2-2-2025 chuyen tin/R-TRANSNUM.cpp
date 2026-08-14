#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    int x,n,cnt = 0;
    cin >> x >> n;
    while(1) {
        cnt++;
        int r = x % 3;
        if(r == 0) x = x+1;
        if(r == 1) x = x*2;
        if(r == 2) x = x*3;
        if(x >= n) break;
    }
    cout << cnt;
    return 0;
}