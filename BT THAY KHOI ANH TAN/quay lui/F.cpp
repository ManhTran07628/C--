#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 50;
int a[MAXN];
vector<pair<int,int>> v;
int n,ans = 1;

void back_tracking(int id)
{
    int p = v.size();
    ans = max(ans,p);
    for(int i = id;i <= n;i++) {
        if(v.size() == 0) {
            v.push_back({a[i],i});
            back_tracking(i+1);
            v.pop_back();
            continue;
        }
        bool ok = 1;
        for(auto j:v) {
            if(i % j.se == 0) {
                ok = 0;
                break;
            }
        }
        
        if(ok && a[i] > v[v.size()-1].fi) {
            v.push_back({a[i],i});
            back_tracking(i+1);
            v.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    back_tracking(1);
    cout << ans;
    return 0;
}