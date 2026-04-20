#include <iostream>
#include <vector>

using namespace std;

int countDivisibleSubsets(int n, vector<int>& nums, int k) {
    int count = 0;
    int totalSubsets = 1 << n; 

    for (int i = 0; i < totalSubsets; i++) {
        long long currentSum = 0;
        for (int j = 0; j < n; j++) {
            // Check if the j-th bit is set in mask i
            if ((i >> j) & 1) {
                currentSum += nums[j];
            }
        }
        // Check divisibility by K (handle sum 0 based on requirements)
        if (i > 0 && currentSum % k == 0) { 
            count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;

    cout << countDivisibleSubsets(n, nums, k) << endl;
    return 0;
}