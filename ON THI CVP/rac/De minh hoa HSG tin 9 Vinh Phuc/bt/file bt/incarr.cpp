#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
int main()
{
    string k,s;
    cin >> k;
    int dem = 0;
    for(int i = 0;i < k.size();i++) {
        if(k[i] >= '1' && k[i] <= '9') {
            s += k[i];
        }
    }
    cout << s;
    return 0;
}
