#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e4+7;
ll p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> p[i];
    }
    sort(p+1,p+n+1);
    for(int i = 1;i <= n;i++) { // a
        for(int j = i+1;j <= n;j++) { // b
            int vtd = p[i] + p[j];
            
        }
    }
    return 0;
}