#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
map<int,int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0,i = 1,j = 1;
    while(i <= n && j <= n) {
        v[a[j]]++;
        while(v[a[j]] == 3) {
            v[a[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    cout << ans;
    return 0;
}