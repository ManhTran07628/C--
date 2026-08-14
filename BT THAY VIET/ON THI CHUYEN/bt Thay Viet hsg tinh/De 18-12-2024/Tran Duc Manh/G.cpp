#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
priority_queue<ll> pq;
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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll i = 1,j = 1;
    while(i <= n && j <= n) {
        pq.push(a[j]);
        b[a[j]]++;
        if(j-i+1 == k) {
            if(b[pq.top()] > 0)
                cout << pq.top() << '\n';
            else {
                while(b[pq.top()] == 0) pq.pop();
                cout << pq.top() << '\n';
            }
            b[a[i]]--;
            if(b[a[i]] == 0) {
                if(a[i] == pq.top()) {
                    pq.pop();
                }
            }
            i++;
        }
        j++;
    }
    return 0;
}