#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

vector<char> a{'R','B','W'};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "COLORS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll x = 0;
    while(1) {
        if((x * (x+1) / 2) <= n && n <= ((x+2) * (x+1) / 2)) {
            break;
        }
        x++;
    }
    cout << a[x%3];
    return 0;
}