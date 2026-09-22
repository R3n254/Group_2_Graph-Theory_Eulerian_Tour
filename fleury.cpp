#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    bool used;
};

int n, m;
vector<Edge> edges;
vector<vector<int>> adj;

int dfsCount(int v, vector<bool>& visited) {
    visited[v] = true;
    int count = 1;

    for (int id : adj[v]) {
        if (edges[id].used) continue;

        int next = (edges[id].u == v) ? edges[id].v : edges[id].u;

        if (!visited[next])
            count += dfsCount(next, visited);
    }

    return count;
}

bool isBridge(int v, int edgeId) {
    int available = 0;

    for (int id : adj[v])
        if (!edges[id].used)
            available++;

    if (available == 1)
        return false;

    vector<bool> beforeVisited(n + 1, false);
    int before = dfsCount(v, beforeVisited);

    edges[edgeId].used = true;

    vector<bool> afterVisited(n + 1, false);
    int after = dfsCount(v, afterVisited);

    edges[edgeId].used = false;

    return after < before;
}

vector<int> fleury(int start) {
    vector<int> path;
    int current = start;

    path.push_back(current);

    for (int i = 0; i < m; i++) {
        int chosen = -1;

        for (int id : adj[current]) {
            if (edges[id].used) continue;

            if (!isBridge(current, id)) {
                chosen = id;
                break;
            }

            if (chosen == -1)
                chosen = id;
        }

        if (chosen == -1)
            break;

        edges[chosen].used = true;

        current = (edges[chosen].u == current)
                      ? edges[chosen].v
                      : edges[chosen].u;

        path.push_back(current);
    }

    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        edges.push_back({a, b, false});
        adj[a].push_back(i);
        adj[b].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> path = fleury(1);

    if ((int)path.size() != m + 1 ||
        path.front() != 1 ||
        path.back() != 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int v : path)
        cout << v << " ";

    cout << "\n";
}
