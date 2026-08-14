#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    string n; /// 102 -> 210
    cin >> n;
    sort(n.begin(),n.end(),greater<char>());
    ll n1 = stoll(n);
    if(n1 % 30 == 0) cout << n1;
    else cout << -1;
    return 0;
}
