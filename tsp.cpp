#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// struct to store co-ordinates
struct coords {
    int x[100];
    int y[100];
};

int main(int argc, char* argv[]) {

    // check if there are enough command line arguments
    if (argc != 2) {
        cout << "Incorrect number of arguments. Please try again" << endl;
        exit(1);
    }

    // declare input & output streams
    ifstream f_input;
    ofstream f_output;

    struct coords coordinates;

    // open input file
    f_input.open(argv[1]);

    // store data from input file into info_input
    int info_input;
    f_input >> info_input;

    int temp_graph[100][100];

    for (int i = 0; i < info_input; ++i) {
        
    }

    


    return 0;
}
