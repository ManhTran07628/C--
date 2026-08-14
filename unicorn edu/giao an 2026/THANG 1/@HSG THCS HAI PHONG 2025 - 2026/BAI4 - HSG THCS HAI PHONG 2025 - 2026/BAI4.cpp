#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll a[MM],L[MM],best[MM],R[MM],pre[MM],suf[MM];
ll n,k;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0;i < n;++i) {
        cin >> a[i];
    }
    sort(a,a + n);
    int left = 0;
    for(int right = 0;right < n;++right) {
        while(a[right] - a[left] > k) {
            left++;
        }
        L[right] = right - left + 1;
    }
    int right_ptr = 0;
    for(int left_ptr = 0;left_ptr < n;++left_ptr) {
        if(right_ptr < left_ptr) right_ptr = left_ptr;
        while(right_ptr < n && a[right_ptr] - a[left_ptr] <= k) {
            right_ptr++;
        }
        R[left_ptr] = right_ptr - left_ptr;
    }
    pre[0] = L[0];
    for(int i = 1;i < n;++i) {
        pre[i] = max(pre[i-1], L[i]);
    }
    suf[n-1] = R[n-1];
    for (int i = n - 2;i >= 0;--i) {
        suf[i] = max(suf[i+1], R[i]);
    }
    int max_flowers = 0;
    for(int i = 0;i < n - 1;++i) {
        int current_total = pre[i] + suf[i+1];
        if(current_total > max_flowers) {
            max_flowers = current_total;
        }
    }
    cout << max_flowers;
    return 0;
}
