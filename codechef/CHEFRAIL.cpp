#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
	lli t;
	cin>>t;
	while(t--)
	{
		lli n,m;
		cin>>n>>m;
		vector<lli>minus_y;
		vector<lli>plus_y;
		vector<lli>minus_x;
		vector<lli>plus_x;
		lli x_ent;
		lli y_ent;
		lli ans=0;
		lli count_x_zero=0;
		lli count_y_zero=0;
		int arr_x[100001] = {0};
		int arr_y[100001] = {0};
		for(lli i=0;i<n;i++)
		{
			cin>>x_ent;
			if(x_ent>0){
				plus_x.push_back(x_ent);
				arr_x[x_ent]++;
			    
			}
			else if(x_ent<0){
				minus_x.push_back(x_ent);
				arr_x[abs(x_ent)]++;}
				else
				count_x_zero++;
		}
		for(lli i=0;i<m;i++)
		{
			cin>>y_ent;
			if(y_ent>0){
				plus_y.push_back(y_ent);
				arr_y[y_ent]++;}
			else if(y_ent<0){
				minus_y.push_back(y_ent);
				arr_y[abs(y_ent)]++;}
				else count_y_zero++;
		}
		for(int i=0;i<minus_x.size();i++)
		{
			for(int j=0;j<plus_x.size();j++)
			{   
			    int prod = -1*(minus_x[i]*plus_x[j]);
			    if(double(sqrt(prod))-floor(sqrt(prod))==0)
				{
					ans+=arr_y[int(sqrt(prod))];
				
				}
			}
		}
		for(int i=0;i<minus_y.size();i++)
		{
			for(int j=0;j<plus_y.size();j++)
			{
			    int prod = -1*(minus_y[i]*plus_y[j]);
			    if(double(sqrt(prod))-floor(sqrt(prod))==0)
				{
					ans+=arr_x[int(sqrt(prod))];
					//cout<<arr_x[int(sqrt(minus_y[i]*plus_y[j]))]<<endl;
					
	
				}
			}
		}
		if(count_y_zero || count_x_zero)
		{
			ans+=(n-count_x_zero)*(m-count_y_zero);
		}
		cout<<ans<<endl;
	
} return 0;}
