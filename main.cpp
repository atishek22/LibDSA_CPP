#include<bits/stdc++.h>
#include "./include/DSA.hpp"

/**
 *
 * The main file 
 * Linked to the data structures and algorithms library
 */

int main() {
    srand(0);
    std::vector<float> v;
    for(int i = 0; i < 20; i++){
        float val = rand()%100;
        val /= 100;
        v.push_back(val);
    }
    std::vector<std::string> s{"aaa", "aa", "abab", "bbb", "abc", "a", "c" };

    std::cout << maxVal(s) << " " << minVal(s) << "\n";
    auto ret = minmaxVal(s);
    std::cout << ret.first << " " << ret.second << "\n";

    std::cout << selectElement(s, 7);

    std::vector<int> v3;


//    for(int i = 0; i < out.size(); i++) {
//        std::cout << out[i] << " ";
//    }
    std::cout << "\n";
    return 0;
}
