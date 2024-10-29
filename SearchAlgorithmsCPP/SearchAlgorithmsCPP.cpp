// SearchAlgorithmsCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//Depth First Search
void DFS(int currentNode, vector<vector<int>> graph, bool* visited) {
    visited[currentNode] = true;
    cout << currentNode << " ";
    for (int i = 0; i < graph[currentNode].size(); i++) {
        int child = graph[currentNode][i];
        if (!visited[child]) {
            DFS(child, graph, visited);
        }
    }
}

void BFS(int startNode, vector<vector<int>> graph, int nodes) {
    bool* visited = new bool[nodes + 1] {};
    queue<int> queueBFS;
    queueBFS.push(startNode);
    
    visited[startNode] = true;
    while (!queueBFS.empty()) {
        vector<int> children = graph[queueBFS.front()];
        cout << queueBFS.front() << " ";
        for (int i = 0; i < children.size(); i++) {
            int child = children[i];
            if (!visited[child]) {
                queueBFS.push(child);
                visited[child] = true;
            }
        }
        queueBFS.pop();
    }
}

//Linear Search
pair<int, int> linearSearch(int arr[], int size, int target) {
    int steps = 0;
    for (int i = 0; i < size; i++, steps++) {
        if (arr[i] = target) {
            return { steps, i };
        }
    }
    return { steps, -1 };
}
//Binary Search
pair<int, int> binarySearch(int arr[], int size, int target) {
    int steps = 0;
    int left = 0,
        right = size - 1,
        mid,
        i = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target > arr[mid]) {
            left = mid + 1;
        }
        else if (target < arr[mid]) {
            right = mid - 1;
        }
        else {
            return { steps, mid };
        }
        i++;
        steps++;
    }
    return { steps, -1 };
}


/*

BFS with a destination and adding a counter to count the steps
needed to reach the end node
The problem here is that introducing the steps increases the time complexity
from O(n^2) to O(n^3) because we have a loop with 2 nested loops inside
*/

void BFS_ReachGoal(int startNode, int endNode, vector<vector<int>> graph, int nodes) {
    bool* visited = new bool[nodes + 1] {};
    queue<int> queueBFS;
    queueBFS.push(startNode);

    visited[startNode] = true;
    int steps = 0;
    while (!queueBFS.empty()) {
        int levelSize = queueBFS.size();
        for (int i = 0; i < levelSize; i++) {
            int frontValue = queueBFS.front();
            queueBFS.pop();

            int frontValue = queueBFS.front();
            if (frontValue == endNode) {
                cout << "Steps: " << steps << endl;
                delete[] visited;
                return;
            }
            vector<int> children = graph[queueBFS.front()];
            cout << queueBFS.front() << " ";
            for (int i = 0; i < children.size(); i++) {
                int child = children[i];
                if (!visited[child]) {
                    queueBFS.push(child);
                    visited[child] = true;
                }
            }
        }

        steps++;
    }
    delete[] visited;
}

int main()
{
    int arr[] = { 1, 3, 5, 2, 6, 8, 10 };
    int size = 7;
    cout << linearSearch(arr, size, 10).second << endl;
    cout << binarySearch(arr, size, 10).second << endl;



    /*
        Let's create a graph
    */

    /*
    1   2
    1   4
    1   6
    2   3
    4   5
    5   6
    */

    int nodes, edges;
    cout << "Enter nodes and edges" << endl;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes+1);

    for (int i = 1; i <= edges; i++) {
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }
    bool* visited = new bool[nodes+1] {};

    /*
    DFS
    */
    cout << "=====================DFS===================" << endl;
    DFS(2, graph, visited);
    cout << endl << endl;
    /*
    BFS
    */
    cout << "=====================BFS===================" << endl;
    BFS(1, graph, nodes);
    cout << endl << endl;
}






