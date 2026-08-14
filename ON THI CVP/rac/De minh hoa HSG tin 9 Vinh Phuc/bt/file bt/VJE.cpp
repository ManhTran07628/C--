#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    ll dem = 0;
    string k;
    cin >> k;
    for(int i = 0;i < k.size();i++) {
        if(k[i] == 'Q') {
            for(int j = i+1;j < k.size();j++) {
                if(k[j] == 'A') {
                    for(int h = j + 1;h < k.size();h++) {
                        if(k[h] == 'Q') dem++;
                    }
                }
            }
        }
    }
    cout << dem;
    return 0;
}