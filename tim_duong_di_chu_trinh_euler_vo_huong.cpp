#include<bits/stdc++.h>
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
int n,start;
int a[maxn][maxn];
int ke_vo_huong[maxn][maxn];
int deg[maxn];
int mark[maxn];
vector<pii> dfs_path;
vector<pii> adj[maxn];
int mark_edge[maxn];
void dfs(int u,int prev = 0)
{
    mark[u] = 1;
    dfs_path.push_back({u,prev});
    FOR(i,1,n)
        if (!mark[i] && ke_vo_huong[u][i]) dfs(i,u);
}
bool check_empty(vector<pii> x)
{
    int cnt = 0;
    for (auto it : x)
        if (mark_edge[it.second]) cnt++;
    return cnt == x.size();
}
void euler()
{
    stack<int> st;
    st.push(start);
    int step = 1;
    vi ce;
    cout<<"Buoc "<<step++<<"\n";
    cout<<"Stack = "<<st.top()<<"\n";
    cout<<"Canh da duyet = rong\n";
    cout<<"CE = rong\n"; 
    cout<<"--------------------\n";
    vector<pii> edges;
    while (!st.empty())
    {
        if (adj[st.top()].size() == 0)
        {
            stack<int> tmp = st;
            vi cur;
            cout<<"Buoc "<<step++<<"\n";
            while (tmp.size()) 
            {
                cur.push_back(tmp.top());
                tmp.pop();
            }
            reverse(ALL(cur));
            cout<<"Stack = ";
            for (int i : cur) cout<<i<<" "; cout<<"\n";
            cout<<"Canh da duyet = ";
            for (auto it : edges) cout<<"("<<it.first<<","<<it.second<<") ,"; cout<<"\n";
            while (st.size() && check_empty(adj[st.top()]))
            {
                ce.push_back(st.top());
                st.pop();
            }
            cout<<"CE = ";
            for (int i : ce) cout<<i<<" ";
            cout<<"\n--------------------\n";
            edges.clear();
        }
        else
        {
            int u = st.top();
            if (mark_edge[adj[u].back().second]) 
            {
                adj[u].pop_back();
                continue;
            }
            mark_edge[adj[u].back().second] = 1;
            edges.push_back({u, adj[u].back().first});
            st.push(adj[u].back().first);
            adj[u].pop_back();
        }
    }
    reverse(ALL(ce));
    cout<<"Chu trinh | duong di tim duoc la :\n";
    for (int i : ce)  cout<<i<<" ";
}
signed main()
{
    cin>>n>>start;
    int edge_idx = 0;
    FOR(i,1,n)
        FOR(j,1,n) 
        {
            char c; cin>>c;
            a[i][j] = c - '0';
            if (a[i][j] && i < j) 
            {
                a[j][i] = 1;
                edge_idx++;
                adj[i].push_back({j,edge_idx});
                adj[j].push_back({i,edge_idx});
                deg[i]++, deg[j]++;
            }
        }
    cout<<"deg = ";
    FOR(i,1,n) cout<<"{"<<i<<","<<deg[i]<<"},";
    cout<<"\n";
    FOR(i,1,n) 
        FOR(j,1,n)
            if (a[i][j])
            {
                ke_vo_huong[i][j] = 1;
                ke_vo_huong[j][i] = 1;
            }
    dfs(1);
    cout<<"dfs(1) = {";
    for (pii x : dfs_path) cout<<x.first<<" ("<<x.second<<") ; ";
    cout<<"}\n";
    cout<<"Tim duong di Euler & chu trinh Euler\n";
    FOR(i,1,n)
        if (deg[i] % 2 == 1) 
        {
            start = i;
            cout<<"Do thi da cho la nua Euler\n";
            break;
        }
    FOR(i,1,n) sort(ALL(adj[i]), greater<pii>());
    euler();
}
/*
    13 1
    0 1 0 0 0 1 0 0 0 0 0 0 0
    1 0 1 0 1 1 0 0 0 0 0 0 0 
    0 1 0 1 1 0 0 0 0 0 1 0 0
    0 0 1 0 0 0 1 1 0 0 1 0 0
    0 1 1 0 0 1 1 0 0 0 0 0 0
    1 1 0 0 1 0 1 0 0 0 0 0 0
    0 0 0 1 1 1 0 1 0 0 0 0 0
    0 0 0 1 0 0 1 0 1 1 0 0 0 
    0 0 0 0 0 0 0 1 0 1 0 1 1
    0 0 0 0 0 0 0 1 1 0 1 1 0
    0 0 1 1 0 0 0 0 0 1 0 1 0
    0 0 0 0 0 0 0 0 1 1 1 0 1
    0 0 0 0 0 0 0 0 1 0 0 1 0
*/