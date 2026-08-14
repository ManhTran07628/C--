#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<char,int>
const int MM = 2e5+7;
int vis[MM];
deque<int> dq1,dq2;
vector<pii> v;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    string s; cin >> s;
    for(int i = 0;i < n;i++) {
        v.push_back({s[i],i});
    }
    sort(v.begin(),v.end());
    for(auto x:v) dq1.push_back(x.se);
    

    sort(v.begin(),v.end(), [] (pii a,pii b){
        if(a.fi != b.fi) return a.fi > b.fi;
        return a.se < b.se;
    });
    
    for(auto x:v) dq2.push_back(x.se);

    while(q--) {
        int type; cin >> type;
        if(type == 0) {
            while(!dq1.empty() && vis[ dq1.front() ]) dq1.pop_front();
            if(!dq1.empty()) vis[ dq1.front() ] = 1;
        }
        else {
            while(!dq2.empty() && vis[ dq2.front() ]) dq2.pop_front();
            if(!dq2.empty()) vis[ dq2.front() ] = 1;
        }
    }
    for(int i = 0;i < n;i++) {
        if(vis[i]) continue;
        cout << s[i];
    }
    return 0;
}