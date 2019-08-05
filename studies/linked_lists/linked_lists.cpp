#include "linked_lists.hpp"

namespace linked_list
{
    // Polimorphic function for a singly linked list
	void reverseLinkedList(singly_linked_list_t** head)
	{
		// Just in case...
		if (head == nullptr)
		{
			return;
		}

		singly_linked_list_t* current = *head;
		singly_linked_list_t* previous = nullptr;
		singly_linked_list_t* next = nullptr;

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
}
