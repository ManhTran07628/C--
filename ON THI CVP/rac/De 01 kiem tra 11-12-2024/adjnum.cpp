#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a,b;
ll solve()
{
    if(a == 1 && (b == 2)) return 1;
    if(a == 2 && (b == 1 || b == 3)) return 1;
    if(a == 3 && (b == 2)) return 1;
    if(a == 4 && (b == 5)) return 1;
    if(a == 5 && (b == 4 || b == 6)) return 1;
    if(a == 6 && (b == 5)) return 1;
    if(a == 7 && (b == 8)) return 1;
    if(a == 8 && (b == 7 || b == 9)) return 1;
    if(a == 9 && (b == 8)) return 1;
    return 0;
}
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
    cin >> a >> b;
    if(solve() == 1) cout << "Yes";
    else cout << "No";
    return 0;
}