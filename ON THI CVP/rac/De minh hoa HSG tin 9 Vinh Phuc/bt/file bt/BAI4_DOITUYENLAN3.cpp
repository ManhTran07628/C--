#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
queue<ll> q;
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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll j = 1,vtd = 0,vtc = 0,max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        b[a[i]]++;
        q.push(a[i]);
        if(b[a[i]] > 1) {
            while(q.front() != a[i]) {
                q.pop();
                b[a[j]] = 0;
                j++;
            }
            q.pop();
            b[a[j]] = 1;
            j++;
        }
        if(i - j + 1 > max1) {
            max1 = i - j + 1;
            vtd = j;
            vtc = i;
        }
    }
    cout << max1 << '\n';
    for(int i = vtd;i <= vtc;i++) {
        cout << a[i] << " ";
    }
    return 0;
}