#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(int k, const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) {
            return i + 1; 
        }
    }
    return -1; 
}

int main() {
    int n, k;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the element to search for: ";
    cin >> k;
    
    int result = findFirstOccurrence(k, arr);
    cout << "Position of first occurrence: " << result << endl;
    
    return 0;
}


