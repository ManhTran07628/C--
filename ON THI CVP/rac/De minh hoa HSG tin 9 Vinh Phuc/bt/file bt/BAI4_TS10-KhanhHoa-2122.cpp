#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DAYSOLC"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    ll vtd = 0,vtc = 0,j = 1;
    for(int i = 1;i <= n;i++) {
        while(a[j] > a[j+1] && j <= n) {
            j++;
        }
        ll vtmid = j-1;
        while(a[j] < a[j+1] && j <= n) {
            j++;
        }
        if(j > n) {
            continue;
        }
        if(j-i >= 3) {
            if((j-i) / 2 == vtmid)
                if(vtc - vtd < j-i) {
                    vtd = i;
                    vtc = j;
                }
        }
        j=i;
    }
    if(vtd == 0 && vtc == 0) {
        cout << -1;
        return 0;
    }
    for(int i = vtd;i <= vtc;i++)
        cout << a[i] << " ";
    return 0;
}