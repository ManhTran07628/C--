#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long tx, ty, n, x, y;
string s;
vector < char > a;
char b[N];
void pos(char c)
{
    if (c == 'R') x += 1;
    if (c == 'L') x -= 1;
    if (c == 'U') y += 1;
    if (c == 'D') y -= 1;
}
int main()
{
    #define TASKNAME "journey"
    if( fopen(TASKNAME".inp", "r") ){
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tx >> ty >> s;
    n = s.size();
    x =0; y = 0;
    int k = 0;
    for (int i=0; i<=n; i++){
        pos(s[i]);
        if (s[i] == '?') k++;
    }
    int dis = abs(tx - x) + abs(ty - y);
    if (k < dis) cout << "IMPOSSIBLE";
    else {
        while (y > ty){
                y--;
                k--;
                a.push_back('D');
            }
        while (x > tx){
            x --;
            k--;
            a.push_back('L');
        }
        while  (x < tx) {
            x++;
            k--;
            a.push_back('R');
        }
        while  (y < ty) {
            y ++;
            k--;
            a.push_back('U');
        }
        if (k % 2 == 1) cout << "IMPOSSIBLE";
        else {
            while (k > 0){
                k -= 2;
                a.push_back('D');
                a.push_back('U');
            }
            for (int i = 0; i<a.size(); i++)
              b[i] = a[i];
              int m = a.size();
            sort(b, b+m);
            int d = 0;
            for (int i=0; i<n; i++)
            if (s[i] == '?') {cout << b[d]; d++; }
            else cout << s[i];
        }

    }
    return 0;
}