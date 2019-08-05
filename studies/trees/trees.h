#ifndef STUDIES_TREES_H
#define STUDIES_TREES_H

#include <iostream>
#include <vector>
#include <queue>

namespace trees
{
  // Defines a tree node
  struct Node
  {
    public:
      int data;
      std::vector<Node*> adjacents;
    };

    //
    // BinaryTrees
    //
    // Time complexity:
    // -------------------------------------------------------
    // Access:    O(log(n))      
    // Search:    O(log(n))
    // Insertion: O(log(n))
    // Deletion:  O(log(n))
    // -------------------------------------------------------
    template<typename _Ty>
    struct BinaryTreeNode
    {
      _Ty data;
      struct BinaryTreeNode* left;
      struct BinaryTreeNode* right;

      BinaryTreeNode() : data(-1), left(nullptr), right(nullptr)
      {
      }

      BinaryTreeNode(_Ty data) : data(data), left(nullptr), right(nullptr)
      {
      }

      ///
      /// Static methods
      ///
      static BinaryTreeNode<_Ty>* insert(BinaryTreeNode<_Ty>* root, _Ty data)
      {
        if (root == nullptr)
        {
          return new BinaryTreeNode<_Ty>(data);
        }

        // We should throw an exception here
        if (root->data == data)
        {
          return root;
        }

        std::queue<BinaryTreeNode*> nodes;

        nodes.push(root);
        while (!nodes.empty())
        {
          struct BinaryTreeNode* node = nodes.front();
          nodes.pop();

          if (node->left == nullptr)
          {
            node->left = new BinaryTreeNode<_Ty>(data);
            return node->left;
          }
          else
          {
            nodes.push(node->left);
          }

          if (node->right == nullptr)
          {
            node->right = new BinaryTreeNode<_Ty>(data);
            return node->right;
          }
          else
          {
            nodes.push(node->right);
          }
        } // while (nodes is not empty)

        return root;
      }

      static BinaryTreeNode<_Ty>* search(BinaryTreeNode<_Ty>* root, _Ty data)
      {
        if (root == nullptr)
        {
          return nullptr;
        }

        if (data == root->data)
        {
          return root;
        }

        if (data < root->data)
        {
          return search(data, root->left);
        }

        // Default is to search right nodes
        return search(data, root->right);
      }

      static void PreOrderTraversal(BinaryTreeNode<_Ty>* root)
      {
        if (root == nullptr)
        {
          return;
        }

        printf("[%02d] ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
      }

      static void InOrderTraversal(BinaryTreeNode<_Ty>* root)
      {
        if (root == nullptr)
        {
          return;
        }

        InOrderTraversal(root->left);
        printf("[%02d] ", root->data);
        InOrderTraversal(root->right);
      }

      static void PostOrderTraversal(BinaryTreeNode<_Ty>* root)
      {
        if (root == nullptr)
        {
          return;
        }

        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("[%02d] ", root->data);
      }

      /// Searching algorithms

      ///
      /// Breadth-first search
      ///
      /// Time complexity:
      /// Constant O(|V| + |E|)
      ///
      /// where:
      /// V = number of vertices
      /// E = number of edges
      ///
      struct BinaryTreeNode<_Ty>* BreadthFirstSearch(struct BinaryTreeNode* root, _Ty value)
      {
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
      struct BinaryTreeNode<_Ty>* DepthFirstSearch(struct BinaryTreeNode* root, _Ty value)
      {
        return nullptr;
      } 
    };

    ///
    /// BinarySearchTree
    ///
    template<typename _Ty>
    struct BinarySearchTree : virtual BinaryTreeNode<_Ty>
    {
      static BinaryTreeNode<_Ty>* insert(BinaryTreeNode<_Ty>* root, _Ty data)
      {
        if (root == nullptr)
        {
          return nullptr;
        }

        if (data == root->data)
        {
          return root;
        }

        std::queue<struct BinaryTreeNode<_Ty>*> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
          struct BinaryTreeNode<_Ty>* node = nodes.front();
          nodes.pop();

          if (node->data == data)
          {
            // Should not happen!
            continue;
          }

          if (data < node->data)
          {
            // Insert to left
            if (node->left == nullptr)
            {
              node->left = new BinaryTreeNode<_Ty>(data);
            }

            nodes.push(node->left);
          }
          else // if (data > node->data)
          {
            if (node->right == nullptr)
            {
              node->right = new BinaryTreeNode<_Ty>(data);
            }

            nodes.push(node->right);
          }
        } // While nodes is not empty

        return nullptr;
      }
    };


    /// Namespace functions
    void test_binary_tree();

}; // namespace trees

#endif // STUDIES_TREES_H