#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    ll n;
    cin >> n;
    string k;
    cin >> k;
    ll demv = 0,demn = 0,demm = 0;
    for(int i = 0;i < k.size();i++) {
        if(k[i] == '1') {
            demv++;
        }
        else if(k[i] == '2') {
            demn+= demv;
        }
        else {
            demm += demn;
        }
    }
    cout << demm;
    return 0;
}








