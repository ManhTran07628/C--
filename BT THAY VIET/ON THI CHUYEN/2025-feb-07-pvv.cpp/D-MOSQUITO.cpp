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
    int x1 = 1e6,y1 = 1e6,x2 = 0,y2 = 0;
    for(int i = 1;i <= n;i++) {
        int x,y;
        cin >> x >> y;
        x1 = min(x1,x);
        y1 = min(y1,y);
        x2 = max(x2,x);
        y2 = max(y2,y);
    }
    int ans = max(y2-y1,x2-x1);
    cout << ans * ans;
    return 0;
}