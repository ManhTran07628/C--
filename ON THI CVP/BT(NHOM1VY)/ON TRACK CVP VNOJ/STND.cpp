#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<int> a;
map<int,int> lt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int b;
        cin >> b;
        if(lt[b] == 0) {
            a.push_back(b);
            lt[b]++;
        }
    }
    sort(a.begin(),a.end());
    cout <<a[a.size()-1]<< ' '<<a[a.size()-2]<<'\n'<<a[0]<<' '<<a[1];
    return 0;
}