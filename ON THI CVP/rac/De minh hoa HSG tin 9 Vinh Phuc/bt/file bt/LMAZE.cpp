#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],dem = 0;
ll n;
void dq(ll i,ll dem) {
    if(a[i] == n) {
        cout << dem+1;
        return;
    }
    else return dq(a[i],dem+1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "LMAZE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    if(a[a[a[n]]] != n || a[n] == n) {
        cout << -1;
        return 0;
    }
    dq(1,1);
    return 0;

}