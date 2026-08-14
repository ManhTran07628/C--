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
    int x;
    cin >> x;
    int vt = 0;
    while(x > 0) {
        if(x > 0) vt+=3;
        x--;
        if(x > 0) vt-=2;
        x--;
    }
    cout << vt;
    return 0;
}