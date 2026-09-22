#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Edge {
    int to;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    vector<int> degree(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b, i});
        adj[b].push_back({a, i});

        degree[a]++;
        degree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<bool> used(m, false);
    vector<int> nextEdge(n + 1, 0);
    vector<int> circuit;
    stack<int> st;

    st.push(1);

    while (!st.empty()) {
        int current = st.top();

        while (nextEdge[current] < (int)adj[current].size() &&
               used[adj[current][nextEdge[current]].id]) {
            nextEdge[current]++;
        }

        if (nextEdge[current] == (int)adj[current].size()) {
            circuit.push_back(current);
            st.pop();
        } else {
            Edge e = adj[current][nextEdge[current]++];

            if (!used[e.id]) {
                used[e.id] = true;
                st.push(e.to);
            }
        }
    }

    if ((int)circuit.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(circuit.begin(), circuit.end());

    if (circuit.front() != 1 || circuit.back() != 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int v : circuit)
        cout << v << " ";

    cout << "\n";

    return 0;
}
