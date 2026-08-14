#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<int> nums;

void calc()
{
    int total = 0;
    while(1) {
        for(int i = 0;i < nums.size();i++) 
        if(nums[i] > 0)
            nums[i]--;


        bool ok = 1;
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] != 0) ok = 0;
        }
        total++;
        if(ok) break;
    }
    cout << total << '\n';
}

void solve()
{
    string s;
    cin >> s;
    for(char i:s) 
        nums.push_back(i-'0');
    calc();
    nums.clear();

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}