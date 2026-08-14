#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N]; 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "phantu"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    cin >> s;
    ll cnt = 0;
    for(int i = 0;i < s.size();i++) {
        if(!isdigit(s[i])) {
            if(!isdigit(s[i]) && !isdigit(s[i+1])) {
                ll tmp = 1;
                if(s[i] == 'H') cnt += 1 * tmp;
                if(s[i] == 'O') cnt += 16 * tmp;
                if(s[i] == 'N') cnt += 14 * tmp;
                if(s[i] == 'C') cnt += 12 * tmp;
                continue;
            }
            ll tmp = 0;
            ll j = i;
            i++;
            while(isdigit(s[i]) && i < s.size()) {
                tmp = tmp * 10 + (s[i] - '0');
                i++;
            }
            i--;
            if(s[j] == 'H') cnt += 1 * tmp;
            if(s[j] == 'O') cnt += 16 * tmp;
            if(s[j] == 'N') cnt += 14 * tmp;
            if(s[j] == 'C') cnt += 12 * tmp;
        }
    }
    cout << cnt;
    return 0;
}