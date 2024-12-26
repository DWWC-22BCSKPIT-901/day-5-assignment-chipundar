#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int kthSmallestSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    auto cmp = [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
        return a.first > b.first; // Min-heap based on sum
    };

    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> minHeap(cmp);

    vector<int> indices(m, 0);
    int initialSum = 0;
    for (int i = 0; i < m; ++i) {
        initialSum += mat[i][0];
    }
    minHeap.push({initialSum, indices});

    int count = 0;

    while (!minHeap.empty()) {
        pair<int, vector<int>> topElement = minHeap.top();
        minHeap.pop();

        int currentSum = topElement.first;
        vector<int> currentIndices = topElement.second;

        count++;

        if (count == k) {
            return currentSum;
        }

        for (int i = 0; i < m; ++i) {
            if (currentIndices[i] + 1 < n) {
                vector<int> newIndices = currentIndices;
                newIndices[i]++;
                int newSum = currentSum - mat[i][currentIndices[i]] + mat[i][newIndices[i]];
                minHeap.push({newSum, newIndices});
            }
        }
    }

    return -1;
}

int main() {
    int m, n, k;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = kthSmallestSum(mat, k);
    cout << "The " << k << "th smallest array sum is: " << result << endl;

    return 0;
}
