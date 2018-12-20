
#include "randomized_binary_search_tree.hpp"

#define ONLY_TIME

#include <iostream>
#include <chrono>

int main() {
    RandomizedBinarySearchTree<int> rbst;
    
    int removal_value;
    std::cout << "removal value: ";
    std::cin >> removal_value;

    std::cout << "inserted values: ";
    while (!std::cin.eof()) {
        if (std::cin.fail()) {
            std::cout << "you entered not a number, sorry" << std::endl;
            return EXIT_FAILURE;
        }
        int inserted_value;
        std::cin >> inserted_value;
        rbst.insert(inserted_value);
    }
    
#ifndef ONLY_TIME
    std::cout << "tree before removal: " << std::endl;
    std::cout << "values: ";
    rbst.display_like_list();
    std::cout << "tree shape: " << std::endl;
    rbst.display_like_tree();
    std::cout << std::endl;
#endif

#ifdef DETAILEDEXPLANATION
    std::cout << "removal process: " << std::endl;
#endif

    auto begin = std::chrono::steady_clock::now();
    rbst.remove(removal_value);
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "removal time: " << elapsed_ms.count() << " ns." << std::endl;

#ifndef ONLY_TIME
    std::cout << "tree after removal: " << std::endl;
    std::cout << "values: ";
    rbst.display_like_list();
    std::cout << "tree shape: " << std::endl;
    rbst.display_like_tree();
#endif
    std::cout << std::endl << std::endl;

    return EXIT_SUCCESS;
}