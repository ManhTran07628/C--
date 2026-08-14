#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];
multiset<int> ms;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1,j = 1;j <= n;j++) {
        ms.insert(a[j]);
        while(!ms.empty() && *ms.rbegin() - *ms.begin() > k) {
            ms.erase(ms.find(a[i]));
            i++;
        }
        int x = ms.size();
        ans = max(ans,x);
    }
    cout << ans;
    return 0;
}