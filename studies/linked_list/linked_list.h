#ifndef STUDIES_LINKED_LIST_H
#define STUDIES_LINKED_LIST_H

#include <iostream>

namespace linked_list
{
    struct Node
    {
        int data;
        struct Node* next;

        Node(int data_) : data(data_), next(nullptr)
        {
        }

        ~Node()
        {
            Node *node = this;
            while (node != nullptr)
            {
                Node* next = node->next;
                delete node;
                node = next;
            }
        }
    };

    ///
    /// Defines a node for a Doubly Linked List
    struct DoublyLinkedNode
    {
        int data;
        struct DoublyLinkedNode *next;
        struct DoublyLinkedNode *previous;

        DoublyLinkedNode(int value): data(value), 
            next(nullptr), previous(nullptr)
        {
        }
    };

    template<typename NodeType>
	struct LinkedList
	{
		int data;
		NodeType *node;

		LinkedList() : node(nullptr), data(-1)
		{
		}

		LinkedList(int value) : node(nullptr), data(value)
		{
		}

		static void destroy(NodeType* head)
		{
			while (head != nullptr)
			{
				NodeType* next = head->next;
				printf("[singly_linked_list] deleting node [data: %d] @ 0x%p\n", head->data, head);
				delete head;
				head = next;
			}
		}

		NodeType* insert(int data)
		{
			this->node = new NodeType(data);
			return this->node;
		}

		void dump_me(const char *separator = " ")
		{
			for (NodeType* node = this->node; node != nullptr; node = node->next)
			{
				printf("%d%s", node->data, (node->next == nullptr ? "" : separator));
			}
		}
	};

    typedef LinkedList<Node> SinglyLinkedList;
    typedef LinkedList<DoublyLinkedNode> DoublyLinkedList;

	// Polimorphic function for a singly linked list
	void reverse_linked_list(Node*& head);
}

#endif // STUDIES_LINKED_LIST_H