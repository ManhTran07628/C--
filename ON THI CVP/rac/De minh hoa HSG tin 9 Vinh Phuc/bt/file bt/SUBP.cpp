#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
stack<int> st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SUBP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
   string k;
    int ma = 0;
    cin >> k;
    st.push(-1);
    for(int i = 0;i < k.size();i++) {
        if(k[i] == '(') {
            st.push(i);
        }
        else {
            st.pop();
            if(st.size()>0)
                ma=max(ma,i-st.top());
            else
                st.push(i);
        }
    }
    cout << ma;
    return 0;
}