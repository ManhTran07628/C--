#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "uocxau"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s,k;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        k += s[i];
        ll kt = 1;
        for(int j = 0;j < s.size(); j+=k.size()) {
            string tmp;

            for(int h = j;h < k.size()+j;h++)
                tmp += s[h];

            if(k != tmp) {
                kt = -1;
                break;
            }
        }
        if(kt == 1) {
            cout << k;
            return 0;
        }
    }
    return 0;
}