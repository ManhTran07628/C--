#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
ll min_prime[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for (ll i = 2; i * i <= N; ++i) {
        if (min_prime[i] == 0) { 
            for (ll j = i * i; j <= N; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }
    for (ll i = 2; i <= N; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
        }
    }
    // for(int i = 1;i <= 1000;i++) {
    //     cout << min_prime[i] << " " << i << '\n';
    // }
    int cntOdd = 0;
    int x;
    cin >> x;
    int last = -1;
    bool flag = true; // ktra
    int somu = 0;
    while (x > 1) {
        int fact = min_prime[x];
        if(fact != last){ // kiem tra thua so cu va hien tai co = nhau
            if(last != -1){
                if(a[last] == 0){ // somu cua thua so last = 0
                    if(somu % 2 != 0){
                        cntOdd++;
                    }
                    a[last] = 1;
                }
                else{
                    if(a[last] % 2 == 0){
                        if(somu % 2 != 0){
                            cntOdd++;
                        }
                    }
                    else{
                        if(somu % 2 != 0){
                            cntOdd--;
                        }
                    }
                    a[last] += somu;
                }
                somu = 0;
            }
            last = fact;
        }
        somu++;
        x /= fact;
        cout << somu << " " << fact << '\n';
    }
    cout << cntOdd;
    return 0;
}