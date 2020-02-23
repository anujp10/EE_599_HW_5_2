#include <iostream>
#include "src/lib/solution.h"

int main()
{
    std::vector<int> input = {10, 20, 2, 0, -8, -6, 41, -9, 5, 15, 4, 7, 22};
    BST *tree = new BST(input);
    std::vector <int> inorder = tree->Inorder();
    std::cout << "Recursive inorder traversal : ";
    for (auto &n : inorder)
        std::cout << n << " ";
    std::cout << std::endl;

    std::vector <int> inorder_non_recursive = tree->Inorder_non_recursive();
    std::cout << "Non-recursive inorder traversal : ";
    for (auto &n : inorder_non_recursive)
        std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "Height of the tree is : " << tree->findHeight() << std::endl;
    return EXIT_SUCCESS;
}