#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // dem so cap A dung truoc BC
    // neu ta co AAABC thi co 3 cach tao ra
    string s; cin >> s;
    int cnt = 0, res = 0;
    for(int i = 0;i < s.size();) {
        if(s[i] == 'A') {
            cnt++; 
            i++;
        }
        else if(s[i] == 'C') {
            cnt = 0;
            i++;
        }
        else if(s[i] == 'B') {
            if(s[i+1] == 'C') {
                res += cnt;
                i += 2;
            }
            else {
                cnt = 0;
                i++;
            }
        }
    }
    cout << res;
    return 0;
}