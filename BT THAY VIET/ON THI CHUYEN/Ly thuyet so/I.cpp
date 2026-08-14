#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
int prime[N];
map<int,int> m;
void minprime()
{
    for(int i = 2;i <= sqrt(N);i++) {
        if(prime[i] == 0) {
            for(int j = i*2;j <= N;j+=i) {
                if(prime[j] == 0) {
                    prime[j] = i;
                }
            }
        }
    }
    for(int i = 2;i <= N;i++) {
        if(prime[i] == 0) prime[i] = i;
    }
}


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
    minprime();
    int n;
    while(cin >> n)
    {
        int n1 = n;
        while(n > 1) {
            m[prime[n]]++;
            n /= prime[n];
        }
        int j = 0;
        for(auto i:m) {
            if(j == m.size()-1) {
                if(i.se == 1) cout << i.fi;
                else cout << i.fi << "^" << i.se; 
            }
            else {
                if(i.se == 1) cout << i.fi << "*";
                else cout << i.fi << "^" << i.se << "*";
            }
            j++;
        }
        m.clear();
        cout << '\n';
    }
    return 0;
}