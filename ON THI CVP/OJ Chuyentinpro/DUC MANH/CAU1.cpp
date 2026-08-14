#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,n;
    cin >> a >> n;
    int x = 0,y = 0,t = 1;
    int b = a * 4;
    while(n >= b) n -= b;
    if(n >= 0 && n <= a) {
        x = n;
    }
    else if(n > a && n <= a*2) {
        x = a;
        y = n - a;
    }
    else if(n > a*2 && n <= a*3) {
        y = a;
        x = (n%a);
    }
    else if(n > a*3 && n <= a*4) {
        x = 0;
        y = a-(n%a);
    }
    cout << x << ' ' << y;
    return 0;
}