#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
vector<int> p;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,v;
    cin >> n;
    int m1 = -1,m2 = -1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    cin >> v;
    for(int i = 1;i <= n;i++) {
        if(m1 == -1 && a[i] == v) m1 = i-1;
    }
    for(int i = n;i >= 1;i--) {
        if(m2 == -1 && a[i] > v) m2 = i-1;
    }
    for(int i = 1;i <= n;i++) {
        if(a[i] < v) p.push_back(i-1);
    }
    cout << m1 << '\n' << m2 << '\n';
    for(auto i:p) cout << i << ' ';
    return 0;
}