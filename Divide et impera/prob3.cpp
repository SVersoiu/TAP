#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <deque>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void varianta_1_hash()
{
	map<int, float> mp;
	vector<int> aux;
	ifstream fin("date.in");
	int n;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		fin >> x;
		mp[x] = 0;
		aux.push_back(x);
	}
	for (auto& i : aux)
	{
		float x;
		fin >> x;
		mp[i] = x;
	}
	float s = 0;
	for (auto it = mp.begin(); it != mp.end(); it++ )
		if ((s+ (*it).second) < 0.5)
		{

			s += (*it).second;
		}
		else
		{
			cout << (*(it)).first << endl;
			break;
		}
}

int poz(int p, int u, float *a){
	int i=p,
	j=u,
	depli=0,
	deplj=-1;
	while(i<j){
		if(a[i]>a[j]){
			int aux=a[i];
			a[i]=a[j];
			a[j]=aux;
			aux=depli;
			depli= -deplj;
			deplj= -aux;
		}
		i+=depli;j+=deplj;
	}
	return i;
}
int pozRand(int p,int u, float *a){
		srand(time(0));
		int r=rand()%(u-p+1)+p;
		float aux=a[r];
		a[r]=a[p];
		a[p]=aux;
		return poz(p,u,a);
}
int selKMin(int p, int u, float *a, int k){

	int m=pozRand(p,u,a);

	if(m==k-1) return a[m];
	if(m<k-1) return selKMin(m+1,u,a,k);
	return selKMin(p,m-1,a,k);
}
int selKMin(float *a, int n, int k){
	return selKMin(0,n-1,a,k);
}
int cmp(const void* a,const void* b)
{return (*(float*)b) - (*(float*)a); }

int varianta_2_KMin( ){
	int n,k,*x;
	float *a;
	ifstream f("date.in");
	f>>n;
	a=new float[n];
	x=new int[n];
	for(int i = 0;i<n;i++)
		f>>x[i];
	for(int i=0;i<n;i++)
		f>>a[i];
	f>>k;

	vector<float> mediane;
	for(int i = 0;i<n;i+=5)
	{
		if(i+5 < n)
		{
			float *temp = new float[5];
			for(int j = 0;j<5;j++)
				temp[j] = a[i + j];
			qsort(temp,5,sizeof(float),cmp);
			mediane.push_back(temp[2]);
		}
		else
		{
			float *temp = new float[n-i];
			for(int j = 0;j<n-i;j++)
				temp[j] = a[i + j];
			qsort(temp,n-i,sizeof(float),cmp);
			mediane.push_back(temp[(n-i)/2]);
		}
	}

	if(mediane.size() > 2)
	{
		float med = selKMin(mediane.data(),n/5,n/10);
		for(int i = 0;i<n;i++)
			if(a[i] == med)
			{
				cout<<x[i]<<endl;
				break;
			}
	}
	else
	{
		float med = mediane[1];
		for(int i = 0;i<n;i++)
			if(a[i] == med)
			{
				cout<<x[i]<<endl;
				break;
			}
	}

	int te;
	cin>>te;
}


int main()
{
	varianta_2_KMin();
	int ch;
	cin>>ch;
	return 0;
}
