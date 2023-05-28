// Hello1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int points_size = points.size();
        if (points_size <= 2)
            return points_size;
        // 构建hash表，使用unordered_map，我们需要一个二维的hash表
        // 使用index和斜率，两个维度
        auto first = points.begin();
        auto end = points.end();
        unordered_map<float, int> hash_map;
        unordered_map<int, int> hash_map_vertical; // 垂线单独处理
        unordered_map<int, int>hash_map_horiziontal; // 水平线单独处理
        int result = 0;
        for (int i = 0; i < points_size - 1; ++i)
        {
            if (result >= (points_size - i) || result > points_size / 2)
                break;
            hash_map.clear();
            hash_map_vertical.clear();
            hash_map_horiziontal.clear();
            for (int j = i + 1; j < points_size; ++j)
            {
                int delta_x = points[j][0] - points[i][0];
                int delta_y = points[j][1] - points[i][1];
                if (delta_y == 0)
                {
                    if (hash_map_horiziontal.find(points[j][1]) != hash_map_horiziontal.end())
                    {
                        int cur_result = hash_map_horiziontal[points[j][1]] + 1;
                        if (cur_result > result)
                            result = cur_result;
                        hash_map_horiziontal[points[j][1]] = cur_result;
                    }
                    else
                    {
                        hash_map_horiziontal.insert({ points[j][1] ,2 });
                        if (result < 2)
                            result = 2;
                    }
                }
                else if (delta_x == 0)
                {
                    if (hash_map_vertical.find(points[j][0]) != hash_map_vertical.end())
                    {
                        int cur_result = hash_map_vertical[points[j][0]] + 1;
                        if (cur_result > result)
                            result = cur_result;
                        hash_map_vertical[points[j][0]] = cur_result;
                    }
                    else
                    {
                        hash_map_vertical.insert({ points[j][0] ,2 });
                        if (result < 2)
                            result = 2;
                    }
                }
                else if (delta_x != 0)
                {
                    float k = float(delta_y) * 1.0 / float(delta_x);
                    if (hash_map.find(k) != hash_map.end())
                    {
                        // 找到了
                        int cur_result = hash_map[k] + 1;
                        if (cur_result > result)
                        {
                            result = cur_result;
                        }

                        hash_map[k] = cur_result;
                    }
                    else
                    {
                        hash_map.insert({ k, 2 });
                        if (result < 2)
                            result = 2;
                    }

                    //hash_map.insert({ k,2 });
                }
            }
        }
        return result;
    }
};

int main()
{
    

    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
