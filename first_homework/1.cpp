#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjMatrix_to_adjList(const vector<vector<int>> &adjMatrix)
{
    vector<vector<int>> adjList(adjMatrix.size());
    for (int i = 1; i < adjMatrix.size(); i++)
    {
        for(int j = 1; j < adjMatrix[i].size(); j++)
        {
            if (adjMatrix[i][j]) adjList[i].push_back(j);
        }
    }

    return adjList;
}

vector<vector<int>> adjList_to_adjMatrix(const vector<vector<int>> &adjList)
{
    vector<vector<int>> adjMatrix(adjList.size(), vector<int> (adjList.size()));
    for (int i = 1; i < adjList.size(); i++)
    {
        for (auto j : adjList[i])
        {
            adjMatrix[i][j] = 1;
        }
    }

    return adjMatrix;
}

vector<pair<int, int>> adjList_to_edgeList(const vector<vector<int>> &adjList)
{
    vector<pair<int, int>> edgeList;
    for (int i = 1; i < adjList.size(); i++)
    {
        for (auto j : adjList[i])
        {
            edgeList.push_back({i, j});
        }
    }

    return edgeList;
}

vector<pair<int, int>> adjMatrix_to_edgeList(const vector<vector<int>> &adjMatrix)
{
    vector<pair<int, int>> edgeList;
    for(int i = 1; i < adjMatrix.size(); i++)
    {
        for (int j = 1; j < adjMatrix[i].size(); j++)
        {
            if (adjMatrix[i][j]) edgeList.push_back({i, j});
        }
    }
    
    return edgeList;
}

vector<vector<int>> edgeList_to_adjList(const vector<pair<int, int>> &edgeList, int n)
{
    vector<vector<int>> adjList(n+1);
    for (auto edge : edgeList)
    {
        adjList[edge.first].push_back(edge.second);
    }

    return adjList;
}

vector<vector<int>> edgeList_to_adjMatrix(const vector<pair<int, int>> &edgeList, int n)
{
    vector<vector<int>> adjMatrix(n+1, vector<int> (n+1));
    for (auto edge : edgeList)
    {
        adjMatrix[edge.first][edge.second] = 1;
    }

    return adjMatrix;
}