#include <iostream>
#include <string>

using namespace std;

// Constants for manual array sizing (No STL containers allowed)
const int MAX_NODES = 20;
const int INF = 999999;

class RoadGraph {
private:
    int adjMatrix[MAX_NODES][MAX_NODES];
    string locationNames[MAX_NODES];
    int vertexCount;

public:
    // Constructor
    RoadGraph() {
        vertexCount = 0;
        for (int i = 0; i < MAX_NODES; i++) {
            locationNames[i] = "";
            for (int j = 0; j < MAX_NODES; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INF;
            }
        }
    }

    // 1. Add Location (Vertex)
    void addLocation(string name) {
        if (vertexCount >= MAX_NODES) {
            cout << "Error: Maximum node limit reached!\n";
            return;
        }
        locationNames[vertexCount++] = name;
        cout << "Location '" << name << "' added successfully at index " << (vertexCount - 1) << ".\n";
    }

    // 2. Add Road (Weighted Edge)
    void addRoad(int u, int v, int weight) {
        if (u < 0 || u >= vertexCount || v < 0 || v >= vertexCount) {
            cout << "Error: Invalid location indices!\n";
            return;
        }
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // Undirected graph for road network
        cout << "Road added between " << locationNames[u] << " and " << locationNames[v] << " with distance " << weight << ".\n";
    }

    // 3. Search Algorithm: Find location index by name
    int searchLocation(string name) {
        for (int i = 0; i < vertexCount; i++) {
            if (locationNames[i] == name) {
                return i;
            }
        }
        return -1;
    }

