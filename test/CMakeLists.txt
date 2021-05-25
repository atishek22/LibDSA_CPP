

#test exectables
#Algorithms
add_executable(sorting_test ./Algorithms/sorting/sorting_test.cpp)
target_link_libraries(sorting_test GTest::gtest GTest::gtest_main DSA)

#DataStructures
add_executable(dynamic_array_test ./Data_structures/dynamic_arrays/dynamic_arrays_test.cpp)
target_link_libraries(dynamic_array_test GTest::gtest GTest::gtest_main DSA)
