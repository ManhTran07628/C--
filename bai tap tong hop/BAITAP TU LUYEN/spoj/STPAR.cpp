#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int a[MM];
stack<int> st;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n) {
        if(n == 0) break;
        for(int i = 1;i <= n;i++) cin >> a[i];
        while(!st.empty()) st.pop();

        vector<int> v;
        for(int i = 1;i <= n;i++) v.push_back(a[i]);

        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());

        for(int i = 1;i <= n;i++) 
            a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
        
        int cur_id = 1;
        for(int i = 1;i <= n;i++) {
            while(!st.empty() && st.top() == cur_id) {
                st.pop();
                cur_id++;
            }
            if(a[i] != cur_id) st.push(a[i]);
            else cur_id++;
        }
        while(!st.empty() && cur_id == st.top()) {
            cur_id++;
            st.pop();
        }
        if(cur_id == n+1) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}