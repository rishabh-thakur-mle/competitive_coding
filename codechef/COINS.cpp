#include<bits/stdc++.h>

#define ll long long

using namespace std;
int  p[100][2],j=0;
unsigned int cal(unsigned int m)
{
    unsigned int a,b,c,k;
    for(k=0;k<j;k++)
    {
        if(p[k][0]==m)
        return (p[k][1]);
    }
    if(m<12)
    return m;
    else
    {
        a=cal(m/2);
        b=cal(m/3);
        c=cal(m/4);
        p[j][0]=m;
        p[j][1]=(a+b+c);
        j++;
        return a+b+c;
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	int k; 
    while(cin>>k)
    {
        cout<<cal(k)<<endl;
    }    
}