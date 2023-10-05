class Dinic {
public:
    struct edge {
        int u, v, w;
    };
    int source, sink, n, inc = 0;
    vector<vector<int>> gr;
    vector<edge> edges;
    vector<int> edge_sz, level;
 
    Dinic(int n, int source, int sink) {
        this->n = n;
        this->source = source;
        this->sink = sink;
        gr.resize(n);
        edge_sz.resize(n);
    }
 
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
        gr[u].push_back(inc++);
        edges.push_back({v, u, 0});
        gr[v].push_back(inc++);
    }
 
    bool bfs() {
        level = vector<int>(n, -1);
        queue<int> q;
        q.push(source);
        level[source] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto child: gr[node]) {
                int v = edges[child].v;
                int w = edges[child].w;
                if (w && level[v] == -1) {
                    level[v] = level[node] + 1;
                    q.push(v);
                }
            }
        }
        return ~level[sink];
    }
 
    int bottleNeckFlowPath(int node, int flow) {
        if (node == sink)return flow;
        for (int &i = edge_sz[node]; i >= 0; --i) {
            int idxOfEdge = gr[node][i];
            int v = edges[idxOfEdge].v;
            int w = edges[idxOfEdge].w;
            if (w && level[v] == level[node] + 1) {
                int bottleNeck = bottleNeckFlowPath(v, min(flow, w));
                if (bottleNeck) {
                    edges[idxOfEdge].w -= bottleNeck;
                    edges[idxOfEdge ^ 1].w += bottleNeck;
                    return bottleNeck;
                }
            }
        }
        return 0;
    }
 
    ll getMaxFlow() {
        ll flow = 0;
        while (bfs()) {
            for (int i = 0; i < n; ++i)
                edge_sz[i] = gr[i].size() - 1;
            int curFlow = 1;
            while (curFlow) {
                curFlow = bottleNeckFlowPath(source, INT_MAX);
                flow += curFlow;
            }
        }
        return flow;
    }
};