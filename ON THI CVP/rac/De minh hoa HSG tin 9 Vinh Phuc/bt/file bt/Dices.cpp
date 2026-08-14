#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main() {
    ll s1,s2,s3;
    ll dem = 0,sol = -1e9;
    cin >> s1 >> s2 >> s3;
    for(int i = 1;i <= s1;i++) {
        for(int j = 1;j <= s2;j++) {
            for(int k = 1;k <= s3;k++) {
                ll ans = i + j + k;
                a[ans]++;
            }
        }
    }
    for(int i = 3;i <= 80;i++) {
        sol = max(sol,a[i]);
    }
    for(int i = 3;i <= 80;i++) {
        if(sol == a[i]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}

