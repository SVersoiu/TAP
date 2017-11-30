#include<fstream.h>
#include<string.h>

struct cub{
	    int l;
	    char c[20];
	  };
cub c[100];

int x[100],mx[100],max=0,n,m;
ifstream f("cub.in");

void citire()
{ int i;
  f>>n>>m;
  for(i=1;i<=n;i++) f>>c[i].l>>c[i].c;
}

void scriesol(int k)
{ int j;
  if(k>max) { max=k;
       for(j=1;j<=max;j++) mx[j]=x[j];
       }
  for(j=k;j>=1;j--)
    cout<<c[x[j]].l<<" "<<c[x[j]].c<<endl;
  cout<<endl;
}

int cond(int k)
{
  if(k>1)
     if(c[x[k-1]].l>c[x[k]].l)
	if(strcmp(c[x[k-1]].c,c[x[k]].c)!=0) return 1;
	else return 0;
     else return 0;
  else return 1;
}

void back(int k)
{
  int i;
  for(i=1;i<=n;i++)
   {
       x[k]=i;
       if (cond(k))
	    { if (k>=m) scriesol(k);
	      back(k+1);
	    }
   }
}

void main()
{
 citire();
 back(1);
 cout<<"Cel mai inalt turn:";
 for(int j=max;j>=1;j--)
    cout<<c[mx[j]].l<<" "<<c[mx[j]].c<<endl;
}
