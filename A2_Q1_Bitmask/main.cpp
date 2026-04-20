#include <iostream>
#include <vector>

using namespace std;

int countDivisibleSubsets(int n, vector<int>& nums, int k) {
    int count = 0;

    int totalSubsets = (1 << n); 

    for (int mask = 0; mask < totalSubsets; mask++) {
        long long currentSum = 0;

        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                currentSum += nums[i];
            }
        }

        if (mask > 0 && currentSum % k == 0) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n, k;
    
    cout << "Enter size of set (n): ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter divisor (k): ";
    cin >> k;

    int result = countDivisibleSubsets(n, nums, k);
    cout << "Number of subsets divisible by " << k << ": " << result << endl;

    return 0;
}