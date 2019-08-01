#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    /* int depth; */

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~TreeNode()
    {
        delete this->left;
        delete this->right;
    }

    void insert(int left, int right)
    {
        if (left != -1)
        {
            this->left = new TreeNode(left);
        }

        if (right != -1)
        {
            this->right = new TreeNode(right);
        }
    }

    void swap(int factor, int level)
    {
        
        if (level % factor == 0)
        {
            TreeNode* temp = this->left;
            this->left = this->right;
            this->right = temp;
            temp = nullptr;
        }

        if (this->left != nullptr)
        {
            this->left->swap(factor, level + 1);
        }

        if (this->right != nullptr)
        {
            this->right->swap(factor, level + 1);
        }
    }

    void inorder_to_vector(vector<int>& dump)
    {
        // Inorder traversal
        if (this->left != nullptr)
        {
            this->left->inorder_to_vector(dump);
        }

        dump.push_back(this->data);

        if (this->right != nullptr)
        {
            this->right->inorder_to_vector(dump);
        }

    }
};

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
    int index = 0;

    vector<vector<int>> result;
    vector<int> swapped;
    queue<TreeNode*> nodes;
    
    // build the tree
    TreeNode root(1);

    nodes.push(&root);
    while (index < indexes.size())
    {
        while (!nodes.empty())
        {
            TreeNode* current = nodes.front();
            nodes.pop();

            int left = indexes[index][0];
            int right = indexes[index][1];

            if (current != nullptr)
            {
                current->insert(left, right);

                if (nullptr != current->left)
                {
                    nodes.push(current->left);
                }

                if (nullptr != current->right)
                {
                    nodes.push(current->right);
                }
            }

            index++;
        }

        // Now perform the queries
        for (vector<int>::const_iterator it = queries.begin(); it != queries.end(); it++)
        {
            root.swap(*it, 1);

            swapped.clear();
            root.inorder_to_vector(swapped);
            result.push_back(swapped);
        }
    }

    return result;
}

int main()
{
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> indexes(n);
  for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
    indexes[indexes_row_itr].resize(2);

    for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
        cin >> indexes[indexes_row_itr][indexes_column_itr];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> queries(queries_count);

  for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
    int queries_item;
    cin >> queries_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    queries[queries_itr] = queries_item;
  }

  vector<vector<int>> result = swapNodes(indexes, queries);

  for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
    for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
        cout << result[result_row_itr][result_column_itr];

        if (result_column_itr != result[result_row_itr].size() - 1) {
            cout << " ";
        }
    }

    if (result_row_itr != result.size() - 1) {
        cout << "\n";
    }
  }

  cout << "\n";

  return 0;
}
