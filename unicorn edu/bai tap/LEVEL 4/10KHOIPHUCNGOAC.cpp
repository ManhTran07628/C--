#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,a[MM];
stack<pii> st;
vector<int> valid;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];


    for(int i = 1;i <= n;i++) {
        st.push({ valid.size() ,a[i]});
        valid.push_back(1);
        while(!st.empty()) {
            int pos = st.top().fi, meet = st.top().se;
            if(valid.size() == pos + meet + 1) {
                valid.push_back(0);
                st.pop();
            }
            else break;
        }

    }
    

    for(auto x:valid) {
        cout << (x == 1 ? '(' : ')');
    }
    
    return 0;
}