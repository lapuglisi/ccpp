#include "linked_lists.h"

namespace linked_list
{
    // Polimorphic function for a singly linked list
	void reverse_linked_list(Node*& head)
	{
		// Just in case...
		if (head == nullptr)
		{
			return;
		}

		Node* current = head;
		Node* previous = nullptr;
		Node* next = nullptr;

		while (current != nullptr)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}

		// Update head
		head = previous;
	}
}
