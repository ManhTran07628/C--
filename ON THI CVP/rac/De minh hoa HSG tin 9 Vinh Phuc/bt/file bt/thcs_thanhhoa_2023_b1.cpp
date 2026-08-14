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
    string n;
    cin >> n;
    string k = "";
    for(int i = 0;i < n.size();i++) {
        if(n[i] >= 'A' && n[i] <= 'Z' && i != 0) {
            k += '_';
        }
        k += n[i];
    }
    for(int i = 0;k[i];i++) {
        if(k[i] >= 'A' && k[i] <= 'Z') {
            k[i] += 32;
        }
    }
    cout << k;
   return 0;
}