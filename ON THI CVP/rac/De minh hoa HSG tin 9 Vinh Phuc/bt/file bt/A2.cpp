#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    ll t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string k;
        getline(cin,k);
        cin.ignore(0);
        for(auto i:k) {
            if(i >= 'A' && i <= 'Z') cout << char(i + 'a'-'A');
            else cout << i;
        }
        cout << '\n';
    }
    return 0;
}