#ifndef STUDIES_TREE_H
#define STUDIES_TREE_H

#include <iostream>
#include <queue>

namespace trees
{
  // Defines a tree node
  struct Node
  {
    public:
      int data;
      // std::vector<Node*> adjacents;
  };

  #pragma region BinaryTree
  //
  // BinaryTree
  //
  // Time complexity:
  // -------------------------------------------------------
  //            Best       Average    Worst    
  // -------------------------------------------------------
  // Access:    Ω(log(n)), θ(log(n)), O(log(n))
  // Search:    Ω(log(n)), θ(log(n)), O(log(n))
  // Insertion: Ω(log(n)), θ(log(n)), O(log(n))
  // Deletion:  Ω(log(n)), θ(log(n)), O(log(n))
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
  };
  #pragma endregion

  ///
  /// BinarySearchTree
  ///
  /// Time complexity:
  /// All operations have average θ(log(n)), worst O(n)
  /// Access: θ(log(n)), O(n)
  /// Search: θ(log(n)), O(n)
  /// Insert: θ(log(n)), O(n)
  /// Delete: θ(log(n)), O(n)
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

  /// Binary Heaps
  struct BinaryHeap
  {
  private:
    int *heap_data_;
    int capacity_;
    int size_;

  public:
    BinaryHeap(int capacity) : capacity_(capacity), 
      heap_data_(nullptr), size_(0)
    {

    }

    virtual ~BinaryHeap()
    {
      if (this->heap_data_ != nullptr)
      {
        free(this->heap_data_);
      }
      this->heap_data_ = nullptr;
    }

    virtual int parent(int index);
    virtual int left(int index);
    virtual int right(int index);

    virtual void insertKey(int k);
    virtual void deleteKey(int index);
  };

  ///
  /// MinHeap
  ///
  /// Time complexity:
  /// 'insert key' has O(log(n))
  /// 'delete key' has O(log(n))
  ///
  struct MinHeap : virtual BinaryHeap
  {
  public:
    MinHeap(int capacity) : BinaryHeap(capacity)
    {
    }

    ~MinHeap()
    {

    }

    int parent(int index) override
    {
      return (index - 1) / 2;
    }

    int left(int index) override
    {
      return (2 * index) + 1;
    }

    int right(int index) override
    {
      return (2 * index) + 2;
    }

    void insertKey(int k) override
    {

    }

    void deleteKey(int index) override
    {

    }
  };

  
  /// Namespace functions
  void test_binary_tree();

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
  template<typename _Ty>
  struct BinaryTreeNode<_Ty>* BreadthFirstSearch(struct BinaryTreeNode<_Ty>* root, _Ty value);

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
  struct BinaryTreeNode<_Ty>* DepthFirstSearch(struct BinaryTreeNode<_Ty>* root, _Ty value);

  ///
  /// Vertical Sum
  ///
  template<typename _Ty>
  int VerticalSum(struct BinaryTreeNode<_Ty>* root);

}; // namespace trees

#endif // STUDIES_TREES_H