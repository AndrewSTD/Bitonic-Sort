#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// The parameter dir indicates the sorting direction, ASCENDING
// or DESCENDING; if (a[i] > a[j]) agrees with the direction,
// then a[i] and a[j] are interchanged.
void compAndSwap(vector<int>& a, int i, int j, int dir)
{
    if (dir == (a[i] > a[j]))
        swap(a[i], a[j]);
}

//It recursively sorts a bitonic sequence in ascending order,
//if dir = 1, and in descending order otherwise (means dir=0).
//The sequence to be sorted starts at index position low,
//the parameter cnt is the number of elements to be sorted.
void bitonicMerge(vector<int>& a, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            compAndSwap(a, i, i + k, dir);
        bitonicMerge(a, low, k, dir);
        bitonicMerge(a, low + k, k, dir);
    }
}

//  This function first produces a bitonic sequence by recursively
//  sorting its two halves in opposite sorting orders, and then
//  calls bitonicMerge to make them in the same order 
void bitonicSort(vector<int>& a, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        // sort in ascending order since dir here is 1
        bitonicSort(a, low, k, 1);

        // sort in descending order since dir here is 0
        bitonicSort(a, low + k, k, 0);

        // Will merge whole sequence in ascending order
        // since dir=1.
        bitonicMerge(a, low, cnt, dir);
    }
}

// Caller of bitonicSort for sorting the entire array of
// length N in ASCENDING order 
void sort(vector<int>& a, int N, int up)
{
    bitonicSort(a, 0, N, up);
}

// Driver code
int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> a;
    int n = 0;
    int x;

    ifstream fin("random_bench_2^24.txt");

    if (!fin) {
        cerr << "Could not open file\n";
        return 1;
    }


    while (fin >> x) {
        a.push_back(x);
        n++;
    }


    int up = 1;   // means sort in ascending order
    sort(a, n, up);

    ofstream fout("rezultat.txt", std::ofstream::trunc);
    if (fout.is_open()) {
        fout << "Sorted array: \n";
        for (int i = 0; i < n; i++)
            fout << a[i] << " \n";
    }
    fout.close();
    cout << "Data was uploaded to file rezultat.txt\n";
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "\nElapsed time: " << elapsed.count() << " seconds\n";

    return 0;
}