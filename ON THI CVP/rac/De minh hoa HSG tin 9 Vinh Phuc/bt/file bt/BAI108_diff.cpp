#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "diff"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 1;i <= 3;i++) {
        cin >> a[i];
    }
    if(a[1] == a[2]) cout << a[3];
    if(a[1] == a[3]) cout << a[2];
    if(a[2] == a[3]) cout << a[1];
    return 0;
}

