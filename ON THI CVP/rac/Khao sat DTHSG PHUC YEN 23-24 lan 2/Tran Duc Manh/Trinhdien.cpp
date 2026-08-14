
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N],b[N];
stack<ll> st;
ll n;
void solveleft()
{
    for(int i = 1;i <= n+2;i++) {
        if(i == 1) {
            st.push(i);
            l[i] = 0;
            continue;
        }
        if(a[i] > a[st.top()]) {
            l[i] = st.top();
            st.push(i);
        }
        else {
            while(!st.empty() && a[i] <= a[st.top()]) {
                st.pop();
            }
            if(st.size() != 0) {
                l[i] = st.top();
            }
            else l[i] = 0;
            st.push(i);
        }
    }
    while(!st.empty()) st.pop();
}
void solveright()
{
    for(int i = n+2;i >= 1;i--) {
        if(i == n+2) {
            st.push(i);
            r[i] = 0;
            continue;
        }
        if(a[i] > a[st.top()]) {
            r[i] = st.top();
            st.push(i);
        }
        else {
            while(!st.empty() && a[i] < a[st.top()]) {
                st.pop();
            }
            if(st.size() != 0) {
                r[i] = st.top();
            }
            else r[i] = 0;
            st.push(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Trinhdien"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    a[n+1] = a[1];
    a[n+2] = a[2];
    solveleft();
    solveright();
    ll p1 = 0,p2 = n+2,p3 = 0;
    for(int i = 1;i <= n+2;i++) {
        if(abs(i-l[i]) + abs(i-r[i]) < abs(p2-p1) + abs(p2-p3) && l[i] > 0 && r[i] > 0) {
            p1 = l[i];p2 = i;p3 = r[i];
        }
    }
    cout << p1 << " " << p2 - (p2 > n ? n : 0) << " " << p3 - (p3 > n ? n : 0);
    return 0;
}