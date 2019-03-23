#include <bits/stdc++.h>

using namespace std;
//bfs
int a[10000][10000],que[10000],n,s,d,t,trace[100000],m;
void bfs()
{
	trace[s]=-1;
	int first=1,last=1;
	que[last]=s;
	while(first<=last)
	{
		int u=que[first];
		first++;
		for(int v=1;v<=n;v++)
			if(a[u][v]==1&&trace[v]==0)
			{
				//if(v==t)
					//return;
				trace[v]=u;
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
	memset(trace,0,sizeof(trace));
	cin>>n>>m>>s>>t;
	/*
		do thi co n dinh, m duong di
		thuat toan tim duong di tu s den t sao cho quang duong ngan nhat
	*/
	for(int i=1;i<=m;i++)
	{
		int k1,k2;
		cin>>k1>>k2;
		a[k1][k2]=1;
		a[k2][k1]=1;
		//cout<<k1<<" "<<k2<<endl;
	}

	bfs();
	while(t!=s)
	{
		cout<<t<<" ";
		t=trace[t];
	}
	cout<<s;
    return 0;
}
