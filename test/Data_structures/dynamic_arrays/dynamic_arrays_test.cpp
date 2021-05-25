#include "gtest/gtest.h"
#include "../../../include/Data_structures.hpp"

#define TEST_ARRAY_SIZE 10000

class DynamicArrayTest : public ::testing::Test {
public:
  DynamicArray<int> test;

  DynamicArrayTest() {
    test.clear();
  }
};

TEST_F(DynamicArrayTest, EmptyArray){
  ASSERT_EQ(test.isEmpty(),true);
  ASSERT_EQ(test.size(), 0);
}

TEST_F(DynamicArrayTest, Insertion){
  for(int i = 0; i < TEST_ARRAY_SIZE * 10; i++) {
    test.add(i);
    ASSERT_EQ(test.size(), i+1);
    ASSERT_EQ(test.isEmpty(), false);
    ASSERT_EQ(test.get(i), i);
  }
}

TEST_F(DynamicArrayTest, Deletion){
  for(int i = 0; i < TEST_ARRAY_SIZE; i++) {
    test.add(i);
  }
  int s = TEST_ARRAY_SIZE;
  for(int i = 0; i < TEST_ARRAY_SIZE - 1; i++ ) {
    test.remove(i);
    s--;
    ASSERT_EQ(test.get(0), i+1);
    ASSERT_EQ(test.size(), s);
  }
  test.removeAt(0);
  ASSERT_EQ(test.isEmpty(), true);
}

TEST_F(DynamicArrayTest, Contains){
  for(int i = 0; i < TEST_ARRAY_SIZE; i++) {
    test.add(i);
    ASSERT_EQ(test.contains(i), true);
  }
  for(int i = 0; i < TEST_ARRAY_SIZE; i++ ) {
    test.remove(i);
    ASSERT_EQ(test.contains(i), false);
  }
}

TEST_F(DynamicArrayTest, IndexOf){
  for(int i = 0; i < TEST_ARRAY_SIZE; i++) {
    test.add(i);
    ASSERT_EQ(test.indexOf(i), test.size() - 1);
    ASSERT_EQ(test.indexOf(i*2 + 1), -1);
  }
  test.clear();
  test.add(10);
  test.add(20);
  ASSERT_EQ(test.indexOf(10),0);
  ASSERT_EQ(test.indexOf(15),-1);
}

TEST_F(DynamicArrayTest, Clear){
  test.add(10);
  test.add(20);
  test.add(30);
  ASSERT_EQ(test.size(), 3);
  ASSERT_EQ(test.isEmpty(), false);
  test.clear();
  ASSERT_EQ(test.size(),0);
  ASSERT_EQ(test.isEmpty(),true);
}

TEST_F(DynamicArrayTest, GetterSetter){
  for(int i = 0 ;  i < TEST_ARRAY_SIZE; i++){
    test.add(i);
  }

  for(int i = 0 ; i < TEST_ARRAY_SIZE; i++){
    test.set(i, -i);
    ASSERT_EQ(test.get(i),-i);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
