#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
char a[3][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= 2;i++) {
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    } 
    string s = "";
    for(int i = 1;i <= n;i++) {
        if(a[1][i] == 92 && a[1][i+3] == 47) {
            if(a[1][i+4] == 92 && a[1][i+7] == 47) {
                s += 'w';
                i+=7;
            }
            else {   
                s += 'v';
                i+=3;
            }
        }
    }
    cout << s;
    return 0;
}