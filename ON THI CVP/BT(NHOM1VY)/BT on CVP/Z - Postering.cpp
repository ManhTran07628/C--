#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int d[N],w[N];
stack<int> st;

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
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> d[i] >> w[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        while(!st.empty() && w[st.top()] > w[i]) st.pop();
        if(st.empty() || w[st.top()] < w[i]) {
            ans++;
            st.push(i);
        }
    }
    cout << ans << '\n';
    return 0;
}