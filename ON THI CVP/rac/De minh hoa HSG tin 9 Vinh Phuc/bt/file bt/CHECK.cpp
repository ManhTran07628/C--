#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
priority_queue<ll> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CHECK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,s,k,dem = 0;
    cin >> n >> s >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll max1 = -1e9,tong = 0,kqmax = 0;
    for(int i = 1;i <= n;i++) {
        pq.push(a[i]);
        tong += a[i];
        if(tong > s) {
            if(k > 0) {
                tong -= pq.top();
                pq.pop();
                k--;
            }
            else {
                break;
            }
        }
    }
    cout << pq.size() - 1;
    return 0;
}
