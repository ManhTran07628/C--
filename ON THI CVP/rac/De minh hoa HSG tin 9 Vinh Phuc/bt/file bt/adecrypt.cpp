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
    int n,j = 1;
    cin >> n;
    string k,k1 = "";
    cin >> k;
    for(int i = 0;i < n;i += j) {
        k1 += k[i];
        j++;
    } 
    cout << k1;
    return 0;
}