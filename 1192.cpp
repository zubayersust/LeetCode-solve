/**
Online Judge : LeetCode
Problem No   : 1192
Problem Name : Critical Connections in a Network
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   :
CPU          : 0.560s
Memory       : 158.9MB
Algorithm    : Articulation Point/Bridge
*/

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>> result;
        vector<int> graph[n];
        int dis[n], low[n], parent[n];
        bool visited[n];
        int tim = 0;

        fill_n(dis, n, 0);
        fill_n(low, n, 0);
        fill_n(visited, n, false);
        fill_n(parent, n, -1);

        for(auto& conn : connections)
        {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        DFS(0, tim, dis, low, visited, parent, graph, result);

        return result;
    }
private:
    void DFS(int node, int tim, int dis[], int low[], bool visited[], int parent[], vector<int> graph[], vector<vector<int>>& result)
    {
        visited[node] = true;
        dis[node] = low[node] = ++tim;

        for (auto child : graph[node])
        {
            if (visited[child] == false)
            {
                parent[child] = node;
                DFS(child, tim, dis, low, visited, parent, graph, result);

                low[node] = min(low[node], low[child]);

                if (dis[node] < low[child])
                    result.push_back({node, child});
            }
            else if (parent[node] != child)
            {
                low[node] = min(low[node], dis[child]);
            }
        }
    }
};
