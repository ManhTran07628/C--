#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];
deque<int> dmax,dmin;
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
    int n,x;
    cin >> n >> x;
    int ans = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1,j = 1;j <= n;j++) {
        while(!dmax.empty() && a[dmax.back()] <= a[j]) dmax.pop_back();
        while(!dmin.empty() && a[dmin.back()] >= a[j]) dmin.pop_back();
        dmax.push_back(j);
        dmin.push_back(j);
        while(a[dmax.front()] - a[dmin.front()] > x) {
            i++;
            if(dmax.front() < i) dmax.pop_front();
            if(dmin.front() < i) dmin.pop_front();
        }
        ans = max(ans,j-i+1);
    }
    cout << ans;
    return 0;
}