#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
int n,k,a[MM];

int max_length(int val,int k)
{
    int ans = 0;
    for(int l = 1,r = 1;r <= n;r++) {
        if(a[r] != val) {
            while(!k) {
                if(a[l] != val) k++;
                l++;
            }
            k--;
        }
        ans = max(ans,r-l+1);
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0;i < 30;i++) {
        ans = max(ans,max_length(i,k));
    }
    cout << ans;
    return 0;
}