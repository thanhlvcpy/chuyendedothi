#include <bits/stdc++.h>

using namespace std;
int que[10000];
char s[10000][10000];
string s1;
int a[123];
int main()
{
	freopen("HTKITU.inp","r",stdin);
	freopen("HTKITU.out","w",stdout);
	int d=0;
	int maxx=-1;
	while(cin>>s1)
	{
		d++;
		for(int i=0;i<=s1.length()-1;i++)
			s[d][i+1]=s1[i];
		if(maxx<s1.length())
			maxx=s1.length();
	}
	cout<<maxx<<endl;
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=maxx;j++)
			cout<<s[i][j]<<" ";
		cout<<endl;
	}


	return 0;
}
