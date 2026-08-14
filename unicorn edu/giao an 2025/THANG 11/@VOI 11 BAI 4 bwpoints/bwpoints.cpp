#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n;
vector<pii> pos;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        pos.push_back({a,0});
    }
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        pos.push_back({a,1});
    }
    sort(pos.begin(),pos.end());
    int res = 0,i = 0;
    while(i < pos.size()-1) {
        if(pos[i].se != pos[i+1].se) {
            res++;
            i++;
        }
        i++;
    }
    cout << res;
    return 0;
}