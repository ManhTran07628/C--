#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "qlbd"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    } // 20
    cout << 12;
    string s;
    while(getline(cin,s)) {
        cin.ignore();
        ll kt = 0;
        for(int i = 0;i < s.size();i++) {
            if(s[i] == '9' && s[i+1] == 'A') {
                kt = 1;
                break;
            }
        }
        if(kt) {
            string k;
            k = s.substr(20);
            cout << k << '\n';
        }
    }
    return 0;
}
