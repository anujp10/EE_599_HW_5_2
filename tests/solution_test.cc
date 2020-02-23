#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(InorderShould, InorderReturn) {
  BST tree;
  tree.push(10);
  tree.push(20);
  tree.push(2);
  tree.push(9);
  tree.push(0);
  tree.push(1);
  tree.push(11);
  tree.push(25);
  std::vector <int> actual = tree.Inorder();
  std::vector <int> expected = {0, 1, 2, 9, 10, 11, 20, 25};
  EXPECT_EQ(expected, actual);
}

TEST(InorderShould_1, InorderReturn_1) {
  BST tree;
  std::vector <int> actual = tree.Inorder();
  std::vector <int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(InorderShould_2, InorderReturn_2) {
  BST tree;
  tree.push(10);
  tree.push(20);
  tree.push(2);
  tree.push(9);
  tree.push(0);
  tree.push(1);
  tree.push(11);
  tree.push(25);
  std::vector <int> actual = tree.Inorder_non_recursive();
  std::vector <int> expected = {0, 1, 2, 9, 10, 11, 20, 25};
  EXPECT_EQ(expected, actual);
}

TEST(InorderShould_3, InorderReturn_3) {
  BST tree;
  std::vector <int> actual = tree.Inorder_non_recursive();
  std::vector <int> expected = {};
  EXPECT_EQ(expected, actual);
}