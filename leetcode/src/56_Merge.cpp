#include "56_Merge.h"
#include "math.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>


// 56  合并区间
/*****************************************************************

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].


输入：[[1,4],[0,4]]
输出：[[0,4]]

*******************************************************************/
std::vector<std::vector<int>> Solution56::merge(std::vector<std::vector<int>>& intervals){
        std::vector<std::vector<int>> result;
        std::vector<int> tmp(2);
        if(intervals.size()<=1){
            return intervals;
        }

        sort(intervals.begin(), intervals.end());  // 先排序

        std::vector<int> item = intervals[0];
        int left = item[0];
        int right = item[1];



        /****************************************************************
         * 有交集的情况:
         * 
         *        left  right
         *         [      ]
         *              [   ]      ------->  (right >= item[0] && right <= item[1])
         *       [   ]             ------->  (left >= item[0] && left <= item[1])
         *      [             ]
         *            [ ]          ------->  (left <= item[0] && right >= item[1])
         *            
         * **************************************************************/
        for(auto& item : intervals){
            // 先判断有没有交集
            if(    (right >= item[0] && right <= item[1])
                || (left >= item[0] && left <= item[1])
                || (left <= item[0] && right >= item[1]) )
            {
                left = std::min(left, item[0]);
                right = std::max(right, item[1]);
                continue;
            }
            
            
            tmp[0] = left;
            tmp[1] = right;
            result.push_back(tmp);

            left = item[0];
            right = item[1];
        }
        
        tmp[0] = left;
        tmp[1] = right;
        result.push_back(tmp);

        return result;
    }


void Solution56::test(){


}

