#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;

ll a[N],b[N];
int main() {
    string k,s;
    cin >> k;
    for(int i = 0;i < k.size();i++) {
        if(k[i] == '0') {
            s += k[i];
            while(k[i] == '0' && i < k.size()) {
                i++;
            }
        }
        if(k[i] != '.')
            s += k[i];
    }
    cout << s;
    return 0;
}
