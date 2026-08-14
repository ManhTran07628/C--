#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<int,int> d1,d2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int g,n;
    string w,s;
    cin >> g >> n >> w >> s;
    for(auto i:w) d1[i]++;
    int i = 0,j = 0;
    int ans = 0;
    while(i <= n && j <= n) {
        if(j-i+1 > g) {
            int ok = 1;
            for(auto it:d2) {
                if(it.se != d1[it.fi]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
            d2[s[i]]--;
            i++;
        }
        else {
            d2[s[j]]++;
            j++;
        }
    }
    cout << ans;
    return 0;
}