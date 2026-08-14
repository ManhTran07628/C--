#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N];
stack<ll> st;
ll n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Camera"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    st.push(0);a[0] = -1;
    for(int i = 1;i <= n;i++) {
        while(a[i] <= a[st.top()]) st.pop();
        l[i] = i - st.top() - 1;
        st.push(i);
        cout << st.top() << '\n';
    }
    // for(int i = 1;i <= n;i++) {
    //     cout << l[i] << ' ';
    // }
    return 0;
}