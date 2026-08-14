#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e5+7;
int a[N][26];
map<char,int> b;
int n;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < 26;j++) {
            a[i][j] = a[i-1][j];
        }
        a[i][s[i-1]-'a']++;
        if(a[i][s[i-1]-'a'] > 1) {
            for(int j = 0;j < 26;j++) {
                if(b[j] <= b[s[i-1]-'a']) a[i][j] = 0;
            }
            a[i][s[i-1]-'a']++;
        }
        b[s[i-1]-'a'] = i;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int cnt = 0;
        for(int j = 0;j < 26;j++) {
            if(a[i][j] == 1) cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}