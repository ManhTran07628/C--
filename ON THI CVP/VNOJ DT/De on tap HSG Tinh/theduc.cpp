#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];
stack<int> st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "theduc"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        if(st.empty()) cout << 0 << ' ';
        else cout << st.top() << ' ';
        st.push(i);
    }
    return 0;
}