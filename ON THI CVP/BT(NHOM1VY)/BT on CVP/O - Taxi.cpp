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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a >= c) {
        cout << a;
        return 0;
    }
    while(1) {
        if(a < c) a += b;
        else break;
        if(a < c) c -= d;
        else break;
    }
    cout << max(a,c);
    return 0;
}