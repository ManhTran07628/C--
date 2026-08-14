#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<int> v;
int d[50];
int n,r;
void backtracking(int id)
{
    if(v.size() == r) {
        for(auto i:v) {
            if(i >= 10) {
                cout << ' ';
            }
            else cout << ' '<<' ';
            cout << i;
        }
        cout << '\n';
        return;
    }

    for(int i = id;i <= n;i++) {
        if(d[i]==0) {
            d[i]=1;
            v.push_back(i);
            backtracking(i+1);
            v.pop_back();
            d[i]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r;
    backtracking(1);
    return 0;
}