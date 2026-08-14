#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "merge"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n; cin >> n;
    cin.ignore();
    while(n--) {
        string s;
        getline(cin,s);
        int k = 0;
        int sz = 0;
        for(int i = s.size() - 1;isdigit(s[i]);i--) sz = i;
        for(int i = sz;i <= s.size() - 1;i++)
            k = k * 10 + (s[i] - '0');

        // cout << k << '\n';

        int cnt = 1;
        for(int i = 0;i < sz - 1;i++) {
            if(cnt == k) {
                int j = i;
                for(;j < sz - 1 && s[j] != ' ';j++) 
                    cout << s[j];
                break;
            }
            if(s[i] == ' ') cnt++;
        }
        cout << ' ';
    }
    return 0;
}