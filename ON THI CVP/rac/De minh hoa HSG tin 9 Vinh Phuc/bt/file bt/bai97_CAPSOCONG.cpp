#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CAPSOCONG"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 1;i <= 3;i++) {
        cin >> a[i];
    }
    sort(a+1,a+4);
    ll vtm = 1e9;
    for(int i = 1;i <= 2;i++) {
        b[i] = a[i+1] - a[i];
        vtm = min(vtm,b[i]);
    }
    for(int i = 1;i <= 2;i++) {
        if(b[i] != vtm) {
            cout << a[i] + vtm;
            return 0;
        }
    }
    cout << a[3]+vtm;
    return 0;
}