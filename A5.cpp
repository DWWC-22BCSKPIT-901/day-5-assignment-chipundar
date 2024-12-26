#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is the smaller array
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    int totalLeft = (m + n + 1) / 2;

    while (left <= right) {
        int partition1 = left + (right - left) / 2;
        int partition2 = totalLeft - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        } else {
            left = partition1 + 1;
        }
    }

    throw invalid_argument("Input arrays are not sorted.");
}

int main() {
    int m, n;

    cout << "Enter the size of the first array: ";
    cin >> m;
    vector<int> nums1(m);
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> n;
    vector<int> nums2(n);
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "The median of the two sorted arrays is: " << median << endl;

  return 0;
}