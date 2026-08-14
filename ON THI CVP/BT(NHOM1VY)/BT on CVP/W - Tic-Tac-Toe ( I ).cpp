#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
char a[100][100];

bool check(char f)
{
    for(int i = 1;i <= 3;i++) 
        if(a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][3] == f) return 1;
    for(int i = 1;i <= 3;i++) 
        if(a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[3][i] == f) return 1;
    if(a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[1][1] == f) return 1;
    if(a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[1][3] == f) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x = 0,o = 0;
        for(int i = 1;i <= 3;i++) {
            for(int j = 1;j <= 3;j++) {
                cin >> a[i][j];
                if(a[i][j] == 'X') x++;
                if(a[i][j] == 'O') o++;
            }
        }
        if(x != o && x!=o+1) {
            cout << "no" << '\n';
            continue;
        }
        if(check('X')==1 && x != o+1) {
            cout << "no" << '\n';
            continue;
        }
        if(check('O')==1 && x != o) {
            cout << "no" << '\n';
            continue;
        }
        cout << "yes" << '\n';
    }
    return 0;
}