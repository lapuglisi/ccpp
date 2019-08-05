#pragma once
#include <iostream>

namespace linked_list
{
	typedef struct singly_linked_list
	{
		int data;
		struct singly_linked_list* next;

		singly_linked_list() : next(nullptr), data(-1)
		{
		}

		singly_linked_list(int data) : next(nullptr), data(data)
		{
		}

		static void destroy(struct singly_linked_list* head)
		{
			while (head != nullptr)
			{
				struct singly_linked_list* next = head->next;
				printf("[singly_linked_list] deleting node [data: %d] @ 0x%p\n", head->data, head);
				delete head;
				head = next;
			}
		}

		struct singly_linked_list* insert(int data)
		{
			this->next = new singly_linked_list(data);
			return this->next;
		}

		void dump_me(const char *separator = " ")
		{
			for (struct singly_linked_list* node = this; node != nullptr; node = node->next)
			{
				printf("%d%s", node->data, (node->next == nullptr ? "" : separator));
			}
		}
	} singly_linked_list_t;

	// Polimorphic function for a singly linked list
	void reverseLinkedList(singly_linked_list_t** head);
}
