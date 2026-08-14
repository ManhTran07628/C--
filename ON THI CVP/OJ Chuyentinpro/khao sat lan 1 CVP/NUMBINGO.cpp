#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int m[N],p[N];
set<int> lt[101],ltl[101],s;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> m[i];
        for(int j = 1;j <= m[i];j++) {
            int x;
            cin >> x;
            lt[i].insert(x);
            ltl[i].insert(x);
        }
    }
    
    for(int i = 1;i <= n;i++) {
        for(int k:lt[i]) {
            int cnt = 0;
            for(int j = 1;j <= n;j++) {
                if(ltl[j].find(k) != ltl[j].end()) ltl[j].erase(k);
                if(ltl[j].empty()) cnt++; 
                if(cnt > 1) break;
            }
            if(cnt == 1) {
                for(int j = 1;j <= n;j++) {
                    if(ltl[j].empty()) {
                        p[j] = 1;
                        break;
                    }
                }
            }
        }
        for(int j = 1;j <= n;j++) {
            ltl[j] = lt[j];
        }
    }
    for(int i = 1;i <= n;i++) {
        if(p[i]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}