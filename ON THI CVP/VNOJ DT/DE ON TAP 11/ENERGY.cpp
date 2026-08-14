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
    ll n;
    cin >> n;
    bitset<50> a(n);
    int cnt = 0;
    for(int i = 0;i < a.size();i++) {
        if(a[i] == 1) cnt++;
    }
    cout << cnt;
    return 0;
}