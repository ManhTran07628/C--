#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int digit = 0, upp = 0, low = 0;
        for(auto x:s) {
            if(isdigit(x)) digit++;
            if('a' <= x && x <= 'z') low++;
            if('A' <= x && x <= 'Z') upp++;
        }
        if(upp && low && digit) cout << s << '\n';
        else {
            if(digit && !upp && !low) {
                s[1] = 'A', s[2] = 'a';
            }
            else if(!digit && upp && !low) {
                s[1] = '1', s[2] = 'a';
            }
            else if(!digit && !upp && low) {
                s[1] = '1', s[2] = 'A';
            }
            else if(digit && upp && !low) {
                for(int i = 0;i < s.size();i++) {
                    if(isdigit(s[i]) && digit > 1) {s[i] = 'a'; break;}
                    if('A' <= s[i] && s[i] <= 'Z' && upp > 1) {s[i] = 'a'; break;} 
                }
            }
            else if(digit && !upp && low) {
                for(int i = 0;i < s.size();i++) {
                    if(isdigit(s[i]) && digit > 1) {s[i] = 'A'; break;}
                    if('a' <= s[i] && s[i] <= 'z' && low > 1) {s[i] = 'A'; break;} 
                }
            }
            else if(!digit && upp && low) {
                for(int i = 0;i < s.size();i++) {
                    if('A' <= s[i] && s[i] <= 'Z' && upp > 1) {s[i] = '3'; break;} 
                    if('a' <= s[i] && s[i] <= 'z' && low > 1) {s[i] = '6'; break;} 
                }
            }
            cout << s << '\n';
        }
    }
    return 0;
}