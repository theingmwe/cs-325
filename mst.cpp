#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// declare struct to store coordinates
struct coordinates {
    int testcase;
    int x[100];
    int y[100];
};

void mst_func(int num_vertices, int temp_graph[20][20]);

int main() {

    // open "graph.txt" file
    ifstream f_input;
    f_input.open("graph.txt");

    // check to see if file was opened successfully
    if (f_input.fail()) {
        cout << "Could not open file.\n" << endl;
        exit(1);
    }
     
    coordinates coords;
    int num_vertices;

    // store test cases
    f_input >> coords.testcase;

    // loop until all test cases are done
    for (int i = 0; i < coords.testcase; ++i) {
        
        int num_testcase = i + 1;
        
        // store how many vertices there are in this test case
        f_input >> num_vertices;
        // declare array to store coordinates
        int temp_graph[20][20];

        // store coordinates
        for (int j = 0; j < num_vertices; ++j) {
            f_input >> coords.x[j] >> coords.y[j];
        }

        // loop through coordinates
        for (int a = 0; a < num_vertices; ++a) {
            for (int b = 0; b < num_vertices; ++b) {
                // determine weight of the vertex using formula that is provided
                double v_weight = sqrt(pow(coords.x[a] - coords.x[b], 2) + pow(coords.y[a] - coords.y[b], 2));
                int nearest = round(v_weight);
                temp_graph[a][b] = nearest;
            }
        }

        cout << "Test case " << num_testcase << ": ";
        
        mst_func(num_vertices, temp_graph);

        cout << endl;
    }


    return 0;
}

// code from https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/ was referenced
void mst_func(int num_vertices, int temp_graph[20][20]) {
    int namename[num_vertices];
    int dist[num_vertices];
    bool mst[num_vertices];

    for (int i = 0; i < num_vertices; ++i) {
        dist[i] = INT_MAX; // kind of like assigning it to infinity
        mst[i] = false;
    }

    dist[0] = 0;
    namename[0] = -1;

    for (int x = 0; x < (num_vertices - 1); ++x) {

        // find the shortest distance
        int temp_dist = INT_MAX;
        int l_weight;

        for (int y = 0; y < num_vertices; ++y) {
            if (mst[y] == false && (dist[y] < temp_dist)) {
               temp_dist = dist[y];
               l_weight = y;
            }
        }
    
        int temp = l_weight;
        mst[temp] = true;

        for (int a = 0; a < num_vertices; ++a) {
            if (temp_graph[temp][a] < dist[a] && temp_graph[temp][a] && mst[num_vertices] == false) {
                namename[a] = temp;
                dist[a] = temp_graph[temp][a];
            }
        }

    }

    // print vertex weights
    int weight_total = 0;

    for (int i = 1; i < num_vertices; ++i) {
        weight_total += temp_graph[i][namename[i]];
    }
    cout << "MST weight: " << weight_total << "\n";
}