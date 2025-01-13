/*

Author: 	Benoît de Keyn
Date: 		2021-09-30

This program is a path finder using the Dijkstra algorithm.

The program reads a CSV file containing the nodes and their distances.
The CSV file should be formatted as follows:
node1, node2, distance

example:
1, 2, 10
2, 3, 20
3, 4, 30

To use a certain CSV file, you must adapt the 4 definitions at the beginning of the program:
- CSV_LINES: the number of lines in the CSV file
- NODE_MAX_VALUE: the maximum value of a node
- PATH: the name of the CSV file
- BACKUP: the name of the binary file to save the graph (try to keep the same name as the CSV file)

The program will then calculate the shortest path between two nodes using the Dijkstra algorithm.
The program will output the total distance, the calculation time,
as well as the nodes' list of this path to a CSV file named "shortest_path.csv".

The program will also save the graph to a binary file for future use.

To be known:
If you enter -1 as the start node, the program will force to reload the graph from the CSV file.
It is able to detect if an invalid node is entered.
It is able to detect if there is no path between the two nodes.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;

/*#define CSV_LINES 28854312
#define NODE_MAX_VALUE 23947347
#define BACKUP "USA-roads.bin"
#define PATH "USA-roads.csv"*/

#define CSV_LINES 5
#define NODE_MAX_VALUE 91
#define BACKUP "list.bin"
#define PATH "list.csv"

// Alias for a pair of integers
using pii = pair<int, int>;

// Function to calculate then display the memory usage of the graph
void GraphMemoryUsage(const vector<vector<pii>>& graph) {
    size_t totalSize = 0;
    for (const auto& neighbors : graph) {
        totalSize += sizeof(neighbors) + (neighbors.size() * sizeof(pii));
    }

    // Adapt the division by 1024 acording to the size of the graph
    if (totalSize > 1024*1024) cout << "Memory used by the graph: " << totalSize/(1024*1024) << " MB" << endl;
    else if (totalSize > 1024) cout << "Memory used by the graph: " << totalSize/(1024) << " KB" << endl;
    else cout << "Memory used by the graph: " << totalSize << " Bytes" << endl;
}

// Function to format a number with spaces between each group of three digits
string formatWithSpaces(u_long number) {
    string numStr = to_string(number);
    int insertPosition = numStr.length() - 3;
    while (insertPosition > 0) {
        numStr.insert(insertPosition, " ");
        insertPosition -= 3;
    }
    return numStr;
}
string formatWithSpaces(int number) {
    string numStr = to_string(number);
    int insertPosition = numStr.length() - 3;
    while (insertPosition > 0) {
        numStr.insert(insertPosition, " ");
        insertPosition -= 3;
    }
    return numStr;
}

void dijkstra(int start, int end, const vector<vector<pii>>& graph, vector<int>& distance, vector<int>& prev) {

    int n = graph.size();
    distance.assign(n, numeric_limits<int>::max());
    prev.assign(n, -1);

    // Priority queue to store {distance, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distance[start] = 0;
    pq.push({0, start});

    int recursion = 0;

    while (!pq.empty()) {

        recursion++;
        cout << "\r" << recursion << flush;
        
        auto [dist, node] = pq.top();
        pq.pop();

        // Skip if this distance is not the latest
        if (dist > distance[node]) continue;

        for (auto [neighbor, weight] : graph[node]) {
            int newDist = dist + weight;

            if (newDist < distance[neighbor]) {
                distance[neighbor] = newDist;
                prev[neighbor] = node;
                pq.push({newDist, neighbor});
            }
        }
    }
}

vector<int> reconstructPath(int start, int end, const vector<int>& prev) {
    vector<int> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    if (path[0] == start) return path;
    return {}; // No path found
}

void savePathToCSV(const string& filename, const vector<int>& path, const vector<int>& distance, const string& time) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }

    file << "Nodes to go from " << path[0] << " to " << path[path.size() - 1] 
    << "\nShortest path : " << distance[path[path.size() - 1]] 
    << "\nCalculation time : " << time << " ms\n\n";

    int previous_distance = 0;
    for (int node : path) {
        file << node << ", " << distance[node] - previous_distance << "\n";
        previous_distance = distance[node];
    }

    file.close();
}

