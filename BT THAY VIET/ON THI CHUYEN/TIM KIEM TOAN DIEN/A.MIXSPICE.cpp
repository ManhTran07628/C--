#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int m = 10,n,ans = 0;
vector<int> v;
set<string> se;
void back_tracking(int sum)
{
    if(sum == n && v.size() == m) {
        string s;
        for(auto i:v) {
            char c = i+'0';
            s += c;
        }
        se.insert(s);
        ans++;
        return;
    }
    for(int i = 1;i <= 3;i++) {
        if(sum+i <= n) {
            v.push_back(i);
            back_tracking(sum+i);
            v.pop_back();
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n > 30) {
        cout << 0;
        return 0;
    }
    back_tracking(0);
    cout << ans << '\n';
    for(auto i:se) {
        for(int j = 0;j < i.size();j++) cout << i[j] << ' ';
        cout << '\n';
    }
    return 0;
}