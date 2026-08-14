#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    freopen("tngh.inp","r",stdin);
    freopen("tngh.out","w",stdout);
    string a,b;
    cin >> a;
    for(int i = 0;i < a.size();i++) {
        if(a[i] >= 'a' && a[i] <= 'z') {
            a[i] -= 32;
        }
    }
    for (int i = 0;i < a.size();i++) {
        if(a[i] >= 'A' && a[i] <= 'C') {
            b[i] = 2;
        }
        if(a[i] >= 'D' && a[i] <= 'F') {
            b[i] = 3;
        }
        if(a[i] >= 'G' && a[i] <= 'I') {
            b[i] = 4;
        }
        if(a[i] >= 'J' && a[i] <= 'L') {
            b[i] = 5;
        }
        if(a[i] >= 'M' && a[i] <= 'O') {
            b[i] = 6;
        }
        if(a[i] >= 'P' && a[i] <= 'S') {
            b[i] = 7;
        }
        if(a[i] >= 'T' && a[i] <= 'V') {
            b[i] = 8;
        }
        if(a[i] >= 'W' && a[i] <= 'Z') {
            b[i] = 9;
        }
    }
    int d = a.size();
    for (int i = 0;i < a.size();i++) {
        if(b[i] != b[d-i-1]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
