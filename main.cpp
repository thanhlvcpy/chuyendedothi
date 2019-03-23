#include <bits/stdc++.h>

using namespace std;
//dfs
int a[10000][10000],n,s,d,t,trace[100000],m;
void dfs(int dinh)
{
	//cout<<dinh<<" ";    	// neeu thuc hien dong nay thi chuong trinh in ra cac dinh
							// cua do thi(if this is run, program will print button of tree)
	for(int v=1;v<=n;v++)
	if(a[dinh][v]==1&&trace[v]==0)
	{
		trace[v]=dinh;		// tu "dinh" co the den duoc dinh v(i can go to V from "dinh")
		if(v==t)
			return;
		dfs(v);
	}


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
		thuat toan tim duong di tu s den t nhung khong toi uu(khong phai duong di ngan nhat)
		giai thua dfs khong thich hop cho viec tiem duong di
	*/
	for(int i=1;i<=m;i++)
	{
		int k1,k2;
		cin>>k1>>k2;
		a[k1][k2]=1;
		a[k2][k1]=1;
		//cout<<k1<<" "<<k2<<endl;
	}
	trace[s]=-1;
	dfs(s);
	while(t!=s)
	{
		cout<<t<<" ";
		t=trace[t];		// truy vet : tra ve dinh ma tu dinh do ta den duoc t
						//return the button that i can go to button t
	}
	cout<<s;
    return 0;
}
