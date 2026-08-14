#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e3+7;
map<int,int> X,Y;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1;i <= 3;i++) {
        int x,y;
        cin >> x >> y;
        X[x]++;
        Y[y]++;
    }
    int dx = -1,dy = -1;
    for(auto x:X) 
        if(x.se == 1) 
            dx = x.fi;
    
    for(auto y:Y) 
        if(y.se == 1) 
            dy = y.fi;
        
    cout << dx << ' ' << dy;
    

    return 0;
}