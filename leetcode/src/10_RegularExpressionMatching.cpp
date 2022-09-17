#include "10_RegularExpressionMatching.h"
#include "math.h"

/*******************************************
 * 
 * 10. 正则表达式匹配
 * 
 ********************************************/ 
bool Solution10::isMatch(std::string s, std::string p){
    int m = s.size();
    int n = p.size();
    this->m_s = s;
    this->m_p = p;

    std::vector<std::vector<int> > f(m+1, std::vector<int>(n+1));
    f[0][0] = true;
    for(int i=0; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(p[j-1] == '*')  // 因为 c++ 的数组索引是从 0 开始的, 所以这里减一才是实际要取的数据
            {  
                f[i][j] |= f[i][j-2];  // (这是匹配0个的情况)把*号前面一个字符连同*号一起删掉,

                if(this->bMatch(i, j-1))  // 这是匹配到1个(或多个)的情况
                {  
                    f[i][j] |= f[i-1][j];
                }
            }
            else
            {
                if(this->bMatch(i,j))
                {
                    f[i][j] |= f[i-1][j-1];
                }
            }
        }
    }
   
    return f[m][n];
}

bool Solution10::bMatch(int i, int j){
    if(i==0){
        return false;
    }

    if(this->m_p[j-1] == '.'){  // 这里下标要减一
        return true;
    }

    return this->m_s[i-1] == this->m_p[j-1];
}


void Solution10::test(){
    

}
