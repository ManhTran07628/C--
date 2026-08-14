#include <bits/stdc++.h>
using namespace std;
#define ll long long
int sotien(int t,int a,int b) {
    int gt = 0;
    if(b > 18) {
        gt = (b-18)*20;
        b = 18;
    }
    int giotq = b - a;
    int sotien = 0;
    if (t >= 2 && t <= 6) {
        if (a >= 6 && b <= 12) {
            sotien = giotq * 6;
        } else if (a >= 12 && b <= 18) {
            sotien = giotq * 10;
        }
        else if (a < 12 && b > 12) {
            sotien = (12 - a) * 6 + (b- 12) * 10;
        }
    } else if(t == 7 || t == 1){
        if (a >= 6 && b <= 12) {
            sotien = giotq * 10;
        } else if (a >= 12 && b <= 18) {
            sotien = giotq * 15;
        }
        else if(a < 12 && b > 12) {
            sotien = (12 - a) * 10 + (b- 12) * 15;
        }
    }
    return sotien + gt;
}


int main() {
    freopen("thamquan.inp","r",stdin);
    freopen("thamquan.out","w",stdout);
    int t,a,b;
    cin >> t >> a >> b;
    cout << sotien(t,a,b);;
    return 0;
}

