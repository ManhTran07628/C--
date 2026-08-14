#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e4+7;
int n;
string s;
int ans = 0,cnt = 0;
struct dl{char a,b,c;int val;};
vector<dl> v1,v2;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "BRICK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> s;
        int sum = 0,c = '0';

        if(s[0] != '.' && s[1] == '.') {
            v1.push_back({s[0],s[1],s[2],s[0] - c});
        }
        else if(s[1] != '.' && s[0] != '.' && s[2] == '.') {
            v1.push_back({s[0],s[1],s[2],s[0] + s[1] - c*2});
        }
        
        
        if(s[2] != '.' && s[1] == '.') {
            v2.push_back({s[0],s[1],s[2],s[2] - c});
        }
        else if(s[2] != '.' && s[1] != '.' && s[0] == '.') {
            v2.push_back({s[0],s[1],s[2],s[2] + s[1] - c*2});
        }

        if(s[0] != '.' && s[1] != '.' && s[2] != '.') ans += s[0] + s[1] + s[2] - c*3;
        if(s[0] == '.' && s[1] != '.' && s[2] == '.') cnt = max(cnt,s[1]-c);

    }
    sort(v1.begin(),v1.end(), [] (dl &a,dl &b){
        return a.val > b.val;
    });
    sort(v2.begin(),v2.end(), [] (dl &a,dl &b){
        return a.val > b.val;
    });
    while(v1.size() < 2) v1.push_back({'0','0','0',0});
    while(v2.size() < 2) v2.push_back({'0','0','0',0});
    for(int i = 0;i < 2;i++) {
        ans += max(v1[i].val,v2[i].val);
    }
    cout << max(ans,cnt);
    return 0;
}