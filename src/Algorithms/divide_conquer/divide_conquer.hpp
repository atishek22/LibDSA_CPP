#ifndef ALGORITHMS_DIVIDE_CONQUER_HPP
#define ALGORITHMS_DIVIDE_CONQUER_HPP

#include<bits/stdc++.h>

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
extern std::tuple<int, int, T> max_subarray_sum(std::vector<T>);

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
extern T max_subarray_sum_fast(std::vector<T>);

#endif //ALGORITHMS_DIVIDE_CONQUER_HPP
