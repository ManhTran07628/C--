#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<char,int> chuso;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x;
    int k;
    cin >> x >> k;
    if(k == 0) {
        ll so = stoll(x);
        ll ans = -1;
        map<char,int> lt;
        for(char c = '0';c <= '9';c++) {
            string s = "";
            for(int i = 0;i < x.size();i++) {
                s += c;
            }
            ll nums = stoll(s);
            if(ans == -1 && nums >= so) {
                ans = nums;
            }
            else if(nums >= so) {
                ans = min(ans,nums);
            }
        }
        cout << ans;
    }
    else {
        int n = x.size();
        ll ans = -1,nums = stoll(x);
        for(char c = '0';c <= '9';c++) {
            for(char j = '0';j <= '9';j++) {
                for(int i = 0;i < n;i++) {
                    string s;
                    for(int l = 0;l < i;l++) s += c;
                    s += j;
                    for(int r = i+1;r < n;r++) s += c;
                    ll so = stoll(s);
                    if(ans == -1 && so >= nums) {
                        ans = so;
                    }
                    if(so >= nums){
                        ans = min(ans,so);
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}
