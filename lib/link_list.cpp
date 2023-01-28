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
  temp->next = head;
  head = temp;
  this->size++;
}

size_t Linklist::length() { return this->size; }

void Linklist::insert(size_t index, int data) {
  Node *temp = new Node(data);
  Node *prev = head;
  Node *curr = head->next;
  if (index == 0) {
    this->push_front(data);
  }
  if (index > size) {
    this->push_back(data);
  } else {
    for (size_t i = 0; i < index - 1; i++) {
      curr = curr->next;
      prev = prev->next;
    }
    temp->next = curr;
    prev->next = temp;
    size++;
  }
}

void Linklist::pop_front() {
  head = head->next;
  this->size--;
}

void Linklist::pop_back() {
  Node *curr = head;
  for (size_t i = 1; i < this->size - 1; i++) {
    curr = curr->next;
  }
  curr->next = nullptr;
  this->size--;
}

void Linklist::print() {
  while (head != nullptr) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << "\n";
}

Linklist::~Linklist() {
  std::cout << "memory freed"
            << "\n";
}
