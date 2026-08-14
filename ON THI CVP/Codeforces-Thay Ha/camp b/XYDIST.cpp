#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a;
vector<int> b,c;
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
    int n,x,y;
    cin >> n >> x >> y;
    for(int i = 1;i <= n;i++) {
        cin >> a;
        if(a == x) b.push_back(i);
        if(a == y) c.push_back(i);
    }
    int ans = n;
    for(int x:b) {
        int pos = lower_bound(c.begin(),c.end(),x) - c.begin();
        if(pos-1 >= 0)
            ans = min(ans,x-c[pos-1]);
    }
    cout << ans;
    return 0;
}