#pragma once
#include <iostream>

namespace linked_list
{
    typedef struct sll_node
    {
        int data;
        struct sll_node* next;

        sll_node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }

        ~sll_node()
        {
            sll_node *node = this;
            while (node != nullptr)
            {
                sll_node* next = node->next;
                delete node;
                node = next;
            }
        }
    } sll_node_t;

    ///
    /// Defines a node for a Doubly Linked List
    typedef struct dll_node
    {
        int data;
        struct dll_node *next;
        struct dll_node *previous;
    } dll_node_t;

	typedef struct singly_linked_list
	{
		int data;
		sll_node_t *node;

		singly_linked_list() : node(nullptr), data(-1)
		{
		}

		singly_linked_list(int data) : node(nullptr), data(data)
		{
		}

		static void destroy(sll_node_t* head)
		{
			while (head != nullptr)
			{
				sll_node_t* next = head->next;
				printf("[singly_linked_list] deleting node [data: %d] @ 0x%p\n", head->data, head);
				delete head;
				head = next;
			}
		}

		sll_node_t* insert(int data)
		{
			this->node = new sll_node_t(data);
			return this->node;
		}

		void dump_me(const char *separator = " ")
		{
			for (sll_node_t* node = this->node; node != nullptr; node = node->next)
			{
				printf("%d%s", node->data, (node->next == nullptr ? "" : separator));
			}
		}
	} singly_linked_list_t;

    typedef struct tree_node
    {
        int data;
        struct tree_node *left;
        struct tree_node *right;

        tree_node() = default;

        tree_node(int data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

        ~tree_node()
        {
            // Notice that every tree_node implements
            // its own destructor.
            // Therefore, each node will have it destructor
            // called accordingly.
            delete this->left;
            delete this->right;
        }
    } tree_node_t;

    typedef struct binary_tree_node : virtual tree_node_t
    {
        binary_tree_node(int data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

        static tree_node_t* insert(tree_node_t *root, int data)
        {
            if (root == nullptr)
            {
                return root;
            }

            if (root->data == data)
            {
                return root;
            }

            if (data > root->data)
            {
                if (root->right == nullptr)
                {
                    root->right = new binary_tree_node(data);
                    return root->right;
                }
                else
                {
                    return insert(root->right, data);
                }
            }

            // Left node is the default here
            if (root->left == nullptr)
            {
                root->left = new binary_tree_node(data);
                return root->left;
            }
            else
            {
                return insert(root->left, data);
            }

            return nullptr;
        }
    } binary_tree_node_t;

	// Polimorphic function for a singly linked list
	void reverseLinkedList(singly_linked_list_t** head);

    void preOrderTraversal(tree_node_t *root);
    void inOrderTraversal(tree_node_t *root);
    void postOrderTraversal(tree_node_t *root);

    void testTreeTraversal();
}
