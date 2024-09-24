#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1000;

vector<vector<int>> g(N);
vector<int> tin(N), tout(N), tmin(N);
int t = 1;
vector<bool> used(N);
set<pair<int, int>> bridge;

void f(int v)
{
    used[v] = 1;
    tin[v] = t;
    tmin[v] = t;
    t++;

    for (auto j : g[v])
    {
        if (!used[j]) 
        {
            f(j);
            if (tin[v] < tmin[j])
            {
                bridge.insert({v, j});
            }
        }
        tmin[v] = min(tmin[v], tmin[j]);
    }
}

int main()
{

}