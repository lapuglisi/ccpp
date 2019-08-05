#include <iostream>
#include "tree.h"

namespace trees
{
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