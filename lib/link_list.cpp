#include "link_list.hpp"
#include "node.hpp"

Linklist::Linklist(int data) {
  head = new Node(data);
  this->size = 1;
}

void Linklist::push_back(int data) {
  Node *temp = new Node(data);
  Node *curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = temp;
  this->size++;
}

void Linklist::push_front(int data) {
  Node *temp = new Node(data);
  Node *curr = head;
  temp->next = head;
  head = temp;
  this->size++;
}

size_t Linklist::length() { return this->size; }
void Linklist::print() {
  while (head != nullptr) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout<<"\n";
}
