// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    long long n,tmp = -1e9;
    long long a[1000001];
    long long dem = 0;
    cin >> n;
    for (long long i = 0;i < n;i++)
        cin >> a[i];
    for (long long i = 0;i < n;i++) {
        dem += a[i];
        if(dem < 0) {
            dem = 0;
        }
        tmp = max(tmp,dem);
    }
    cout << tmp;
    return 0;
}