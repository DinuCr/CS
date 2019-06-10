#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

ifstream f("amedie.in");
ofstream g("amedie.out");

inline int cmp ( int x, int y ) { return x<y; }

int r,val,p,l,c,n,m,nr,median,valmax,q;

int poz[100005],w[700005],left1[700005],right1[700005],a[806][806],v[700005];

void elimin ()
{
	int i;
	r=poz[a[l][c]];
	if (v[r+1]!=a[l][c]) poz[a[l][c]]=0;
				else poz[a[l][c]]++;
	
	left1[right1[r]]=left1[r];
	right1[left1[r]]=right1[r];
	
	if (nr%2==0)
		if (median>=r)
			median=right1[median];
	if (nr%2==1)
		if (median<=r)
			median=left1[median];		
	nr--;
}

void solve()
{
	int i,j;
	char op;
	nr=n*m;
	median=nr/2 + nr%2;
	for (;q;--q)
	{
		f>>op;
		if (op=='L')
		{
			f>>l;
			for(i=1;i<=m;i++)
				if (a[l][i]>-1)
				{
					c=i;
					elimin();
					a[l][c]=-1;
				}
		}
		if (op=='C')
		{
			f>>c;
			for(i=1;i<=n;i++)
				if (a[i][c]>-1)
				{
					l=i;
					elimin();
					a[l][c]=-1;
				}
		}
		if (op=='Q')
		{
			g<<v[median]<<endl;
		}
	}
}

void preproc()
{
	int i,j,ind;
	for (i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{	valmax=max(valmax,a[i][j]);
			w[a[i][j]]++; 
		}
	p=0;
	for (i=1;i<=valmax;i++)
		for (;w[i];w[i]--)
			v[++p]=i;  
	
	ind=1;
	for (i=1;i<=valmax;i++)
	{
		while (v[ind]<i)
			ind++;
		if (v[ind]==i)
			poz[i]=ind;  // poz , pozitia valorii val in vectoru v
	}

	for (i=1;i<=p;i++)
	{	
		left1[i]=i-1;
		right1[i]=i+1;
	}
}

void citire()
{
	int i,j;
	f>>n>>m>>q;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			f>>a[i][j];
}

int main ()
{
	citire();
	preproc();
	solve();
	f.close();
	g.close();
	return 0;
}
	