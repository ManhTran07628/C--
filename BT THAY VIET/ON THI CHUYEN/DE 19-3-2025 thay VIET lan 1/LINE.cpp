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
    int k,n;
    cin >> k >> n;
    int sotrang = (n/k);
    int dong = n - (sotrang*k);
    if(dong == 0) dong = k;
    if(n % k != 0) sotrang++;
    cout << sotrang << ' ' << dong;
    return 0;
}