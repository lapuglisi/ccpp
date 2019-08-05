#include "linked_lists.hpp"

namespace linked_list
{
    // Polimorphic function for a singly linked list
	void reverseLinkedList(sll_node_t** head)
	{
		// Just in case...
		if (head == nullptr)
		{
			return;
		}

		sll_node_t* current = *head;
		sll_node_t* previous = nullptr;
		sll_node_t* next = nullptr;

		while (current != nullptr)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}

		// Update head
		*head = previous;
	}

    void preOrderTraversal(tree_node_t *root)
    {
        if (root == nullptr)
        {
            return;
        }

        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(tree_node_t *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(tree_node_t *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);

        printf("%d ", root->data);
    }

    ///
    /// Methods for testing
    ///
    void testTreeTraversal()
    {
        // TODO: find a way to create a balanced tree
        binary_tree_node_t* root = new binary_tree_node_t(10);
        for (int i = 1; i <= 20; i += 2)
        {
            binary_tree_node_t::insert(root, i);
        }

        printf("[preOrderTraversal] Dumping...\n");
        preOrderTraversal(root);
        printf("\n\n");

        printf("[inOrderTraversal] Dumping...\n");
        inOrderTraversal(root);
        printf("\n\n");

        printf("[postOrderTraversal] Dumping...\n");
        postOrderTraversal(root);
        printf("\n\n");
    }
}
