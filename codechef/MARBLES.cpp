#include<stdio.h>
 
int main()
{
    long long int t,k,n,i,ans;
    scanf("%lld",&t);
    while(t--)
    {
        ans=1ll;
        scanf("%lld%lld",&n,&k);
        n--;
        k--;
        if(k>n/2)
            k=n-k;
        for(i=1;i<=k;i++)
            ans=ans*(n+1-i)/i;
        printf("%lld\n",ans);
    }
    return 0;
}
 
 