#include"order_statistics.hpp"

namespace {
    template<Comparable T>
        T randomisedSelect(std::vector<T> v, int low, int high, int order) {
            if(low == high) {
                return v[low];
            }
            int pivot = randomisedPartition(v, sorting::increasingOrder<T> , low, high);
            int index = pivot - low + 1;
            if(index == order) {
                return v[pivot];
            } else if(order < index) {
                return randomisedSelect(v, low, pivot - 1, order);
            } else {
                return randomisedSelect(v, pivot + 1, high, order - index);
            }
        }
}

template<Comparable T>
T maxVal(std::vector<T> v) {
    if(v.empty()) throw std::runtime_error("Empty vector");
    T max = v[0];
    for(const auto& val: v) {
        if(val > max) {
            max = val;
        }
    }
    return max;
}

template<Comparable T>
T minVal(std::vector<T> v) {
    if(v.empty()) throw std::runtime_error("Empty vector");
    T min = v[0];
    for(const auto& val: v){
        if(val < min) {
            min = val;
        }
    }
    return min;
}

template<Comparable T>
std::pair<T, T> minmaxVal(std::vector<T> v) {
    if(v.empty()) throw std::runtime_error("Empty vector");
    std::pair<T, T> minmax;
    int index = 0;
    if(v.size() % 2 == 0) {
        minmax = std::make_pair(v[v[0] >= v[1]], v[v[0] < v[1]]);
        index = 2;
    } else {
        minmax = std::make_pair(v[0], v[0]);
        index = 1;
    } 
    for(int i = index; i < v.size(); i += 2) {
        T localMin = v[(v[i] >= v[i+1]) + i];
        T localMax = v[(v[i] < v[i+1]) + i];
        if(localMax > minmax.second) 
            minmax.second = localMax;
        if(localMin < minmax.first) 
            minmax.first = localMin;
    }
    return minmax;
}

template<Comparable T>
T selectElement(std::vector<T> v, int order) {
    if(v.empty()) throw std::runtime_error("Empty vector");
    if(order > v.size() || order <= 0) throw std::out_of_range("Invalid order");
    return randomisedSelect(v, 0, v.size()-1, order);
}
