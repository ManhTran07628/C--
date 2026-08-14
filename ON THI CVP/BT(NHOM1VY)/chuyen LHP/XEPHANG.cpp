#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<string,int> lt;
int n;
string s;
bool check(int k)
{
    map<string,int> lt;
    for(int i = 1;i <= n-k+1;i++) {
        string t = s.substr(i,k);
        if(lt[t] > 0) return 0;
        lt[t]++;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    s = '/' + s;
    ll l = 1,r = n,ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}