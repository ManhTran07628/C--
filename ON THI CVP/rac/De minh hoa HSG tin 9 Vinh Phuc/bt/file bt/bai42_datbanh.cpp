#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<char> a;
int main()
{
    freopen("DATBANH.inp","r",stdin);
    freopen("DATBANH.out","w",stdout);
    string k;
    cin >> k;
    int dem = 0;
    for(int i = 0;i < k.size();i++) {
        if((k[i] >= 'A' && k[i] <= 'Z') || (k[i] >= '0' && k[i] <= '9')) {
            dem+= 3;
        }
        else {
            dem += 2;
        }
    }
    cout << dem;
    return 0;
}

