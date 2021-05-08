#include <iostream>  
#include <fstream>  
#include <stdio.h>
#include <stdlib.h>

#include "29_DivideTwoIntegers.h"

// static void getCoordinate(int* featureMap, float* pX, float* pY)
// {
//     int mapWidth = 64;  // 特征图的宽
//     int mapHeight = 64;  // 特征图的高
//     int k = 18;  // 取最大的K个值

//     float x[k];
//     float y[k];
//     float tmpscore[k];
//     float score[k];
//     int tmpindex[k];
//     int index[k];
//     memset(score,0,sizeof(float)*k);
//     memset(index,0,sizeof(int)*k);
//     float xSum = 0;  // K个x坐标值的加权和
//     float ySum = 0;  // K个y坐标值的加权和
//     float expSum = 0;  // softmax的分母

//     // 遍历特征图的数据, 插入优先队列, 筛选top_K个数据
//     for(int idx = 0; idx<mapHeight*mapWidth; idx++)
//     {

//         int index_loc=-1;
//         for(int j=0;j<k;j++)
//         {
//             if((featureMap[idx]>score[j]))
//             {
//                 index_loc=j;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         if(index_loc>=0)
//         {
//             for(int j=index_loc;j>0;j--)
//             {
//                 tmpscore[j-1]=score[j];
//                 tmpindex[j-1]=index[j];
//             }
//             for(int j=0;j<index_loc;j++)
//             {
//                 score[j]=tmpscore[j];
//                 index[j]=tmpindex[j];
//             }
//             score[index_loc]=featureMap[idx];
//             index[index_loc]=idx;

//         }

//     }

//     // 取数据(假设此时队列里就有K个元素)
//     for(int idx = 0; idx<k; idx++){
//         x[idx]=index[idx]%mapWidth;
//         y[idx]=index[idx]/mapWidth;
//         score[idx] = exp(static_cast<float>(score[idx])/4096.0);
//         expSum += score[idx];
//     }

//     // 求softmax, 求和
//     for(int idx = 0; idx<k; idx++){
//         float softmax = score[idx] / expSum;
//         xSum += x[idx] * softmax;
//         ySum += y[idx] * softmax;
//     }

//     *pX = xSum*4;
//     *pY = ySum*4;
//     return;
// }


int main(int argc,char** agrv){
    
    Solution29 s29;
    int result;

    result = s29.divide(10, 6);
    std::cout << result << std::endl;

    return 0;
}