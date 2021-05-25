#include "divide_conquer.hpp"

/*
 * Find the max subarray of the form A[i..j] where j >= mid and i <= mid
 * The problem is divided to find two array of the form A[i..mid] and A[mid+1..j]
 * Returns a tuple consisting of the indices demarcating the subarray and the sum of the subarray
 */
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
static std::tuple<int, int, T> max_crossing_subarray(std::vector<T> v, int low, int mid, int high) {
    T left_sum = std::numeric_limits<T>::min();
    T sum = (T) 0;
    int max_left, max_right;
    for (int i = mid; i >= low; i--) {
        sum += v[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    T right_sum = std::numeric_limits<T>::min();
    sum = (T) 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += v[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }
    return std::make_tuple(max_left, max_right, left_sum + right_sum);
}

/*
 * Recursively calculate the max subarray
 * Check the following three cases :
 *  -> A[i..j]; i,j < mid
 *  -> A[i..mid]+A[mid+1..j]
 *  -> A[i..j]; i,j > mid
 */
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
static std::tuple<int, int, T> max_subarray_sum_recur(std::vector<T> v, int low, int high) {
    int left_low, left_high;
    int right_low, right_high;
    int cross_low, cross_high;
    T left_sum, right_sum, cross_sum;
    if (low == high) {
        return std::make_tuple(low, high, v[low]);
    } else {
        int mid = (low + high) / 2;
        std::tie(left_low, left_high, left_sum) = max_subarray_sum_recur(v, low, mid);
        std::tie(right_low, right_high, right_sum) = max_subarray_sum_recur(v, mid + 1, high);
        std::tie(cross_low, cross_high, cross_sum) = max_crossing_subarray(v, low, mid, high);
        if (left_sum >= right_sum && left_sum >= cross_sum)
            return std::make_tuple(left_low, left_high, left_sum);
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return std::make_tuple(right_low, right_high, right_sum);
        else
            return std::make_tuple(cross_low, cross_high, cross_sum);
    }
}

/*
 * Returns the tuple consisting of the indices demarcating
 * the subarray and the maximum sum
 */
template<typename T, typename>
std::tuple<int, int, T> max_subarray_sum(std::vector<T> v) {
    return max_subarray_sum_recur(v, 0, v.size() - 1);
}

/*
 * Faster implementation for the max_subarray_sum
 * returns just the maximum sum without the sub-array indices
 */
template <typename T, typename>
T max_subarray_sum_fast(std::vector<T> v) {
  T max = std::numeric_limits<T>::min();
  T sum = (T)0;
  for(const auto& elm: v) {
    sum = std::max(sum + elm, elm);
    max = std::max(sum, max);
  }
  return max;
}
