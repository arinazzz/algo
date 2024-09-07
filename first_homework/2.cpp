#include <iostream>
#include <vector>

using namespace std;

static bool findOddCycle1(int v, const vector<vector<int>> &adjList, vector<bool> &used)
{
    if (used[v] == 1 && v % 2 == 1) return true; 

    used[v] = true;
    if (v % 2 == 0) return false;

    bool fl = false;
    for (auto i : adjList[v])
    {
        fl = fl || findOddCycle1(i, adjList, used);
    }

    return fl;
}

bool findOddCycle(const vector<vector<int>> &adjList)
{
    vector<bool> used(adjList.size());

    for (int i = 1; i < adjList.size(); i++)
    {
        if (!used[i]) 
        {
            if (findOddCycle1(i, adjList, used)) return true;
        }
    }

    return false;
}