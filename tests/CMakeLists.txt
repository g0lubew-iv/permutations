add_executable(permutation_test permutation_test.cpp)
target_link_libraries(permutation_test permutations doctest::doctest)
add_test(NAME test1 COMMAND permutation_test)
