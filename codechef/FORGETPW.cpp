#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        bool flag=0;
        char arr[100];
        for(int i=0;i<100;i++)
        arr[i]=(char)(33+i);
        int n;
        char ci,pi;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ci>>pi;
            arr[ci-33]=pi;
        }
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(arr[s[i]-33]=='.')
            {
                flag=1;
            }
        }
        if(n!=0)
        for(int i=0;i<s.length();i++)
        {
          s[i]=arr[s[i]-33];   
        }
        int j=0;
        int l=s.length()-1;
        while(s[j]=='0')
        {
            j++;
        }
        if(flag)
        while(s[l]=='0')
        {
            l--;
        }
        if(s[l]=='.')
        l--;
        if(j>l)
        cout<<0;
        else
        for(int i=j;i<=l;i++)
        cout<<s[i];
        cout<<endl;
    }
}
