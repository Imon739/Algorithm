#include<bits/stdc++.h>


using namespace std;

struct Node {
    int parent;
    int rank;
};


struct Edge {
    int src;
    int dst;
    int wt;
};


vector<Node> nodes;
vector<Edge> edges, mst;


int find(int v) {
    if (nodes[v].parent == -1)
        return v;
    return nodes[v].parent = find(nodes[v].parent);
}


void union_op(int from, int to) {
    if (nodes[from].rank > nodes[to].rank) {
        nodes[to].parent = from;
    } else if (nodes[from].rank < nodes[to].rank) {
        nodes[from].parent = to;
    } else {
        nodes[to].parent = from;
        nodes[from].rank++;
    }
}


bool compare(Edge a, Edge b) {
    return a.wt < b.wt;
}


void Kruskals(int V, int E) {
    sort(edges.begin(), edges.end(), compare);

    int i = 0, j = 0;
    while (i < V - 1 && j < E) {
        int from = find(edges[j].src);
        int to = find(edges[j].dst);

        if (from != to) {
            union_op(from, to);
            mst.push_back(edges[j]);
            i++;
        }
        j++;
    }
}


void printMST() {
    cout << "MST formed is:\n";
    for (auto& p : mst) {
        cout << "src: " << p.src << " dst: " << p.dst << " wt: " << p.wt << "\n";
    }
}


int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    nodes.resize(V);

    for (int i = 0; i < V; ++i) {
        nodes[i].parent = -1;
        nodes[i].rank = 0;
    }

    for (int i = 0; i < E; ++i) {
        Edge temp;
        cout << "Enter from, to, weight: ";
        cin >> temp.src >> temp.dst >> temp.wt;
        edges.push_back(temp);
    }

    Kruskals(V, E);
    printMST();

    return 0;
}
