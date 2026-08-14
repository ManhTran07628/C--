#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
int main()
{
    ll a,b,x,y;
    cin >> a >> b >> x >> y;
    ll sshx = (b-a)/x + 1;
    ll sshy = (b-a)/y + 1;
    cout << sshx + sshy;
    return 0;
}
