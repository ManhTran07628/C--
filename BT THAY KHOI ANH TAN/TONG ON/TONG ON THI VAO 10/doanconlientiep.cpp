#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],ps[MAXN];
map<int,int> counts;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,S;
    cin >> n >> k >> S;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }        
    counts[0] = 1;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += counts[ps[i]-S];
        counts[ps[i]]++;
        if(i >= k) counts[ps[i-k]]--;
    }
    cout << ans;
    return 0;
}


// Tìm đoạn con liên tiếp có độ dài <=K có tổng =S,chia hết cho S