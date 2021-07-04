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
ll l=20;
ll tt = 1;
ll tin[200005];
ll tout[200005];
ll anc[200005][20];
void dfs(ll x,vector<ll>adj[],ll p)
{
  tin[x]=tt++;
  anc[x][0]=p;
  for(ll j=1;j<l;j++)
  {
    anc[x][j]=anc[anc[x][j-1]][j-1];
  }
  for(auto i:adj[x])
  {
    if(i!=p)
    {
      dfs(i,adj,x);
    }
  }
  tout[x]=tt++;
}

bool isancestor(ll x,ll y)
{
  if(tin[x]<=tin[y] && tout[x]>=tout[y])
  return true;
  else
  return false;
}

void solve()
{
  ll n,q;cin>>n>>q;
  vector<ll>adj[n];
  for(ll i=0;i<n-1;i++)
  {
    ll x,y;cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(0,adj,0);

  while(q--)
  {
    ll a,b;cin>>a>>b;
    a-=1;
    b-=1;

    ll dist = 0;

    if(a==b)
    {
      dist=0;
    }
    else if(isancestor(a,b))
    {

      for(ll i=l-1;i>=0;i--)
      {
        if(!isancestor(anc[b][i],a))
        {
          dist+=(1<<i);
          b=anc[b][i];
        }
      }
      dist+=1;
    }
    else if(isancestor(b,a))
    {
      for(ll i=l-1;i>=0;i--)
      {
        if(!isancestor(anc[a][i],b))
        {
          dist+=(1<<i);
          a=anc[a][i];
        }
      }
      dist+=1;
    }
    else
    {
      ll ac = a;
      ll bc = b;
      for(ll i=l-1;i>=0;i--)
      {
        if(!isancestor(anc[a][i],b))
        {
          dist+=(1<<i);
          a=anc[a][i];
        }
      }
      dist+=1;

      a=ac;
      b=bc;

      for(ll i=l-1;i>=0;i--)
      {
        if(!isancestor(anc[b][i],a))
        {
          dist+=(1<<i);
          b=anc[b][i];
        }
      }
      dist+=1;

    }
    cout<<dist<<endl;
  }

}

int main()
{
  std::ios::sync_with_stdio(false);
  ll T=1;
  // cin>>T;
  // cin.ignore(); must be there when using getline(cin, s)
  while(T--)
  {
    solve();
  }


  return 0;
}
