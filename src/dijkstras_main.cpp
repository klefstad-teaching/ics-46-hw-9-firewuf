#include "dijkstras.h"

int main() {
    Graph G;
    file_to_graph("src/largest.txt", G);
    vector<int> previous(G.size(), -1);
    vector<int> distances_from_src = dijkstra_shortest_path(G, 0, previous);
    vector<int> shortest_path = extract_shortest_path(distances_from_src, previous, 84);
    print_path(shortest_path, distances_from_src[2]);

    return 0;
}