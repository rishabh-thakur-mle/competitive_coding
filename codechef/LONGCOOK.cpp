#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
} 

bool checkYear(int year)  
{  
    if (year % 400 == 0)  
        return true;  
    if (year % 100 == 0)  
        return false;  
    if (year % 4 == 0)  
        return true;  
    return false;  
}
int main(){
	
	int modulo_array[400];
	int curr_ans = 0;
	for(int i=1;i<=400;i++)
	{
		if(checkYear(i))
			{
				if(dayofweek(2,2,i)==0)
					{
						curr_ans+= 1;
    				}
			}
			else
			{
				if(dayofweek(2,2,i)==1 || dayofweek(2,2,i)==0 )
					{
					curr_ans+= 1;
					}
    		}
        modulo_array[i-1]=curr_ans;
        //cout<<modulo_array[i-1]<<" ";
	}
	cout<<endl;
	int t;cin>>t;
	while(t--)
	{
		int m1,y1,m2,y2;
		cin>>m1>>y1;
		cin>>m2>>y2;
		if(m1>2)y1+=1;
		if(m2<2)y2-=1;
		int ans=0;
		if(checkYear(y1))
			{
				if(dayofweek(2,2,y1)==0)
					{
						ans+=1;
    				}
			}
		else
			{
				if(dayofweek(2,2,y1)==1 || dayofweek(2,2,y1)==0 )
					{
					    ans+=1;
					}
    		}
        int ans1 =0;
	    int ans2 =0;
		ans1 = ((y1-1)/400)*modulo_array[399] + modulo_array[(y1-1)%400];
    	ans2 = ((y2-1)/400)*modulo_array[399] + modulo_array[(y2-1)%400];
	    ans+=ans2-ans1;
	    cout<<ans<<endl;
	}

	return 0;
}