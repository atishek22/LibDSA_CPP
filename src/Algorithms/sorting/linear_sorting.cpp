#include"./linear_sorting.hpp"

namespace {

    template<std::integral T>
        std::vector<T> crSort(std::vector<T> v, long long m ,int maximum, int compareFlag) {
            std::vector<T> count;
            for(T i = 0; i <= maximum; i++) {
                count.push_back(0);
            }
            for(T i = 0; i < v.size(); i++) {
                auto index = (v[i] % m) * 10;
                index /= m;
                count[index]++;
            }
            if(compareFlag == linear_sorting::INCREASING_ORDER) {
                for(int i = 1; i <= maximum; i++)
                    count[i] += count[i-1];
            } else if(compareFlag == linear_sorting::DECREASING_ORDER) {
                for(int i = maximum-1; i >= 0; i--) 
                    count[i] += count[i+1];
            }
            std::vector<T> output(v.size());
            for(T i = v.size() - 1; i >= 0; i--) {
                auto index = (v[i] % m) * 10;
                index /= m;
                output[count[index]-1] = v[i];
                count[index]--;
            }
            return output;
        }
}

template<std::integral T>
std::vector<T> countingSort(std::vector<T> v, T maximum, int compareFlag) {
    std::vector<T> count;
    for(T i = 0; i <= maximum; i++) {
        count.push_back(0);
    }
    for(T i = 0; i < v.size(); i++) {
        count[v[i]]++;
    }
    if(compareFlag == linear_sorting::INCREASING_ORDER) {
        for(T i = 1; i <= maximum; i++)
            count[i] += count[i-1];
    } else if(compareFlag == linear_sorting::DECREASING_ORDER) {
        for(T i = maximum-1; i >= 0; i--) 
            count[i] += count[i+1];
    }
    std::vector<T> output(v.size());
    for(T i = v.size() - 1; i >= 0; i--) {
        output[count[v[i]]-1] = v[i];
        count[v[i]]--;
    }
    return output;
}

template<std::integral T>
std::vector<T> radixSort(std::vector<T> v, int digits, int maximum ,int compareFlag) {
    std::vector<T> output(v);
    long long m;
    for(int i = 1; i <= digits; i++) {
        m = pow(10, i);
        output = crSort(output, m, maximum, compareFlag);
    }
    return output;
}

template<std::floating_point T>
void normalise(std::vector<T> &v, std::function<T(T)> compute) {
    return;
}

template<std::floating_point T>
std::vector<T> bucketSort(std::vector<T> v, int compareFlag) {
    std::vector<std::vector<T>> buckets(v.size());
    std::vector<T> out;
    auto n = v.size();
    for(int i = 0; i < v.size(); i++) {
        int index = std::floor(n*v[i]);
        buckets[index].push_back(v[i]);
    }
    if(compareFlag == linear_sorting::INCREASING_ORDER){
        for(int i = 0; i < v.size(); i++) {
            insertionSort(buckets[i]);
        }
        for(auto b: buckets) {
            if(b.empty()) continue;
            for(auto val: b) {
                out.push_back(val);
            }
        }
    }
    else if(compareFlag == linear_sorting::DECREASING_ORDER) {
        for(int i = 0; i < v.size(); i++) {
            insertionSort(buckets[i], sorting::decreasingOrder<T>);
        }
        for(int i = buckets.size() - 1; i >= 0; i--) {
            if(buckets[i].empty()) continue;
            for(auto val: buckets[i]){
                out.push_back(val);
            }
        }
    }
    return out;
}
