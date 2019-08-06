#include <iostream>
#include <queue>
#include "tree.h"

namespace trees
{
  template<typename _Ty>
  struct BinaryTreeNode<_Ty>* BreadthFirstSearch(struct BinaryTreeNode<_Ty>* root, _Ty value)
  {
    if (root == nullptr)
    {
      return nullptr;
    }

    std::queue<struct BinaryTreeNode<_Ty>*> nodes;

    nodes.push(root);
    while (!nodes.empty())
    {
      struct BinaryTreeNode<_Ty>* node = nodes.top();
      nodes.pop();

      if (node != nullptr)
      {
      }
    }
    return nullptr;
  }

  ///
  /// Depth-first search
  ///
  /// Time complexity:
  /// Constant O(|V| + |E|)
  ///
  /// where:
  /// V = number of vertices
  /// E = number of edges
  ///
  template<typename _Ty>
  struct BinaryTreeNode<_Ty>* DepthFirstSearch(struct BinaryTreeNode<_Ty>* root, _Ty value)
  {
    return nullptr;
  }

  void test_binary_tree()
  {
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    for (int i = 1; i < 21; i++)
    {
      if (i == 10)
      {
        continue;
      }
      BinarySearchTree<int>::insert(root, i);
    }

    printf("[test_binary_tree] PreOrderTraversal: \n");
    BinaryTreeNode<int>::PreOrderTraversal(root);
    printf("\n\n");

    printf("[test_binary_tree] InOrderTraversal: \n");
    BinaryTreeNode<int>::InOrderTraversal(root);
    printf("\n\n");

    printf("[test_binary_tree] PostOrderTraversal: \n");
    BinaryTreeNode<int>::PostOrderTraversal(root);
    printf("\n\n");
  }

};