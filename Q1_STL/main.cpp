#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <numeric>  
#include <algorithm> 

using namespace std;

int main() {
    const int N = 5; 
    vector<int> vec;

    vec.reserve(N); 

    for (int i = 1; i <= N; ++i) {
        vec.push_back(i * 10); 
    }

    cout << "Part A: Reversed vector: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";


    // Part B: Deque Operations
    deque<int> dq;
    dq.push_back(90);  
    dq.push_front(38);  
    dq.push_back(75);  
    dq.pop_front();     

    cout << "Part B: Deque contents: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << "\n\n";


    // Part C: Fixed-size Array Sum
    array<int, 5> arr = {10, 4, 9, 16, 5};

    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    cout << "Part C: Array sum: " << total_sum << endl;

    return 0;
}