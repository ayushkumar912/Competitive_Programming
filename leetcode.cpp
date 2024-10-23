#include <iostream>
#include <vector>
#include "algo/debug.h"

using namespace std;



int main()
{
    Solution sol;
    vector<int> nums = {9, 10, 11, 21, 0, 1, 2}; // Example rotated sorted array
    int target = 11;

    int result = sol.search(nums, target);
    if (result != -1)
    {
        cout << "Target found at index: " << result << endl;
    }
    else
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
