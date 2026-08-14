#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main() {
    //freopen("bai03.inp","r",stdin);
    //freopen("bai03.out","w",stdout);
    ll n;
    string k,hv;
    cin >> n >> hv;
    cin.ignore();
    getline(cin,k);
    if(k.size() % n != 0) {
        while(k.size() % n != 0) {
            k += ' ';
        }
    }
    string k1;
    ll s = k.size();
    int vt = 0;
    for(int i = 0;i < s;i+=n) {
        string tmp;
        for(int j = 0;j < n;j++) {
            tmp += k[i +(hv[j] - '0')-1];
        }
        cout << tmp << endl;
    }
    return 0;
}
