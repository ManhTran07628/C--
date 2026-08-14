#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "RPS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,a,b,c;
        cin >> n >> a >> b >> c; // R P S
        string s;
        cin >> s;
        ll dem = 0;
        for(int i = 0;i < s.size();i++) {
            if(s[i] == 'R') {
                if(b >= 1) {
                    dem++;
                    b--;
                }
            }
            else if(s[i] == 'P') {
                if(c >= 1) {
                    dem++;
                    c--;
                }
            }
            else if(s[i] == 'S') {
                if(a >= 1) {
                    dem++;
                    a--;
                }
            }
        }
        double n1 = n;
        double kq = round(double(n1/2));
        if(dem >= kq) {
            string k;
            for(int i = 0;i < s.size();i++) {
                if(s[i] == 'R') {
                    k += 'P';
                }
                else if(s[i] == 'P') {
                    k += 'S';
                }
                else if(s[i] == 'S') {
                    k += 'R';
                }
            }
            cout << "YES" << '\n' << k << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}