# LeetCode Cpp

[![Travis Build Status][travis-image]][travis-url]

# Summary

## 数字翻转

Tips:

1. 需要考虑末尾为0的特殊情况
2. 需要考虑数字长度为奇数和偶数的不同情况
3. 需要考虑转换前数字的有效性
4. 需要考虑转换后数字的范围
5. 不能将转换后的数字做有效性判断，而应该在转换前


## 常见错误

### 类型转换
```c++
size_t i = 0;
i < s.size() - 1
```
当s.size() = 0时，这个就成立了。

所以应该改用
```c++
size_t i = 0;
i + 1< s.size()
```
或者将`s.size()`转换成`signed int`


[travis-url]: https://travis-ci.org/census-instrumentation/opencensus-cpp
[travis-url]: https://travis-ci.org/github/panzhongxian/leetcode-cpp

