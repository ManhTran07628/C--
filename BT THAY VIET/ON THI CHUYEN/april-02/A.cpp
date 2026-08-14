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
    vector<char> a;
    for(char i = 'a';i <= 'z';i++) {
        a.push_back(i);
    }
    ll d,m,w,i,j,k;
    cin >> d >> m >> w >> i >> j >> k;
    ll days = ((k-1)*m*d+i+(j-1)*d-1);
    // cout << days;
    cout << a[days%w];
    return 0;
}