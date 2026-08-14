#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n;
long long k, a[N];
deque<int> c, st;
int main()
{
    cin >> n >> k;
    for (int i=1 ; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+1+n, greater<int>());
    st.push_back(1);
    c.push_back(0);
    long long ans = 0;
    for (int i=2; i<=n; i++){
            st.push_back(i);
        if (a[i]+k <= a[st.front()]){
            if (c.front() == 0) ans += a[st.front()];
            c.push_back(1);
            c.pop_front(); st.pop_front();
        }
        else
         c.push_back(0);
    }
    for (int i=0; i<c.size(); i++){
       if (c[i] == 0) ans += a[st[i]] ;

    }
    cout << ans;
    return 0;
}