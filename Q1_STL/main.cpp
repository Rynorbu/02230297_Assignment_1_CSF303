#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <numeric>   
#include <algorithm> 

using namespace std;

int main() {
    // Part A: Vector with N integers in reverse
    cout << "Part A: Vector (Reverse Order)" << endl;
    int N = 5; 
    vector<int> vec;

    for (int i = 1; i <= N; ++i) {
        vec.push_back(i * 10); 
    }

    cout << "Reversed vector: ";
    // Using reverse iterators for efficiency
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;


    cout << "Part B: Deque Operations" << endl;
    deque<int> dq;

    dq.push_back(90);  
    dq.push_front(38);  
    dq.push_back(75);  
    dq.pop_front();     

    cout << "Deque contents: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl << endl;


    // Part C: Fixed-size std::array and Sum
    cout << "Part C: Fixed-size Array Sum" << endl;
    // std::array requires a constant size at compile time
    array<int, 5> arr = {10, 4, 9, 16, 5};

    // Using std::accumulate from <numeric> for an efficient sum
    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    cout << "Array elements: ";
    for(int val : arr) cout << val << " ";
    cout << "\nSum of array: " << total_sum << endl;

    return 0;
}