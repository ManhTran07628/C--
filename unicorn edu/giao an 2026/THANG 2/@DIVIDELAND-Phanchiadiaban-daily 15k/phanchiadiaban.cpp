#include<bits/stdc++.h>
using namespace std;
int n, a[100][100];
void show()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout << a[i][j] ;
        cout << "\n";
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++){
        char x;
        cin >> x;
        if (x == 'C') a[i][j] = 1;
         if (j==1) a[i][j] += a[i-1][n];
        else
         a[i][j] += a[i][j-1];
    }
    int k = a[n][n] / 2;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        if (a[i][j] <= k)
         cout << 1;
         else
            cout << 2;
      cout << "\n";
    }
    return 0;
}