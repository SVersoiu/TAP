#include <iostream>

#include <utility>

#include <algorithm>

#include <vector>



using namespace std;


bool compare(pair<float,float> a, pair <float,float> b)

{

    return a.second < b.second;

}



int main()

{

    int n;

    float x,y;

    vector<pair<float,float> > cuvinte, banda,aux;
;

    cin >> n;

    for(int i = 0;i < n;i++)

    {

        cin >> x >> y;

        cuvinte.push_back(make_pair(x,y));

        aux.push_back(make_pair(i,x/y));

    }

    sort(aux.begin(),aux.end(),compare);



    cout << endl;

    for(int i = 0;i < n;i++) cout << aux[i].first + 1 << " ";



    return 0;

}
