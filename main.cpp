//
// Created by Manju Muralidharan on 10/19/25.
//
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "heap.h"
using namespace std;

// Global arrays for node information
const int MAX_NODES = 64;
int weightArr[MAX_NODES];
int leftArr[MAX_NODES];
int rightArr[MAX_NODES];
char charArr[MAX_NODES];

// Function prototypes
void buildFrequencyTable(int freq[], const string& filename);
int createLeafNodes(int freq[]);
int buildEncodingTree(int nextFree);
void generateCodes(int root, string codes[]);
void encodeMessage(const string& filename, string codes[]);

int main() {
    int freq[26] = {0};

    // Step 1: Read file and count letter frequencies
    buildFrequencyTable(freq, "input.txt");

    // Step 2: Create leaf nodes for each character with nonzero frequency
    int nextFree = createLeafNodes(freq);

    // Step 3: Build encoding tree using your heap
    int root = buildEncodingTree(nextFree);

    cout << "Heap implementation complete. Root node: " << root << endl;
    return 0;
}

/*------------------------------------------------------
    Function Definitions (Students will complete logic)
  ------------------------------------------------------*/

// Step 1: Read file and count frequencies
void buildFrequencyTable(int freq[], const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open " << filename << "\n";
        exit(1);
    }

    char ch;
    while (file.get(ch)) {
        // Convert uppercase to lowercase
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';

        // Count only lowercase letters
        if (ch >= 'a' && ch <= 'z')
            freq[ch - 'a']++;
    }
    file.close();

    cout << "Frequency table built successfully.\n";
}

// Step 2: Create leaf nodes for each character
int createLeafNodes(int freq[]) {
    int nextFree = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            charArr[nextFree] = 'a' + i;
            weightArr[nextFree] = freq[i];
            leftArr[nextFree] = -1;
            rightArr[nextFree] = -1;
            nextFree++;
        }
    }
    cout << "Created " << nextFree << " leaf nodes.\n";
    return nextFree;
}

// Step 3: Build the encoding tree using heap operations
int buildEncodingTree(int nextFree) {
    cout << "Building encoding tree with min heap...\n";

    // Create a MinHeap object
    MinHeap heap;

    // Push all leaf node indices into the heap
    for (int i = 0; i < nextFree; i++) {
        heap.push(i, weightArr);
    }

    int currentNode = nextFree; // Start new nodes after leaf nodes

    // While the heap size is greater than 1, combine nodes
    while (heap.size > 1) {
        // Pop two smallest nodes
        int leftIdx = heap.pop(weightArr);
        int rightIdx = heap.pop(weightArr);

        // Create a new parent node with combined weight
        weightArr[currentNode] = weightArr[leftIdx] + weightArr[rightIdx];
        leftArr[currentNode] = leftIdx;
        rightArr[currentNode] = rightIdx;
        charArr[currentNode] = '\0'; // Internal nodes don't have characters

        // Push new parent index back into the heap
        heap.push(currentNode, weightArr);

        currentNode++;
    }

    // Return the index of the last remaining node (root)
    return heap.pop(weightArr);
}

// Step 4: Use an STL stack to generate codes
void generateCodes(int root, string codes[]) {
    // TODO: Implement in future commit
    cout << "Code generation - to be implemented\n";
}

// Step 5: Print table and encoded message
void encodeMessage(const string& filename, string codes[]) {
    // TODO: Implement in future commit
    cout << "Message encoding - to be implemented\n";
}