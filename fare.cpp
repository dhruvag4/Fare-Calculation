#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

using namespace std;

const int INF = numeric_limits<int>::max();


// Dijkstra's algorithm to find shortest paths from source
void dijkstra(int src, const vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V = 10;
    vector<vector<pair<int, int>>> graph(V);

    // Make connections as per the given fares
    graph[0].push_back({1, 400});
    graph[0].push_back({7, 500});
    graph[1].push_back({0, 400});
    graph[1].push_back({7, 400});
    graph[1].push_back({2, 500});
    graph[2].push_back({1, 500});
    graph[2].push_back({8, 500});
    graph[2].push_back({5, 400});
    graph[2].push_back({1, 400});
    graph[8].push_back({2, 500});
    graph[8].push_back({6, 500});
    graph[6].push_back({8, 500});
    graph[6].push_back({5, 400});
    graph[5].push_back({2, 400});
    graph[5].push_back({6, 400});
    graph[5].push_back({4, 500});
    graph[4].push_back({3, 500});
    graph[4].push_back({5, 500});
    graph[3].push_back({4, 500});
    graph[3].push_back({5, 400});

    // Map place names to numbers
    unordered_map<string, int> place_to_num = {
        {"RajendraNagar", 0},
        {"Koti", 1},
        {"Dilsukhnagar", 2},
        {"Secunderabad", 3},
        {"Miyapur", 4},
        {"Kukatpally", 5},
        {"Gachibowli", 6},
        {"BanjaraHills", 7},
        {"JubileeHills", 8},
        {"HitechCity", 9}
    };


    string srcPlace, destPlace;
    cout << "Enter source place (e.g., RajendraNagar): ";
    cin >> srcPlace;
    cout << "Enter destination place (e.g., HitechCity): ";
    cin >> destPlace;

    int src = place_to_num[srcPlace];
    int dest = place_to_num[destPlace];

    vector<int> dist(V, INF);
    dijkstra(src, graph, dist);

    if (dist[dest] != INF) {
        cout << "The minimum fare from " << srcPlace << " to " << destPlace << " is " << dist[dest] << endl;
    } else {
        cout << "There is no path from " << srcPlace << " to " << destPlace << endl;
    }

    return 0;
}