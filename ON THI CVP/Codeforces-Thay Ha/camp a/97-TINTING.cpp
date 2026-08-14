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
    int n;
    int max1 = 1,min1 = 1e9;
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        max1 = max(max1,x);
        min1 = min(min1,x);
    }
    cout << max1-min1+1;
    return 0;
}