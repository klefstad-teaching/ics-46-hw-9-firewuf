#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    previous[source] = source;
    vector<int> distances_from_src(G.size(), INF);
    distances_from_src[source] = 0;
    set<int> visited;
    priority_queue<Edge> next_vertex;

    int current_vertex = source;
    visited.insert(source);
    while (visited.size() < G.size()) {
        const vector<Edge> & edges_from_cv = G[current_vertex];

        for (Edge e: edges_from_cv) {
            if (visited.find(e.dst) == visited.end()) next_vertex.push(e);

            int new_distance_from_src_candidate = distances_from_src[current_vertex]+e.weight;
            if (new_distance_from_src_candidate < distances_from_src[e.dst]) {
                // if the new distance is less than the current distance
                distances_from_src[e.dst] = new_distance_from_src_candidate;
                previous[e.dst] = e.src;
            }
        }

        if (next_vertex.empty()) continue;
        current_vertex = next_vertex.top().dst;
        next_vertex.pop();
        visited.insert(current_vertex);
    }

    return distances_from_src;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> d = distances;

    vector<int> shortest_path;

    int current_vector = destination;
    while (previous[current_vector] != current_vector) {
        shortest_path.push_back(current_vector);

        current_vector = previous[current_vector];
    }
    shortest_path.push_back(current_vector);
    reverse(shortest_path.begin(), shortest_path.end());

    return shortest_path;
}

void print_path(const vector<int>& v, int total) {
    for (int vertex: v) {
        cout << vertex << ' ';
    }
    cout << endl << "Total cost is " << total << endl;
}