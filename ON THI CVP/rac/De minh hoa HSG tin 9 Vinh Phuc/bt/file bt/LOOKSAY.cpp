#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "LOOKSAY"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int t;
    cin >> t;
    while(t--) {
        string k;
        cin >> k;
        for(int i = 0;k[i];i++) {
            if(k[i] == k[i+1]) {
                ll dem = 1;
                while(k[i] == k[i+1] && i < k.size()) {
                    dem++;
                    i++;
                }
                cout << dem << k[i];
            }
            else cout << 1 << k[i];
        }
        cout << '\n';
    }
    return 0;
}



