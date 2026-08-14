#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ARN"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string k,s;
    cin >> k >> s;
    ll dem = 0,j = 0;
    for(int i = 0;i < k.size();i++) {
        if(k[i]==s[j]) {
            while(k[i] == s[j] && i < k.size() && j < k.size()) {
                i++;
                j++;
            }
            j--;
            i--;
            if(j == s.size()-1) {
                dem++;
            }
            j = 0;
        }
    }
    cout << dem;
    return 0;
}