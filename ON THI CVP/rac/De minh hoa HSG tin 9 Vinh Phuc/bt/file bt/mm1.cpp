#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main()
{
    string k;
    cin >> k;
    int dem = 0;
    for(int i = 0;i < k.size();i++) {
        if(k[i] >= '1' && k[i] <= '9') {
            ll tmp = 0;
            ll so = 0;
            while(tmp <= 3) {
                if(k[i] >= '0' && k[i] <= '9') {
                    tmp++;
                    so = so * 10 + (k[i]-'0');
                    i++;
                }
                else {
                    break;
                }
            }
            if(a[so] == 0) {
                dem++;
                a[so]++;
            }
        }
    }
    cout << dem;
    return 0;
}

