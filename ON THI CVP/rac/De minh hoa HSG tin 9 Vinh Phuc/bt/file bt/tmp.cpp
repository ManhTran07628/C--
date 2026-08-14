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
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    srand(time(NULL));
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        ll a = rand();
        cout << a << ' ';
    }
    for(int i = 1;i <= m;i++) {
        ll a = rand();
        cout << a << ' ';
    }
    return 0;
}