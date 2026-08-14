#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
set<int> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    vector<int> f(a.begin(),a.end());
    reverse(f.begin(),f.end());
    for(int i:f) cout << i << ' ';
    return 0;
}