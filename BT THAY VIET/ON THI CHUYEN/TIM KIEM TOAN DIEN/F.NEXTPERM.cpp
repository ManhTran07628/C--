#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    m--;
    while(next_permutation(a+1,a+n+1)) {
        if(m == 0) {
            for(int i = 1;i <= n;i++) cout << a[i] << ' ';
            return 0;
        }
        m--;
    }
    return 0;
}