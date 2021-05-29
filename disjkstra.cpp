
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define pp pop_back

using namespace std;
priority_queue<pair<int,int>> pq;

void solve()
{
	int n,m;cin>>n>>m;
	int dist[n];
	vector<pair<int,int>>adj[n];
	for(int i=0;i<m;i++)
	{
		int x,y;int w;
		cin>>x>>y>>w;
		x-=1;
		y-=1;
		adj[x].pb({y,w});
		adj[y].pb({x,w});
	}
	mem(dist,10000);
	pq.push({0,0});
	dist[0]=0;


	while(!pq.empty())
	{
		int xdist,x;
		xdist = -pq.top().first;
		x = pq.top().second;
		pq.pop();
		for(auto &i: adj[x])
		{
			if(xdist + i.second < dist[i.first])
			{
				dist[i.first] = xdist +(i.second);
				pq.push({-dist[i.first],i.first});
			}
		}
	}
	for(int i=1;i<n;i++)cout<<dist[i]<<" ";
}

int main()
{
  std::ios::sync_with_stdio(false);
  int T=1;
  // cin>>T;
  // cin.ignore(); must be there when using getline(cin, s)
  while(T--)
  {
    solve();
  }


  return 0;
}
