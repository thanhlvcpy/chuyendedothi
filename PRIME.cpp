#include <bits/stdc++.h>

using namespace std;
const int maxn=10001;
bool kt[maxn];
int trace[maxn],que[maxn];
int n,m;
void kiemtranguyento()
{
	kt[1]=false;
	kt[2]=true;
	kt[3]=true;
	for(int i=1;i<=trunc(sqrt(maxn));i++)
		if(kt[i]==true)
		for(int j=2;j<=maxn/i;j++)
		kt[i*j]=false;
}
bool kenhau(int a,int b)
{
	string s1= to_string(a);
	string s2= to_string(b);
	int d=0;
	for(int i=0;i<=s1.length()-1;i++)
		if(s1[i]!=s2[i])
			d++;
	if(d==1)
		return true;
	else return false;
}
void bfs()
{
	int first=1,last=1;
	trace[n]=-1;
	que[first]=n;
	while(first<=last)
	{
		int u=que[first];
		first++;
		for(int v=1000;v<=m;v++)
			if(kt[v]==true&&trace[v]==0&&kenhau(u,v)==true)
			{
				last++;
				que[last]=v;
				trace[v]=u;
			}
	}
}
int main()
{
	freopen("PRIME.inp","r",stdin);
	freopen("PRIME.out","w",stdout);
	memset(kt,true,sizeof(kt));
	memset(trace,0,sizeof(trace));
	cin>>n>>m;
	kiemtranguyento();
	bfs();
	while(m!=n)
	{
		cout<<m<<" ";
		m=trace[m];
	}
	cout<<n;
	return 0;
}
