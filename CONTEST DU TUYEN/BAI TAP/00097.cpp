#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,l1,r1,l2,r2,h[MM];
map<int,int> mp;
vector<pii> adj,Inter,A,B;
int cntA = 0, cntB = 0, cntI = 0, cA = 0, cB = 0;

void process(vector<pii> &x)
{
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> l1 >> r1 >> l2 >> r2;
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
        mp[ h[i] ]++;
    }

    for(int i = 1;i <= n;i++) {

        if(l1 <= h[i] && h[i] <= r1 && l2 <= h[i] && h[i] <= r2) {
            Inter.push_back({h[i],mp[ h[i] ]});
            continue;
        }   

        if(l1 <= h[i] && h[i] <= r1) {
            A.push_back({h[i],mp[ h[i] ]});
        }

        if(l2 <= h[i] && h[i] <= r2) {
            B.push_back({h[i],mp[ h[i] ]});
        }
    }
    process(Inter);
    process(A);
    process(B);



    for(auto x: Inter) {
        // cout << x.fi << ' ' << x.se << '\n';
        cntI += x.se;
    }
    // cout << '\n';
    for(auto x: A) {
        // cout << x.fi << ' ' << x.se << '\n';
        cntA += x.se;
    }
    // cout << '\n';
    for(auto x: B) {
        // cout << x.fi << ' ' << x.se << '\n';
        cntB += x.se;
    }

    // cout << cntA << ' ' << cntB << ' ' << cntI << '\n';

    if(cntI <= m) {
        if(cntI % 2 == 1) cA++;
        cA += cntI / 2;
        cB += cntI / 2;
        m -= cntI;
    }
    else {
        if(m % 2 == 1) cout << "Petya";
        else cout << "Draw";
        return 0;
    }

    if(cntI % 2 == 1) { // tuc la den luot cua thang A cuoi -> den luot thg B
        if(m > 0 && cntB > 0) {
            m--; cntB--;
            cB++;
        } 
    }

    while(m > 0) {
        if(m > 0 && cntA > 0) {
            m--; cntA--;
            cA++;
        }
        else if(m > 0 && cntA == 0) m--;

        if(m == 0) break;

        if(m > 0 && cntB > 0) {
            m--; cntB--;
            cB++;
        }
        else if(m > 0 && cntB == 0) m--;
    }

    if(cA > cB) cout << "Petya";
    else if(cA < cB) cout << "Vasya";
    else cout << "Draw";


    return 0;
}
