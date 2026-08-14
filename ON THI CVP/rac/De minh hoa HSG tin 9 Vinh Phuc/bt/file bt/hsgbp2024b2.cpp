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
        if(k[i] >= '0' && k[i] <= '9') {
            dem++;
        }
    }
    cout << dem;
    return 0;
}

