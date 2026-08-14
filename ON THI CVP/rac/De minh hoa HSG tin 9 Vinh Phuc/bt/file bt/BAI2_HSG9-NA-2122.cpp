#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MATKHAU"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    string k,s = "";
    cin >> n;
    while(n--) {
        cin >> k;
        map<char,int> kt;
        for(int i = 0;k[i];i++) {
            kt[k[i]]++;
        }
        ll dem = 0;
        for(char i = 'A';i <= 'Z';i++) {
            if(kt[i] == 1) {
                s+=i;
                break;
            }
        }
    }
    cout << s;
    return 0;
}
