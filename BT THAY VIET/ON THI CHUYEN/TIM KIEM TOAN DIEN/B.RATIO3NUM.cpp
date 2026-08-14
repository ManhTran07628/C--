#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int d[15];
vector<pair<pair<int,int>,int>> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    int n = 9;
    cin >> a >> b >> c;
    for(int q = 1;q <= n;q++) {
        for(int w = 1;w <= n;w++) {
            for(int e = 1;e <= n;e++) {
                
                for(int r = 1;r <= n;r++) {
                    for(int t = 1;t <= n;t++) {
                        for(int y = 1;y <= n;y++) {
                            
                            for(int u = 1;u <= n;u++) {
                                for(int i = 1;i <= n;i++) {
                                    for(int o = 1;o <= n;o++) {
                                        int l1 = q*100+w*10+e;
                                        int l2 = r*100+t*10+y;
                                        int l3 = u*100+i*10+o;
                                        if(
                                            q!=w&&q!=e&&q!=r&&q!=t&&q!=y&&q!=u&&q!=i&&q!=o&&
                                            w!=e&&w!=r&&w!=t&&w!=y&&w!=u&&w!=i&&w!=o&&
                                            e!=r&&e!=t&&e!=y&&e!=u&&e!=i&&e!=o&& 
                                            r!=t&&r!=y&&r!=u&&r!=i&&r!=o&& 
                                            t!=y&&t!=u&&t!=i&&t!=o&& 
                                            y!=u&&y!=i&&y!=o&& 
                                            u!=i&&u!=o&& 
                                            i!=o
                                        ) {
                                            if(a != 0) {
                                            int p = l1 / a;
                                            if(p*a==l1&&p*b==l2&&p*c==l3)
                                            v.push_back({{l1,l2},l3});
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(v.size()==0) {
        cout << "No!!!";
        return 0;
    }
    for(auto lt:v) cout << lt.fi.fi << ' ' << lt.fi.se << ' ' << lt.se << '\n';
    return 0;
}