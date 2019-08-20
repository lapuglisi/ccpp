#include <iostream>
#include <map>

using namespace std;

struct Node {
  int data;
  struct Node* next;
  struct Node* random;

  Node() : data(-1), next(nullptr), random(nullptr) {

  }

  Node(int data, struct Node* next, struct Node* random)
  {
    this->data = data;
    this->next = next;
    this->random = random;

  }
};

struct Node* clone(struct Node* source) {

  if (source == nullptr) {
    return nullptr;
  }

  struct Node* newNode = new Node(source->data, nullptr, source);

  return newNode;
}

struct Node* copyList(struct Node* head) {
  if (head == nullptr) {
    return head;
  }

  struct Node* node = head;
  struct Node* last = nullptr;
  struct Node* next = nullptr;

  struct Node* newHead = clone(node);
  last = newHead;
  next = node->next;
  node->next = newHead;
  node = next;
  while (node != nullptr) {
    struct Node* newNode = clone(node);
    last->next = newNode;
    last = newNode;

    // Now here is the fucking trick
    struct Node* next = node->next;
    node->next = newNode;
    
    node = next;
  }

  // Now update references of randoms
  node = newHead;
  while (node != nullptr) {
    if (node->random->random != nullptr)
    {
      node->random = node->random->random->next;
    }
    else
    {
      node->random = nullptr;
    }

    node = node->next;
  }

  return newHead;
}

inline void printNode(const struct Node* node) {
  printf("node: [data: %d @ %p, next: %d @ %p, random: %d @ %p]\n",
      node->data, node,
      (node->next ? node->next->data : -1), node->next,
      (node->random ? node->random->data : -1), node->random);
}

int main() 
{
  struct Node* head = new Node(1, nullptr, nullptr);
  struct Node* node1 = new Node(2, nullptr, nullptr);
  struct Node* node2 = new Node(3, nullptr, nullptr);
  struct Node* node3 = new Node(4, nullptr, nullptr);
  struct Node* node4 = new Node(5, nullptr, nullptr);

  head->next = node1;

  node1->next = node2;
  node1->random = node3;

  node2->next = node3;
  node2->random = node1;

  node3->next = node4;
  node3->random = head;

  node4->random = node2;

  struct Node* iter = head;
  printf("[amazon] Printing original list: \n");
  while (iter != nullptr) {
    printNode(iter);

    iter = iter->next;
  }
  printf("\n");

  // Copy the list
  struct Node* newList = copyList(head);

  printf("[amazon] Printing copied list: \n");
  iter = newList;
  while (iter != nullptr) {
    printNode(iter);

    iter = iter->next;
  }
  printf("\n");

  // Free resources
  delete head;
  delete node1;
  delete node2;
  delete node3;
  delete node4;

  delete newList;

  return 0;
}