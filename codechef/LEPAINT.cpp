#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c,K,a,b;
		cin>>n>>c>>K;
		long double ans=0;
		long double dp[51][51][101]={0};
		for(int i=1;i<=n;i++)
		{
			dp[0][i][1]=1;
		}
		for(int i=1;i<=K;i++)
		{
			cin>>a>>b;
			for(int j=1;j<=n;j++)
			{
			for(int k=0;k<c;k++)
				{
					if(j>=a && j<=b)
					{
					for(int m=0;m<c;m++)
					dp[i][j][(m*k)%c]+=dp[i-1][j][k]/(2*c);
					dp[i][j][k]+=dp[i-1][j][k]*.5;
					}
					else
					dp[i][j][k]+=dp[i-1][j][k];
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<c;j++)
			ans+=j*dp[K][i][j];
		cout<<fixed<<setprecision(9)<<ans<<endl;
	}
}