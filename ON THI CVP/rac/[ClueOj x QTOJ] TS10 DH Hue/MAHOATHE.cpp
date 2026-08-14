#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int n;
set<string> v;
void back_tracking(int length,string s) {
    if(length == n) {
        v.insert(s);
        return;
    }
    for(char i = '0';i <= '1';i++) {
        back_tracking(length+1,s+i);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    back_tracking(0,"");
    for(auto i:v) cout << i << ' ';
    cout << '\n';
    cout << v.size();
    return 0;   
}