    // 4. Shortest Path Finder using Dijkstra's Algorithm
    void findShortestPath(int start, int dest) {
        int dist[MAX_NODES];
        bool visited[MAX_NODES];

        for (int i = 0; i < vertexCount; i++) {
            dist[i] = INF;
            visited[i] = false;
        }

        dist[start] = 0;

        for (int count = 0; count < vertexCount - 1; count++) {
            int u = -1, minDist = INF;
            
            // Find minimum distance unvisited node
            for (int i = 0; i < vertexCount; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1) break;
            visited[u] = true;

            // Update adjacent distances
            for (int v = 0; v < vertexCount; v++) {
                if (!visited[v] && adjMatrix[u][v] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        if (dist[dest] == INF) {
            cout << "No path found between " << locationNames[start] << " and " << locationNames[dest] << "!\n";
        } else {
            cout << "\n[Shortest Path Result]\n";
            cout << "Shortest Distance from " << locationNames[start] << " to " << locationNames[dest] << " is: " << dist[dest] << " units.\n";
        }
    }

    // 5. Graph Traversal - Breadth-First Search (BFS) using manual array queue
    void bfsTraversal(int startNode) {
        bool visited[MAX_NODES] = {false};
        int queue[MAX_NODES];
        int front = 0, rear = 0;

        visited[startNode] = true;
        queue[rear++] = startNode;

        cout << "\n[BFS Traversal]: ";
        while (front < rear) {
            int curr = queue[front++];
            cout << locationNames[curr] << " ";

            for (int i = 0; i < vertexCount; i++) {
                if (adjMatrix[curr][i] != INF && adjMatrix[curr][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }

    // Helper for DFS recursion
    void dfsUtil(int curr, bool visited[]) {
        visited[curr] = true;
        cout << locationNames[curr] << " ";

        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[curr][i] != INF && adjMatrix[curr][i] != 0 && !visited[i]) {
                dfsUtil(i, visited);
            }
        }
    }

    // 6. Graph Traversal - Depth-First Search (DFS)
    void dfsTraversal(int startNode) {
        bool visited[MAX_NODES] = {false};
        cout << "\n[DFS Traversal]: ";
        dfsUtil(startNode, visited);
        cout << endl;
    }

    // 7. Sorting Algorithm: Sort outgoing routes from a location using Bubble Sort
    void sortRoadsFromLocation(int nodeIdx) {
        if (nodeIdx < 0 || nodeIdx >= vertexCount) {
            cout << "Invalid location index!\n";
            return;
        }

        int weights[MAX_NODES];
        int targets[MAX_NODES];
        int count = 0;

        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[nodeIdx][i] != INF && adjMatrix[nodeIdx][i] != 0) {
                weights[count] = adjMatrix[nodeIdx][i];
                targets[count] = i;
                count++;
            }
        }

        // Bubble Sort implementation
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (weights[j] > weights[j+1]) {
                    int tempW = weights[j];
                    weights[j] = weights[j+1];
                    weights[j+1] = tempW;

                    int tempT = targets[j];
                    targets[j] = targets[j+1];
                    targets[j+1] = tempT;
                }
            }
        }

        cout << "\n[Sorted Routes from " << locationNames[nodeIdx] << " (Nearest to Farthest)]:\n";
        for (int i = 0; i < count; i++) {
            cout << " -> " << locationNames[targets[i]] << " (Distance: " << weights[i] << ")\n";
        }
    }

    // 8. Operator Overloading: Overloading '<<' to display graph status
    friend ostream& operator<<(ostream& out, const RoadGraph& g) {
        out << "\n========================================\n";
        out << "        ROAD NETWORK MAP OVERVIEW       \n";
        out << "========================================\n";
        out << "Total Registered Locations: " << g.vertexCount << "\n\n";
        out << "Location Index Mapping:\n";
        for (int i = 0; i < g.vertexCount; i++) {
            out << " [" << i << "] -> " << g.locationNames[i] << "\n";
        }
        out << "\nAdjacency Matrix (Distances):\n\t";
        for (int i = 0; i < g.vertexCount; i++) out << "[" << i << "]\t";
        out << "\n";

        for (int i = 0; i < g.vertexCount; i++) {
            out << "[" << i << "]\t";
            for (int j = 0; j < g.vertexCount; j++) {
                if (g.adjMatrix[i][j] == INF)
                    out << "INF\t";
                else
                    out << g.adjMatrix[i][j] << "\t";
            }
            out << "\n";
        }
        out << "========================================\n";
        return out;
    }

    int getVertexCount() { return vertexCount; }
};

// Main Menu-Driven Application Loop
int main() {
    RoadGraph map;
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "   SMART ROAD NETWORK & ROUTE FINDER    \n";
        cout << "========================================\n";
        cout << "1. Add Location (Vertex)\n";
        cout << "2. Add Route / Road (Weighted Edge)\n";
        cout << "3. Display Map (Operator Overloading <<)\n";
        cout << "4. Find Shortest Path (Dijkstra's Algorithm)\n";
        cout << "5. Graph Traversal (BFS)\n";
        cout << "6. Graph Traversal (DFS)\n";
        cout << "7. Search Location & Sort Routes\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                cout << "Enter location name (e.g., Library, Gate, Hostels): ";
                cin >> name;
                map.addLocation(name);
                break;
            }
            case 2: {
                if (map.getVertexCount() < 2) {
                    cout << "Please add at least 2 locations first!\n";
                    break;
                }
                int u, v, weight;
                cout << "Enter source index and destination index: ";
                cin >> u >> v;
                cout << "Enter route distance/weight: ";
                cin >> weight;
                map.addRoad(u, v, weight);
                break;
            }
            case 3: {
                // Uses overloaded insertion operator
                cout << map;
                break;
            }
            case 4: {
                if (map.getVertexCount() < 2) {
                    cout << "Not enough locations to find a path!\n";
                    break;
                }
                int start, dest;
                cout << "Enter start location index: ";
                cin >> start;
                cout << "Enter destination location index: ";
                cin >> dest;
                map.findShortestPath(start, dest);
                break;
            }
            case 5: {
                if (map.getVertexCount() == 0) {
                    cout << "Map is empty!\n";
                    break;
                }
                int start;
                cout << "Enter starting location index for BFS: ";
                cin >> start;
                map.bfsTraversal(start);
                break;
            }
            case 6: {
                if (map.getVertexCount() == 0) {
                    cout << "Map is empty!\n";
                    break;
                }
                int start;
                cout << "Enter starting location index for DFS: ";
                cin >> start;
                map.dfsTraversal(start);
                break;
            }
            case 7: {
                string query;
                cout << "Enter location name to search: ";
                cin >> query;
                int idx = map.searchLocation(query);
                if (idx != -1) {
                    cout << "Location found at index: " << idx << "\n";
                    map.sortRoadsFromLocation(idx);
                } else {
                    cout << "Location not found!\n";
                }
                break;
            }
            case 8:
                cout << "Exiting application. Good luck with your project evaluation!\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 1 to 8.\n";
        }
    } while (choice != 8);

    return 0;
}