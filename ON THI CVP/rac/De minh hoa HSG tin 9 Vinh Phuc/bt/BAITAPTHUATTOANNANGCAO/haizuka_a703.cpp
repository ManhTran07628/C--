#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
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
    string a;
    cin >> a;
    for(int i = 0;i < a.size();i++) {
        if(islower(a[i])){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}