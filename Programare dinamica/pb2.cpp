#include <iostream>

using namespace std;

int n, m, a[102][102], d[102][102];
int main()

{
    cin>>n>>m;

    for( int i = 1; i <= n; i++)
        for( int j = 1; j<= m; j++)
            cin>>a[i][j];

    for( int i = n; i >= 1; i-- )
        for( int j = 1; j <= m; j++ )
            d[i][j] = max( d[i][j-1], d[i+1][j] ) + a[i][j];

        cout<<d[1][n]<<endl;

    int x = 1, y = n, mutari = 0, mx[101], my[101];
    mutari++;
    mx[mutari] = x;
    my[mutari] = y;

    while( x < n || y > 1 )
    {
        if( d[x][y-1] > d[x+1][y] )
            y--; else x++;

        mutari++;
        mx[mutari] = x;
        my[mutari] = y;
    }

    for ( int i=mutari; i>=1; i-- )
        cout << mx[i] << ' ' << my[i] << '\n';
}
