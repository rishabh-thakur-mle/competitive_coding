#include<iostream>

using namespace std;

int main()
{

int t,i;
char str[27],ar[101];

cin>>t>>str;
while(t>0)
{
	cin>>ar;
	for(i=0;ar[i]!='\0';i++)
	{
		if(ar[i]=='_')
		cout<<" ";
		else if((ar[i])>=65&&int(ar[i]<=90))
			{
				cout<<char(str[ar[i]-65]-32);
			}
		else if(ar[i]>=97&&ar[i]<=122)
		{
			cout<<str[ar[i]-97];
		}
		else
		{
			cout<<ar[i];
		}
	}
	t--;
}

	return 0;
}