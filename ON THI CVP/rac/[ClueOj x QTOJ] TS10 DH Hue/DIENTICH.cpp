#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double a,b;
    cin >> a >> b;
    double maxans = 0,minans = 1e9,max_x = 0,min_x = 0;  
    for(int x = 0;x <= b;x++) {
        double cm = b-x;
        double dn = a-x;
        double S = a*b-a*x/2-cm*x/2-b*dn/2;
        if(S > maxans) {
            maxans = S;
            max_x = x;
        }
        if(S < minans) {
            minans = S;
            min_x = x;
        }
    }
    cout  << maxans << '\n' << max_x << '\n' << minans << '\n' << min_x;
    return 0;
}