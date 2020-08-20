#include<bits/stdc++.h>
 
using namespace std;
#define pb push_back
const int maxn=(int)1e5+10;
 
vector<int> g[maxn];
int p[18][maxn],lvl[maxn];
int in[maxn],out[maxn];
int w[maxn];
int T;
bool used[maxn];
 
void dfs(int v,int pr,int level)
{
	lvl[v]=level;
	p[0][v]=pr;
	for(int i=1;i<18;i++)
	{
		p[i][v]=p[i-1][p[i-1][v]];
	}
	in[v]=T++;
	for(int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if(to==pr)continue;
		dfs(to,v,level+1);
	}
	out[v]=T++;
}
 
bool upper(int x,int y)
{
	return in[x]<=in[y]&&out[y]<=out[x];
}
int lca(int x,int y)
{
	if(upper(x,y)) return x;
	if(upper(y,x)) return y;
	for(int i=17;i>=0;i--)
	{
		if(!upper(p[i][x],y))
		{
			x=p[i][x];
		}
	}
	return p[0][x];
}
 
void solve()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		g[i].clear();	
	}
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		--x;
		--y;
		g[x].pb(y);
		g[y].pb(x);
	}
	T=0;
	dfs(0,0,0);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&w[i]);
			--w[i];
			used[i]=false;
		}
		int root=w[0];
		for(int i=1;i<m;i++)
		{
			root=lca(root,w[i]);
		}
		int lo=0;
		for(int i=1;i<m;i++)
		{
			if(lvl[w[i]]>lvl[w[lo]])
			{
				lo=i;
			}
		}
		for(int i=0;i<m;i++)
		{
			if(upper(w[i],w[lo]))
			{
				used[i]=true;
			}
		}
		lo=w[lo];
		int mm=0;
		for(int i=0;i<m;i++) if(!used[i])
		{
			w[mm]=w[i];
			used[mm]=false;
			mm++;
		}
		m=mm;
		if(m==0)
		{
			puts("Yes");
			continue;
			
		}
		int lo2=0;
		for(int i=1;i<m;i++)
		{
			if(lvl[w[i]]>lvl[w[lo2]])
			{
				lo2=i;
			}
		}
		for(int i=0;i<m;i++)
		{
			if(upper(w[i],w[lo2]))
			{
				used[i]=true;
			}
		}
		lo2=w[lo2];
		bool good=true;
		good&=lca(lo,lo2)==root;
		for(int i=0;i<m;i++)if(!used[i])
		{
			good=false;
			break;
		}
		puts(good ?"Yes":"No");
	}
}
int main()
{
	int Case;
	cin>>Case;
	while(Case--)solve();
	return 0;
}