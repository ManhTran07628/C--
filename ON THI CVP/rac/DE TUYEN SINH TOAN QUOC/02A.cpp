#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // for(int id = 10;id <= 10;id++) {
        map<int,int> lt;
        for(int i = 1;i <= 10;i++) lt[i] = 1;
        while(lt.size() > 1) {
            int i = 1;
            for(auto p:lt) {
                if(i%3==2) lt.erase(p.fi);
                i++;
            }
            break;
        }
        cout << 10 << '\n';
        for(auto p:lt) cout << p.fi << '\n';
    // }
    return 0;
}