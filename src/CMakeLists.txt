add_subdirectory(./Algorithms)
add_subdirectory(./Data_structures)
add_library(DSA INTERFACE)
target_link_libraries(DSA INTERFACE Algorithms Data_structures)
