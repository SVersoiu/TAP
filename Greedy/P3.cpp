#include <iostream>

#include <vector>

#include <algorithm>

#include <utility>



struct activitate

{

    int t,p,ind;

}a,b;


bool compare(activitate a, activitate b) {return a.p > b.p;}



using namespace std;



int main()

{

    int n,timpmaxim = 0, k = 0;

    vector<activitate> activit;

    activitate sol[100];

    cin >> n;

    for(int i = 0;i < n;i++)

    {

        sol[i].t = 0;

        cin >> a.p;

        cin >> a.t;

        a.ind = i;

        activit.push_back(a);

        if(timpmaxim < a.t) timpmaxim = a.t;

    }

    sort(activit.begin(),activit.end(),compare);

    for(int i = 0;i < n;i++)

    {

        if(k == timpmaxim) break;

        int j = activit[i].t-1;

        while(j > -1)

        {

            if(sol[j].t == 0)

            {

                sol[j] = activit[i];

                j = -1;

                k++;

            }

            else j--;



        }



    }

    int prof = 0;

    for(int i = 0;i < timpmaxim;i++)

    {

        cout << sol[i].ind + 1 << " ";

        prof += sol[i].p;

    }

    cout << "\nPROFIT:" << prof;

    cout << endl;

    return 0;

}
