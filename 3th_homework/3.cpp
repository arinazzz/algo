#include <iostream>
#include <vector>

using namespace std;

int countComp(const vector<vector<int>> &adjList)
{
    vector<bool> used(adjList.size());

    auto f = [&] (int v) {
        used[v] = 1;

        for (auto i : adjList[v])
        {
            if (!used[i]) f(i);
        }
    
    };

    int cnt = 0;

    for (auto i : adjList)
    {
        for (auto j : i)
        {
            if (!used[j]) f(j), cnt++;
        }
    }

    return cnt;
}


int main()
{

}