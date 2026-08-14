#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll p[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[n+i] = a[i];
    }
    
    return 0;
}