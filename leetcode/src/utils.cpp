#include "utils.h"

#include <stdio.h>
#include <queue>
#include <cmath>

float fast_exp(float y) {
    float d;
    *(reinterpret_cast<short*>(&d) + 0) = 0;
    *(reinterpret_cast<short*>(&d) + 1) = static_cast<int>(184 * y + 16256);
    return d;
}

struct Status{
    int val;
    int index;
    bool operator < (const Status &ref) const{
        return val > ref.val;
    }
    
    bool operator > (const Status &ref) const{
        return val < ref.val;
    }
    Status() : val(0), index(0) {}
    Status(int x, int n) : val(x), index(n) {}
};


void getCoordinate(int* featureMap, float* pX, float* pY){
    int mapWidth = 64;  // 特征图的宽
    int mapHeight = 64;  // 特征图的高
    int k = 18;  // 取最大的K个值

    float x[k];
    float y[k];
    float score[k];
    float xSum = 0;  // K个x坐标值的加权和
    float ySum = 0;  // K个y坐标值的加权和
    float expSum = 0;  // softmax的分母

    std::priority_queue<Status> q;  // 优先队列

    // 遍历特征图的数据, 插入优先队列, 筛选top_K个数据
    for(int index = 0; index<mapHeight*mapWidth; index++){
        q.push(Status(featureMap[index], index));

        // 维持优先队列的大小, 弹出队首元素(最小值)
        if(q.size()>k){
            q.pop();
        }
    }
    
    // 取数据(假设此时队列里就有K个元素)
    for(int idx = 0; idx<k; idx++){
        Status s = q.top();
        q.pop();

        x[idx] = s.index % mapWidth;
        y[idx] = s.index / mapWidth;

        // 当输入在(-10, 10)之间可用fast_exp, 不然就用标准函数exp()
        // score[idx] = fast_exp(static_cast<float>(s.val)/4096.0);
        score[idx] = exp(static_cast<float>(s.val)/4096.0);
        expSum += score[idx];
    }
    
    // 求softmax, 求和
    for(int idx = 0; idx<k; idx++){
        float softmax = score[idx] / expSum;
        xSum += x[idx] * softmax;
        ySum += y[idx] * softmax;
    }

    *pX = xSum;
    *pY = ySum;
    return;
}
