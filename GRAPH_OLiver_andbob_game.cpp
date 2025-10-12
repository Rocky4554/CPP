#include <bits\stdc++.h>
using namespace std;

int timer = 1;

// void resize(int v)
// {
//     inTime.resize(v+1);
//     outTime.resize(v+1);
// }

void dfs(int src, int parent, vector<int> g[], vector<int> &inTime,vector<int> &outTime)
{
    inTime[src] = timer++;
    for (auto i : g[src])
    {
        if (i != parent)
        {
            dfs(i, src, g,inTime,outTime);
        }
    }
    outTime[src] = timer++;
}

bool checkSubtree(int x, int y, vector<int> &inTime,vector<int> &outTime)
{
    if (inTime[x] > inTime[y] && outTime[x] < outTime[y])
    {
        return true;
    }
    return false;
}

int main()
{
    int v;
    cin >> v;

    timer = 1;
    // resize(v);

    vector<int> g[v + 1];
    for (int i = 0; i < v - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> inTime(v + 1);
    vector<int> outTime(v + 1);
    dfs(1, 0, g, inTime, outTime); // src , parent(parent is intially zero as first node will not have a parent) , graph

    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (!checkSubtree(x, y,inTime,outTime) && !checkSubtree(y, x,inTime,outTime))
        {
            cout << "no";
            continue;
        }

        if (type == 0)
        {
            if (checkSubtree(y, x,inTime,outTime))
                cout << "yes";
            else
                cout << "no";
        }
        else if (type == 1)
        {
            if (checkSubtree(x, y,inTime,outTime))
                cout << "yes";
            else
                cout << "no";
        }
    }

    return 0;
}
// 9
// 1 2
// 1 3
// 2 6
// 2 7
// 3 4
// 3 5
// 6 9
// 7 8
// 2
// 0 2 9