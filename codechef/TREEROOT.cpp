#include<iostream>

using namespace std;

int main()
{
	int t,Id,sm;
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>Id>>sm;
			ans+=Id-sm;		
		}
		cout<<ans<<endl;
	}
}