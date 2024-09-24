#include <iostream>
#include <vector>
#include <set>

using namespace std;

int t = 0;
vector<int> order, comp;
vector<bool> used;
vector<vector<int>> g, gt;

void dfs1(int v)
{
    used[v] = true;
    order.push_back(v);

    for (auto i : g[v])
    {
        if (!used[i]) dfs1(i);
    }
}

vector<vector<int>> gc(const vector<vector<int>> &sc, const vector<vector<int>> &adjList)
{
    vector<vector<int>> res(sc.size());
    set<pair<int, int>> x;
    vector<int> b(adjList.size());
    for (int i = 0; i < sc.size(); i++)
    {
        for (auto j : sc[i])
        {
            b[j] = i;
        }
    }

    for (int i = 0; i < b.size(); i++)
    {
        for (auto j : adjList[i])
        {
            x.insert({b[i], b[j]});
        }
    }

    for (auto y : x)
    {
        res[y.first].push_back(y.second);
    }

    return res;
}

void dfs2(int v)
{
    used[v] = true;
	comp.push_back (v);
	for (size_t i=0; i<gt[v].size(); ++i)
		if (!used[ gt[v][i] ])
			dfs2 (gt[v][i]);
}

vector<vector<int>> transp(const vector<vector<int>> &adjList, int n)
{
    vector<vector<int>> res(n+1);
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adjList[i])
        {
            res[j].push_back(i);
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n, m;

    g = vector<vector<int>> (n);
    gt = vector<vector<int>> (n);
    used = vector<bool> (n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i]) dfs1(i);
    }

    used.assign(n, false);
    for (int i = n-1; i >= 0; i--)
    {

    }

}