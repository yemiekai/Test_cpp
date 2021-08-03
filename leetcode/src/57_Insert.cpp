#include "57_Insert.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

// 57  插入区间
/*******************************************************************************************
给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

-------------------------------------------------------------------------------------------

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]

-------------------------------------------------------------------------------------------

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

-------------------------------------------------------------------------------------------

测试不过的用例:
输入：intervals = [[1,5]], newInterval = [2,3]
输入：intervals = [[1,5]], newInterval = [6,8]


*********************************************************************************************/
std::vector<std::vector<int>> Solution57::insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval){
        std::vector<std::vector<int>> result;
        std::vector<int> tmp(2);
        if(newInterval.size() == 0){
            return intervals;
        }

        if(intervals.size() == 0){
            result = intervals;
            result.push_back(newInterval);
            return result;
        }

        int left = newInterval[0];
        int right = newInterval[1];
        bool bPlaced = false;  // newInterval放进去没有

        /****************************************************************
         * 把item当做一个滑动窗口
         * 
         *          left  right
         *           [      ]
         * 1.                    [   ]      
         * 2.            [   ]            
         * 3.      [   ]
         * 4. [   ]         
         *            
         * **************************************************************/
        for(auto& item : intervals){
            
            if(right < item[0])  // newInterval在左边, 无交集, 则先把newInterval加入(加过就不用加了), 再把当前item加入
            {
                if(false == bPlaced){
                    tmp[0] = left;
                    tmp[1] = right;
                    result.push_back(tmp);
                    bPlaced = true;
                }
                result.push_back(item);
            }
            else if(left > item[1])  // newInterval在右边, 把item加入
            {
                result.push_back(item);  
            }
            else  // 处理交集
            {
                left = std::min(left, item[0]);
                right = std::max(right, item[1]);
            }
            
        }

        if(false == bPlaced){
            tmp[0] = left;
            tmp[1] = right;
            result.push_back(tmp);
        }

        return result;
}


void Solution57::test(){


}

