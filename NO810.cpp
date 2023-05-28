#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int size = nums.size();
        if (size % 2 == 0) {
            return true;
        }
        int xorsum = 0;
        for (int i = 0; i < size; ++i) {
            xorsum ^= nums[i];
        }
        return xorsum == 0;
    }
};

int main()
{
    Solution s;


    std::cout << "Hello World!\n";
}