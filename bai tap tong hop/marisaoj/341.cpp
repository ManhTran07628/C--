#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    vector<int> f;
    for(int i = 1;i <= n;i++) {
        int p = lower_bound(f.begin(),f.end(),a[i]) - f.begin();
        if(p == f.size()) f.push_back(a[i]);
        else f[p] = a[i];
    }
    cout << f.size();
    return 0;
}