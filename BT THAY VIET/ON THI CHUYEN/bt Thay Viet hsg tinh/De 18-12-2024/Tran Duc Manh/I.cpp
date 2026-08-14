#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],d[N],w[N];
stack<ll> st;
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
        cin >> d[i] >> w[i];
    }
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        while(!st.empty() && w[st.top()] > w[i]) st.pop();

        if(st.empty() || w[st.top()] < w[i]) {
            cnt++;
            st.push(i);
        }
    }
    cout << cnt;
    return 0;
}