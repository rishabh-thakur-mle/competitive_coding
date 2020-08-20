#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
 
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
 
 
using namespace std;
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    ll n,a,b,h;
	    vector<pair<int,int> >v;
	    scanf("%lld%lld",&n,&h);
	    for(int i=0;i<n;i++)
		{
		    scanf("%lld%lld",&a,&b);
		    v.pb(mp(a,b));
		}
		ll k=h-1;
		ll mn=numeric_limits<ll>::min();
		for(int i=0;i<=n-h;i++)
		{
		    ll cnt=0;
		    for(int j=0;j<n;j++)
		    {
		        if((v[j].f>k &&v[j].s>k)||(v[j].f<i &&v[j].s<i))
		        continue;
		        else if(v[j].f>=i && v[j].s<=k)
		        {
		            cnt+=v[j].s-v[j].f+1;
		        }
		        else if(v[j].f<=i &&v[j].s>=k)
		        {
		            cnt+=k-i+1;
		        }
		        else if(v[j].f<=i && v[j].s<=k && v[j].s>=i)
		        {
		            cnt+=v[j].s-i+1;
		        }
		        else if(v[j].f>=i && v[j].f<=k && v[j].s>=k)
		        {
		            cnt+=k-v[j].f+1;
		        }
		    }
		    if(cnt>=mn)
		    mn=cnt;
		    k++;
		}
		printf("%lld\n",(n*h)-mn);
	}
}  