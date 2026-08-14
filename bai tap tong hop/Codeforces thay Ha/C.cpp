#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MM = 1e6+7;
ll a[MM],ps[MM],pfm[MM],sfm[MM], n;

void process(ll a[], ll p[], int t)
{
    if(t == 1) {
        stack<int> st;
        for(int i = 1; i <= n; ++i) {
            while(!st.empty() && a[st.top()] <= a[i]) st.pop();
            p[i] = st.empty() ? 0 : st.top(); 
            st.push(i);
        }
    }
    else {
        stack<int> st;
        for(int i = n; i >= 1; --i) {
            while(!st.empty() && a[st.top()] < a[i]) st.pop();
            p[i] = st.empty() ? (n+1) : st.top();
            st.push(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    process(a, pfm, 1);
    process(a, sfm, 2);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = pfm[i]+1;j <= i;j++) {
            int L = max(i,j);
            int R = sfm[i] - 1;
            int cnt = -1;
            while(L <= R) {
                int mid = (L+R)/2;
                if(ps[mid] - ps[j-1] > 2*a[i]) {
                    cnt = mid;
                    R = mid - 1;
                }
                else L = mid + 1;
            }
            if(cnt != -1) ans += sfm[i] - cnt;
        }
    }
    cout << ans << '\n';
    return 0;
}
