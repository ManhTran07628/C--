#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
char a[MAXN];
map<char,int> b;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    int ans = max({b['N'],b['S'],b['W'],b['E']});
    cout << n - ans;
    return 0;
}