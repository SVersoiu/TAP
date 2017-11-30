#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


bool compare(pair<int,int> a, pair<int,int > b)
    {
     return a.first > b.first;
    }


int main()

{

    vector<pair<int,int> > cuburi,turn;

    int i,n,x,y,k = 0, p;


    cin >> n >> p;


    for(i = 0;i < n;i++)

    {

        cin >> x ;

        cin >> y ;

        cuburi.push_back(make_pair(x,y));

    }

    sort(cuburi.begin(),cuburi.end(),compare);

    turn.push_back(cuburi[0]);

    for(i = 1;i < n;i++)

    {

        if(cuburi[i].second != turn[k].second)

        {

            turn.push_back(cuburi[i]);

            k++;

        }

    }



    cout << "H MAX = " << k + 1 << endl;

    for(int i = 0;i <= k;i++)

    {

        cout << turn[i].first << " " << turn[i].second << endl;

    }

    return 0;
}
