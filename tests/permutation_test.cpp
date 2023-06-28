//
// Created by one_eyed_john on 27/06/23.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <permutations/permutation.hpp>
#include <doctest/doctest.h>

#include <vector>
#include <iostream>

using vint = std::vector<int>;

TEST_CASE("Test of constructors") {
    vint a1 = {3, 1, 2};
    Permutation<vint> f(a1.begin(), a1.end());

    vint a2 = {1, 2, 3, 4, 5};
    Permutation<vint> g(a2.begin(), a2.end());

    vint a_store = a2;
    Permutation<vint> m(g.Inverse(a_store.begin(), a_store.end()));
    std::cout << m;
}
