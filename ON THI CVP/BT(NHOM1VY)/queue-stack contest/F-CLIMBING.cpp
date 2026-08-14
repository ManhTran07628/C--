#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];
deque<int> ma,mi;
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
    int n,m,c;
    cin >> n >> m >> c;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    bool check = 0;
    for(int i = 1;i <= n;i++) {
        while(!mi.empty() && a[mi.back()] >= a[i]) mi.pop_back();
        mi.push_back(i);
        if(mi.front() <= i-m) mi.pop_front();

        while(!ma.empty() && a[ma.back()] <= a[i]) ma.pop_back();
        ma.push_back(i);
        if(ma.front() <= i-m) ma.pop_front();

        if(i >= m) {
            if(a[ma.front()] - a[mi.front()] <= c) {
                cout << i-m+1 << '\n';
                check = 1;
            }
        }
    }
    if(!check) cout << "NONE";
    return 0;
}