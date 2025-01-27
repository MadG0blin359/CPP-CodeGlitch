#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to generate the next lexicographical permutation of a vector
bool next_permutation(vector<int>& arr) {
   int n = arr.size(), i = n - 2;

   // Find the first index 'i' such that arr[i] < arr[i+1] (rightmost ascent)
   while (i >= 0 && arr[i] >= arr[i + 1])
       i--;

   // If no such index exists, the permutation is the last one
   if (i < 0)
       return false;

   // Find the smallest element in the right of 'i' that is greater than arr[i]
   int j = n - 1;
   while (arr[j] <= arr[i])
       j--;

   // Swap arr[i] and arr[j]
   swap(arr[i], arr[j]);

   // Reverse the elements to the right of 'i' to get the next permutation
   reverse(arr.begin() + i + 1, arr.end());

   return true;
}

// Function to reverse a section of the vector from 'start' to the end
void reverse(vector<int>& arr, int start) {
   int end = arr.size() - 1;
   while (start < end) {
       swap(arr[start], arr[end]);
       start++;
       end--;
   }
}

// Function to solve the Travelling Salesman Problem (TSP) using permutations
void travellingSalesmanProblem(int graph[][4], int s, int size) {
   vector<int> vertex;
   for (int i = 0; i < size; i++)
       if (i != s)
           vertex.push_back(i);

   int min_path = INT_MAX;
   vector<int> min_route;

    // Generate all permutations of the cities to find the minimum path
   do {
       int current_weight = 0;
       int k = s;
       vector<int> current_route = { s };

       for (int i = 0; i < vertex.size(); i++) {
           current_weight += graph[k][vertex[i]];
           k = vertex[i];
           current_route.push_back(k);
       }

       current_weight += graph[k][s];
       current_route.push_back(s);

       if (current_weight < min_path) {
           min_path = current_weight;
           min_route = current_route;
       }

   } while (next_permutation(vertex));

   // Print the minimum path
   cout << "Minimum Path: ";
   for (int i = 0; i < min_route.size(); i++) {
       cout << char('A' + min_route[i]);
       if (i != min_route.size() - 1)
           cout << " -> ";
   }
   cout << endl;

   cout << "Minimum Cost: " << min_path << endl;
}

int main() {
    // Representation of the graph as a cost adjacency matrix
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0; // Starting city
    travellingSalesmanProblem(graph, start, 4);

    system("pause");
    return 0;
}