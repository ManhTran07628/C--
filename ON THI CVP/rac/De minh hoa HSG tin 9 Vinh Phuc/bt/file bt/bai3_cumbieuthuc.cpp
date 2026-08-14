#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
stack<ll> a;
int main() {
    freopen("bai3.inp","r",stdin);
    freopen("bai3.out","w",stdout);
    string s;
    cin >> s;
    int dem = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(') {
            dem++;
        }
    }
    cout << dem << endl;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(') {
            a.push(i);
        }
        else if(s[i] == ')') {
            for(int j = a.top();j <= i;j++) {
                cout << s[j];
            }
            cout << endl;
            a.pop();
        }
    }
    return 0;
}



