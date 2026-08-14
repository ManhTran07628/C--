#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "TABLET"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,k,a,b,c;
    cin >> n >> m >> k >> a >> b >> c;
    ll J = n * a,R = m * b,S = k * c;
    if(max({J,R,S}) == J) {
        cout << "Joffrey" << " ";
    }
    if(max({J,R,S}) == R) {
        cout << "Robb" << " ";
    }
    if(max({J,R,S}) == S) {
        cout << "Stannis" << " ";
    }
    return 0;
}


