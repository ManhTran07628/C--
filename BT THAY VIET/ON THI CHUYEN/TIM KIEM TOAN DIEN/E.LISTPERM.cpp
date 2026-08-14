#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int n;
vector<int> v;
int d[10];
void backtracking()
{
    if(v.size() == n) {
        for(auto i:v) {
            cout<<"    "<<i;
        }
        cout << '\n';
    }
    for(int i = 1;i <= n;i++) {
        if(d[i] == 0) {
            d[i]=1;
            v.push_back(i);
            backtracking();
            v.pop_back();
            d[i]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    backtracking();
    return 0;
}