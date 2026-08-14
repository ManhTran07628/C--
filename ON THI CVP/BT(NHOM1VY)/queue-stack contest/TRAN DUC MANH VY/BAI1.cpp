#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
map<int,int> d;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        if(d[a[i]] == 0) {
            d[a[i]] = i+k;
            continue;
        }
        if(d[a[i]] != 0 && d[a[i]] <= i) {
            d[a[i]] = i+k;
        }        
        else {
            cout << d[a[i]]-k;
            return 0;
        }
    }
    cout << -1;
    return 0;
}