void saveGraphToBinary(const string& filename, const vector<vector<pii>>& graph) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }

    size_t size = graph.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& neighbors : graph) {
        size = neighbors.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(reinterpret_cast<const char*>(neighbors.data()), size * sizeof(pii));
    }

    file.close();
}

void loadGraphFromBinary(const string& filename, vector<vector<pii>>& graph) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "\nFailed to open the file for reading." << endl;
        return;
    }

    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    graph.resize(size);

    for (auto& neighbors : graph) {
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        neighbors.resize(size);
        file.read(reinterpret_cast<char*>(neighbors.data()), size * sizeof(pii));
    }

    file.close();
}

void loadGraph(vector<vector<pii>>& graph, bool force = false) {

    if (!force) {cout << "Loading the graph from the binary backup ..." << flush;}
    ifstream binaryFile(BACKUP, ios::binary);
    if (binaryFile.is_open() && !force) {
        binaryFile.close();
        loadGraphFromBinary(BACKUP, graph);
        cout << "Done !" << endl;
        // Calculate and display memory usage
        GraphMemoryUsage(graph);
        return;
    }

    if(!force){cout << "Any backup found" << endl;}

    // Load the CSV file in the graph
    fstream csv_map(PATH);

    unsigned int counter = 0;
    unsigned int progression = 0;
    unsigned int progression_backup = 0;

    string line;

    while (getline(csv_map, line)) {


        stringstream nodeString(line);
        string node_cell;
        vector<int> nodeData;
        while (getline(nodeString, node_cell, ',')) {
            nodeData.push_back(stoi(node_cell));
        }

        // CSV format is: node1, node2, distance
        if (nodeData.size() == 3) {
            int node1 = nodeData[0];
            int node2 = nodeData[1];
            int distance = nodeData[2];
            graph[node1].push_back({node2, distance});
            graph[node2].push_back({node1, distance});
        }

        counter++;
        progression = counter * 100 / CSV_LINES;
        if (progression != progression_backup) {
            cout << "\rLoading the CSV file into memory ... " << progression << " %" << flush;
            progression_backup = progression;
        }
    }

    csv_map.close();

    // Save the graph to a binary file for future use
    saveGraphToBinary(BACKUP, graph);
    cout << "\nGraph saved to binary backup." << endl;

    // Calculate and display memory usage
    GraphMemoryUsage(graph);
}


int main() {

    int start, end;                            // Example start and end
    vector<vector<pii>> graph(NODE_MAX_VALUE+1); // Graph is a vector of vectors of pairs of integers of size NODE_MAX_VALUE
    vector<int> distance, prev, path;          // Distance, previous node and path

    cout << "\nInitialization\n" << endl;

    // Load the graph from the CSV file or previous backup
    loadGraph(graph);

    // Main loop
    while (true) {

        cout << "\n\nEnter the start node: ";
        cin >> start;
        if (start == -1) {
            loadGraph(graph, true);
            continue; // Restart the loop
        }
        if (start < 0 || start >= graph.size() || graph[start].empty()) 
        {
            cout << "Invalid node. Please try again." << endl;
            continue;
        }
        cout << "Enter the end node: ";
        cin >> end;
        if (end < 0 || end >= graph.size() || graph[end].empty())
        {
            cout << "Invalid node. Please try again." << endl;
            continue;
        }

        cout << "\nCalculating the shortest path ...\n" << endl;
        // Measure the execution time
        auto start_time = chrono::high_resolution_clock::now();
        dijkstra(start, end, graph, distance, prev);
        auto end_time = chrono::high_resolution_clock::now();

        //Calculate the time
        u_long time_num = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
        string time = formatWithSpaces(time_num);

        // Calculate the path
        path = reconstructPath(start, end, prev);

        if (path.empty()) {
            cout << "No path found between node " << start << " and node " << end << "." << endl;
        } else {
            // Save the path nodes to a CSV file
            savePathToCSV("shortest_path.csv", path, distance, time);

            // Output results
            string totalDistance = formatWithSpaces(distance[end]);
            cout << "\nTotal Distance: " << totalDistance << endl;
            cout << "Calculation Time: " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms" << endl;
        }
    }

    return 0;
}
