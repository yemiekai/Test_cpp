# Test_cpp
## 1. 哈希表
表的存储形式是**键值对**:`key->value`，C++ 中有各种map实现了这种结构：map，unorderd_map，hash_map。  
原本STL只提供了<map>，通常用红黑树实现。由于性能优势，使用面广，有许多第三方类库提供了支持，如MSVC中的<hash_map>和Boost中的<boost/unordered_map.hpp>，后来Boost的unordered_map被吸纳进了C++11标准。

### (1) 1.两数之和
题目描述：给你一个数组，要在数组中找到两个数`a`和`b`，相加等于`target`，返回`a`和`b`在数组中的索引。    

做法：遍历数组，假设当前遍历到的数是`x`，如果能在数组中找到 `target-x`，就成功了。  
把已经遍历过的数作为`key`加入哈希表，它的索引作为`value`。  
迭代遍历时在哈希表中查找`key`为`target-x`的值，如果找不到，说明没有匹配的，然后把当前元素`x`作为`key`加入哈希表继续迭代。