#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 105
int n,m;
int a[maxn][maxn];
vi mark(maxn);
int get_connected_component()
{
    mark.assign(n+1, 0);
    
}
void dfs(int cur,int prev = 0)
{

}
signed main()
{
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            a[u][v] = a[v][u] = 1;
        }
        
    }
}
