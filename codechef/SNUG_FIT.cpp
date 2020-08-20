#include <bits/stdc++.h>


using namespace std;


int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> a,b;
		int ent;
		for(int i=0;i<n;i++)
		{
			cin>>ent;
			a.push_back(ent);
		}
		for(int i=0;i<n;i++)
		{
			cin>>ent;
			b.push_back(ent);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		long long int ans =0;
		for(int i =0;i<n;i++)
		{
			if(a[i]<b[i]) ans+=a[i];
			else {ans+=b[i];}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}