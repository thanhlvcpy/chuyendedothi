#include <bits/stdc++.h>

using namespace std;
struct toado
{
	int x,y;
};
const int maxn=1001;
toado robot,bomb;
toado que[1001],trace[1001][1001];
int dx[10]={0,-1,-1,-1,0,0,0,1,1,1};
int dy[10]={0,0,-1,1,-1,0,1,-1,0,1};
int a[1001][1001],n,m;
int d;
bool kt=false;
void bfs()
{
	int first=1,last=1;
	que[first].x=robot.x;
	que[first].y=robot.y;
	trace[robot.x][robot.y].x=-1;
	trace[robot.x][robot.y].y=-1;
	int fuck=1;
	while(first<=last)
	{
		int ux=que[first].x;
		int uy=que[first].y;
		first++;
		for(int i=1;i<=9;i++)
		{
			int toado1=ux+dx[i],toado2=uy+dy[i];
			if(trace[toado1][toado2].x==0&&trace[toado1][toado2].y==0&&a[toado1][toado2]==0&&toado1>0&&toado2>0)
			if(toado1<=m&&toado2<=n)
			{
				last++;
				que[last].x=toado1;
				que[last].y=toado2;
				trace[toado1][toado2].x=ux;
				trace[toado1][toado2].y=uy;
				d=last;
				//cout<<toado1<<" "<<toado2<<" "<<"fuck"<<endl;
				if(toado1==bomb.x&&toado2==bomb.y)
				{
					kt=true;
					return;
				}

			}
		}
	}


}
int main()
{
	freopen("ROBO.inp","r",stdin);
	//freopen("ROBO.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(trace,0,sizeof(trace));
    cin>>m>>n;
    cin>>robot.x>>robot.y>>bomb.x>>bomb.y;
    int x,y;
    while(cin>>x>>y)
		a[x][y]=1;
	bfs();
	if(kt==true)
	{
		int d=1;
		cout<<bomb.x<<" "<<bomb.y<<endl;
		while(bomb.x!=robot.x&&bomb.y!=robot.y)
		{
			int k1=bomb.x;
			int k2=bomb.y;
			bomb.x=trace[k1][k2].x;
			bomb.y=trace[k1][k2].y;
			cout<<bomb.x<<" "<<bomb.y<<endl;
			d++;
		}
		cout<<robot.x<<" "<<robot.y<<endl;
		cout<<d<<endl;
	}
	else
		cout<<-1;
	return 0;
}
