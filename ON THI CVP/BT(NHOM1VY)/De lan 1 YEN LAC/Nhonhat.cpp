#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<int,ll> lt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(char i:s) lt[i-'0']++;
    if(lt[1] > 0) {
        cout << 1;lt[1]--;
    }
    for(int i = 1;i <= lt[0];i++) cout << 0;
    for(int i = 1;i <= lt[1];i++) cout << 1;
    for(int i = 2;i <= 9;i++) {
        for(int j = 1;j <= lt[i];j++) cout << i;
    }
    return 0;
}