#include "gtest/gtest.h"
#include "../../../include/DSA.hpp"
#define SIZE 10000

/*
 * Unit Tests for the Sorting Algorithms
 */
class SortingTest : public ::testing::Test {
public:
    std::vector<int> IntegerVector{};
    std::vector<double> DoubleVector{};
    std::vector<std::string> StringVector{};
protected:
    void SetUp() override {
        // setting up random integer vector
        std::random_device rd;
        std::default_random_engine e(rd());
        std::uniform_int_distribution<> distInt(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        for (int i = 0; i < SIZE; i++) {
            IntegerVector.push_back(distInt(e));
        }
        //setting up the random Double vector
        std::uniform_real_distribution<> distDouble(std::numeric_limits<double>::min(),
                                                    std::numeric_limits<double>::max());
        for (int i = 0; i < SIZE; i++) {
            DoubleVector.push_back(distDouble(e));
        }
    }

    void TearDown() override {
        IntegerVector.clear();
        DoubleVector.clear();
        StringVector.clear();
    }
};

/* ========================================== Insertion Sort =========================================================*/

TEST_F(SortingTest, insertionSortIncreasingInteger) {
    insertionSort(IntegerVector, sorting::increasingOrder<int>);
    for (int i = 0; i < SIZE - 1; i++) {
        ASSERT_GE(IntegerVector[i + 1], IntegerVector[i]);
    }
}
TEST_F(SortingTest, insertionSortDecreasingInteger) {
    insertionSort(IntegerVector, sorting::decreasingOrder<int>);
    for (int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(IntegerVector[i + 1], IntegerVector[i]);
    }
}
TEST_F(SortingTest, insertionSortIncreasingDouble) {
    insertionSort(DoubleVector, sorting::increasingOrder<double>);
    for (int i = 0; i < SIZE - 1; i++) {
        ASSERT_GE(DoubleVector[i + 1], DoubleVector[i]);
    }
}

TEST_F(SortingTest, insertionSortDecreasingDouble) {
    insertionSort(DoubleVector, sorting::decreasingOrder<double>);
    for (int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(DoubleVector[i + 1], DoubleVector[i]);
    }
}

/* ============================================ Merge Sort =========================================================== */

TEST_F(SortingTest, mergeSortIncreasingInteger) {
    mergeSort(IntegerVector, sorting::increasingOrder<int>);
    for (int i = 0; i < SIZE - 1; i++) {
        ASSERT_GE(IntegerVector[i + 1], IntegerVector[i]);
    }
}
TEST_F(SortingTest, mergeSortDecreasingInteger) {
    mergeSort(IntegerVector, sorting::decreasingOrder<int>);
    for (int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(IntegerVector[i + 1], IntegerVector[i]);
    }
}
TEST_F(SortingTest, mergeSortIncreasingDouble) {
    mergeSort(DoubleVector, sorting::increasingOrder<double>);
    for (int i = 0; i < SIZE - 1; i++) {
        ASSERT_GE(DoubleVector[i + 1], DoubleVector[i]);
    }
}

TEST_F(SortingTest, mergeSortDecreasingDouble) {
    mergeSort(DoubleVector, sorting::decreasingOrder<double>);
    for (int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(DoubleVector[i + 1], DoubleVector[i]);
    }
}

/* ============================================= Heap Sort ========================================================= */

TEST_F(SortingTest, heapSortIncreasingInteger) {
    heapSort(IntegerVector, sorting::HEAP_INCREASING);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_GE(IntegerVector[i+1], IntegerVector[i]);
    }
}

TEST_F(SortingTest, heapSortDecreasingInteger) {
    heapSort(IntegerVector, sorting::HEAP_DECREASING);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(IntegerVector[i+1], IntegerVector[i]);
    }
}

TEST_F(SortingTest, heapSortIncreasingDouble) {
    heapSort(DoubleVector, sorting::HEAP_INCREASING);
    for(int i = 0;i < SIZE - 1; i++) {
        ASSERT_GE(DoubleVector[i+1], DoubleVector[i]);
    }
}

TEST_F(SortingTest, heapSortDecreasingDouble) {
    heapSort(DoubleVector, sorting::HEAP_DECREASING);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(DoubleVector[i+1], DoubleVector[i]);
    }
}

/* =========================================== Quick Sort ========================================================== */

TEST_F(SortingTest, quickSortIncreasingInteger) {
    quickSort(IntegerVector);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_GE(IntegerVector[i+1], IntegerVector[i]);
    }
}

TEST_F(SortingTest, quickSortDecreasingInteger) {
    quickSort(IntegerVector, sorting::decreasingOrder<int>);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(IntegerVector[i+1], IntegerVector[i]);
    }
}

TEST_F(SortingTest, quickSortIncreasingDouble) {
    quickSort(DoubleVector, sorting::increasingOrder<double>);
    for(int i = 0;i < SIZE - 1; i++) {
        ASSERT_GE(DoubleVector[i+1], DoubleVector[i]);
    }
}

TEST_F(SortingTest, quickSortDecreasingDouble) {
    quickSort(DoubleVector, sorting::decreasingOrder<double>);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(DoubleVector[i+1], DoubleVector[i]);
    }
}

/* =========================================== Randomised Quick Sort ========================================================== */

TEST_F(SortingTest, randomisedQuickSortIncreasingInteger) {
    randomisedQuickSort(IntegerVector);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_GE(IntegerVector[i+1], IntegerVector[i]);
    }
}

TEST_F(SortingTest, randomisedQuickSortDecreasingInteger) {
    randomisedQuickSort(IntegerVector, sorting::decreasingOrder<int>);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(IntegerVector[i+1], IntegerVector[i]);
    }
}

TEST_F(SortingTest, randomisedQuickSortIncreasingDouble) {
    randomisedQuickSort(DoubleVector, sorting::increasingOrder<double>);
    for(int i = 0;i < SIZE - 1; i++) {
        ASSERT_GE(DoubleVector[i+1], DoubleVector[i]);
    }
}

TEST_F(SortingTest, randomisedQuickSortDecreasingDouble) {
    randomisedQuickSort(DoubleVector, sorting::decreasingOrder<double>);
    for(int i = 0; i < SIZE - 1; i++) {
        ASSERT_LE(DoubleVector[i+1], DoubleVector[i]);
    }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

