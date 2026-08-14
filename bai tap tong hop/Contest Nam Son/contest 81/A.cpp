#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int ans = 0,n;
string s;
vector<string> lt;

bool ispalind(string k)
{
    string k1 = k;
    reverse(k1.begin(),k1.end());
    return k1 == k;
}

void back_tracking(int id)
{
    if(id == n+1) {
        for(auto d:lt)  if(!ispalind(d)) return;
        ans++;
        return;
    }
    string tmp = "";
    for(int i = id;i <= n;i++) {
        tmp += s[i];
        lt.push_back(tmp);
        back_tracking(i+1);
        lt.pop_back();
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    back_tracking(1);
    cout << ans;
    return 0;
}