#include <iostream>
#include <vector>

using namespace std;

static void DFS(int v, const vector<vector<int>> &adjList, vector<bool> &used)
{
    if (used[v]) return;
    used[v] = true;

    for (auto i : adjList[v])
    {
        DFS(i, adjList, used);
    }
}

bool mutuallyAchieve(int u, int v, const vector<vector<int>> &adjList)
{
    vector<bool> used1(adjList.size()), used2(adjList.size());

    BFS(u, adjList, used1);
    BFS(v, adjList, used2);

    return used1[v] && used2[u];
}