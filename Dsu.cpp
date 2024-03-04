class DisjointSet {
public:
    vector<int> rank, parent, size;
    long long no;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        no = n;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        no--;
    }

    void add(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        no--;
    }
    /* little error but can  understand*/ 
    void printComponents() {
        vector<vector<int>> components;
        vector<bool> visited(parent.size(), false);
        for (int i = 1; i < parent.size(); i++) {
            if (!visited[i]) {
                vector<int> component;
                int root = findUPar(i);
                for (int j = 1; j < parent.size(); j++) {
                    if (findUPar(j) == root) {
                        component.push_back(j);
                        visited[j] = true;
                    }
                }
                components.push_back(component);
            }
        }

        for (const auto& component : components) {
            cout << "Component: ";
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

