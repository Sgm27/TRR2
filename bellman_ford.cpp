#include <bits/stdc++.h>

using namespace std;

int n,s,ke[1005][1005];
int D[1005], trace[1005];

void bellManFord()
{
    memset(trace, -1, sizeof trace);
    trace[s] = 0;
    for (int i=1; i<=n; i++) D[i] = INT_MAX;
    D[s] = 0;
    for (int T=1; T<n; T++)
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            {
                if (ke[i][j] == 0) continue;
                if (D[i] != INT_MAX && D[j] > D[i] + ke[i][j])
                {
                    D[j] = D[i] + ke[i][j];
                    trace[j] = i;
                }
            }
    }
}
void trace_path(int u)
{
    cout<<"K/c "<<s<<" -> "<<u<<" = ";
    if (trace[u] == -1)
    {
        cout<<"INF;\n";
        return;
    }
    if (u == s)
    {
        cout<<"0;   ";
        cout<<s<<" <- "<<s<<"\n";
        return;
    }
    cout<<D[u]<<";  ";
    vector<int> path;
    while (u != 0)
    {
        path.push_back(u);
        u = trace[u];
    }
    for (int i=0; i<path.size()-1; i++) cout<<path[i]<<" <- ";
    cout<<path.back()<<"\n";
}

int main()
{
    cin>>n>>s;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin>>ke[i][j];
    bellManFord();
    for (int i=1; i<=n; i++) trace_path(i);
}