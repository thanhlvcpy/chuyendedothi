#include <bits/stdc++.h>

using namespace std;
//bfs
int a[10000][10000],que[10000],n,s,d;
bool duyetu[100000];
void bfs()
{
	duyetu[s]=false;
	int first=1,last=1;
	que[last]=s;
	while(first<=last)
	{
		int u=que[first];
		first++;
		for(int v=1;v<=n;v++)
			if(a[u][v]==1&&duyetu[v]==true)
			{
				duyetu[v]=false;
				last++;
				que[last]=v;
			}
	}
	d=last;
}
int main()
{
	freopen("bfs.inp","r",stdin);
	freopen("bfs.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(duyetu,true,sizeof(duyetu));
	cin>>n>>s;
	int k1,k2;
	while(cin>>k1>>k2)
	{
		a[k1][k2]=1;
		a[k2][k1]=1;
		//cout<<k1<<" "<<k2<<endl;
	}
	bfs();
	for(int i=1;i<=d;i++)
		cout<<que[i]<<" ";
    return 0;
}
