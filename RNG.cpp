#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

// function to generate n random numbers in the range [0, max_val]
void generateRandomNumbers(int n, int max_val, string filename) {
    ofstream fout(filename);

    for (int i = 0; i < n; i++) {
        fout << rand() % (max_val + 1) << "\n";
    }

    fout.close();
}

// function to generate n ascending numbers starting from 0
void generateAscendingNumbers(int n, string filename) {
    ofstream fout(filename);

    for (int i = 0; i < n; i++) {
        fout << i << "\n";
    }

    fout.close();
}

// function to generate n descending numbers starting from max_val
void generateDescendingNumbers(int n, int max_val, string filename) {
    ofstream fout(filename);

    for (int i = 0; i < n; i++) {
        fout << max_val - i << "\n";
    }

    fout.close();
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    int n = 10000; // number of numbers to generate
    int max_val = 100000000; // maximum value for random numbers
    int option;
    cout << "1.Generate random numbers and save them in a text file\n2.Generate ascending numbers and save them in a text file\n3.generate descending numbers and save them in a text file\nYour option is: ";
    cin >> option;
    switch (option)
    {
    case 1:
        generateRandomNumbers(n, max_val, "random.txt");
        break;
    case 2:
        generateAscendingNumbers(n, "ascending.txt");
        break;
    case 3:
        generateDescendingNumbers(n, max_val, "descending.txt");
        break;
    default:
        break;
    }


    return 0;
}