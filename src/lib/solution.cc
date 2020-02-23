#include "solution.h"
#include <iostream>
#include <queue>
#include <bits/stdc++.h>

void BST::push(int key)
{
  root_ = pushNode(BST::root_, key);
}

bool BST::find(int key)
{
  TreeNode *temp = findNode(root_, key);
  if (temp == nullptr)
    return false;
  else
    return true;
}

bool BST::erase(int key)
{
  if (find(key))
  {
    TreeNode *temp = eraseNode(root_, key);
    if (temp == nullptr)
      return false;
    else
      return true;
  }
  else
    return false;
}

TreeNode *BST::pushNode(TreeNode *node, int key)
{
  if (node == nullptr)
  {
    return (new TreeNode(key));
  }
  else if (key < node->val)
  {
    node->left = pushNode(node->left, key);
  }
  else if (key > node->val)
  {
    node->right = pushNode(node->right, key);
  }
  return node;
}

TreeNode *BST::findNode(TreeNode *node, int key)
{
  if (node == nullptr || node->val == key)
    return node;

  if (key < node->val)
    return findNode(node->left, key);
  else
    return findNode(node->right, key);
}

TreeNode *BST::eraseNode(TreeNode *node, int key)
{
  if (node == nullptr)
    return node;

  if (key < node->val)
    node->left = eraseNode(node->left, key);
  else if (key > node->val)
    node->right = eraseNode(node->right, key);
  else
  {
    if (node->left == nullptr)
    {
      TreeNode *temp = node->right;
      free(node);
      return temp;
    }
    else if (node->right == nullptr)
    {
      TreeNode *temp = node->left;
      free(node);
      return temp;
    }

    TreeNode *temp = minNode(node->right);
    node->val = temp->val;
    node->right = eraseNode(node->right, temp->val);
  }
  return node;
}

TreeNode *BST::minNode(TreeNode *node)
{
  TreeNode *temp = node;

  while (temp != nullptr && temp->left != nullptr)
  {
    temp = temp->left;
  }

  return temp;
}

std::vector<int> BST::Inorder()
{
  std::vector <int> result;
  InorderBST(root_, result);
  return result;
}

void  BST::InorderBST(TreeNode *node, std::vector <int> &result)
{
  if (node == nullptr)
    return;
  
  InorderBST(node->left, result);
  result.push_back(node->val);
  InorderBST(node->right, result);
}

std::vector<int> BST::LevelOrder()
{
  std::vector<int> result;
  std::queue<TreeNode *> inputqueue;

  if (root_ == nullptr)
    return result;

  inputqueue.push(root_);
  TreeNode *temp;

  while (!inputqueue.empty())
  {
    temp = inputqueue.front();
    result.push_back(temp->val);
    inputqueue.pop();
    if (temp->left != nullptr)
      inputqueue.push(temp->left);

    if (temp->right != nullptr)
      inputqueue.push(temp->right);
  }

  return result;
}

int BST::findHeight()
{
  return findHeightNode(root_);
}

int BST::findHeightNode(TreeNode *node)
{
  if (node == nullptr)
    return 0;

  int lheight = findHeightNode(node->left);
  int rheight = findHeightNode(node->right);

  if (lheight > rheight)
    return lheight + 1;
  else
    return rheight + 1;
}

std::vector <int> BST::Inorder_non_recursive() {
  std::vector <int> result;
  if (root_ == nullptr)
    return result;

  std::stack <TreeNode*> stack_inorder;
  TreeNode* node = root_;
  while (node != nullptr || !stack_inorder.empty()) {
    while (node != nullptr) {
      stack_inorder.push(node);
      node = node->left;
    }

    node = stack_inorder.top();
    stack_inorder.pop();
    result.push_back(node->val);
    node = node->right;
  }

  return result;
}