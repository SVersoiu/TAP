#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a,int b){return a < b;}

int main()

{

    int n,x,k;

    vector<int> Text;

    vector<int> Banda[100];



    cin >> n;

    cin >> k;

    for(int i = 0;i < n;i++)

    {

        cin >> x;

        Text.push_back(x);

    }

    int m = 0;

    sort(Text.begin(),Text.end(),compare);

    for(int i = 0;i < n;i++)

    {

        Banda[m].push_back(Text[i]);

        m++;

        m = m%k;

    }

    for(int i = 0;i < k;i++)

    {

        cout << i << ":";

        for(int m = 0;m < Banda[i].size();m++)

        {

            cout << Banda[i][m] << " ";

        }

        cout << endl;

    }

    return 0;

}
