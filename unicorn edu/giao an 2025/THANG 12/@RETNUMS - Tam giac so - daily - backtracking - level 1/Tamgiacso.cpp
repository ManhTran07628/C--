#include<bits/stdc++.h>
using namespace std;
int n,f, dx[15];
vector<int> a,c;
bool check()
{
    c.clear();
    for (auto x:a) c.push_back(x);
    c.push_back(0);
    for (int w=1; w<=n-1; w++)
     for (int i=0; i<n; i++)
        c[i] += c[i+1];
       // cout << c[0] << endl;
    return (c[0] == f ? 1 : 0);
}
void show()
{
    for ( auto x:a)
        cout << x << " ";
        cout << "\n";
}
void tamgiac(int k)
{
    dx[k] = 1;
    a.push_back(k);
   // show();
    for (int i=1; i<=n; i++)
         if (dx[i] == 0)
               tamgiac(i);
           if (a.size() == n){
               // show ();
                if (check()) {
                    show();
                    exit(0);
                }
            }
                dx[a.back()] = 0;
                a.pop_back();
}
int main()
{
    cin >> n >> f;
    memset(dx, 0, sizeof(dx));
    for (int i=1; i<=n; i++)
    tamgiac(i);
    return 0;
}