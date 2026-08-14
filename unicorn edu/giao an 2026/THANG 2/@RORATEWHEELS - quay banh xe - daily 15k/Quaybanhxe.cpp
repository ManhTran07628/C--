#include <bits/stdc++.h>
using namespace std;
int n, s;
int main()
        {
            cin >> n;
            for (int i=1; i<n; i++)
            {
                int a,b,c;
                cin >> a >> b >> c;
                s += c;
            }
            cout << s%2;
            return 0;
    }