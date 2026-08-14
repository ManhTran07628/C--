#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


void codecheck()
{
    srand(time(NULL));
    int nn = 1000;
    int l = 2000,r = 5000;
    while(nn--) {
        int x = rand()%(r-l+1)+l;
        int y = rand()%(l-5)+1;
        int a = rand()%(l-1000)+1;
        
        int cost2 = 10*n/(x*9+y);
        if(cost2 == a) cout << 1;
        else cout << 0;
        // cout << cost2 << ' ' << a << '\n';
        cout << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    codecheck();
    int n = (a-a/10)*x+(a/10)*y;
    return 0;
}