#include "link_list.hpp"
#include "node.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

Linklist::Linklist() { head = nullptr; };

void Linklist::push_front(int data) {
  auto temp = std::make_unique<Node>(data);
  if (head)
    temp->next = std::move(head);
  head = std::move(temp);
  size++;
}

void Linklist::push_back(int data) {
  auto temp = std::make_unique<Node>(data);
  auto curr = head.get();
  if (head == nullptr) {
    head = std::move(temp);
    size++;
  } else {
    while (curr->next != nullptr) {
      curr = curr->next.get();
    }
    curr->next = std::move(temp);
    size++;
  }
}

void Linklist::insert(size_t index, int data) {
  auto temp = std::make_unique<Node>(data);
  if (index <= 0) {
    push_front(data);
    size++;
  } else if (index > size) {
    push_back(data);
    size++;
  }
  auto prev = head.get();
  for (size_t i = 0; i < index - 1; ++i) {
    prev = prev->next.get();
  }
  temp->next = std::move(prev->next);
  prev->next = std::move(temp);
  size++;
}

void Linklist::pop_front() {
  if (head == nullptr)
    return;
  head = std::move(head->next);
  size--;
}

void Linklist::pop_back() {
  if (head == nullptr)
    return;
  auto curr = head.get();
  for (size_t i = 1; i < size - 1; ++i) {
    curr = curr->next.get();
  }
  curr->next = nullptr;
  size--;
}

void Linklist::remove(size_t index) {
  if (head == nullptr)
    return;
  if (index == 0)
    pop_front();
  if (index > size)
    pop_back();
  else {
    auto curr = head.get();
    for (size_t i = 1; i < index; ++i) {
      curr = curr->next.get();
    }
    curr->next = std::move(curr->next->next);
    size--;
  }
}

size_t Linklist::get(int index) {
  if (head == nullptr)
    return 0;
  if ((size_t)index >= size) {
    exit(-1);
  }
  auto curr = head.get();
  for (int i = 0; i < index; ++i) {
    curr = curr->next.get();
  }
  return curr->data;
}

size_t Linklist::search(int data) {
  if (head == nullptr) {
    return -1;
  }
  if (head->data == data)
    return 0;
  auto curr = head.get();
  for (size_t i = 0; i < size; ++i) {
    if (curr->data == data) {
      return i;
    }
    curr = curr->next.get();
  }
  return -1;
}

size_t Linklist::length() { return size; }
void Linklist::print() {
  auto temp = head.get();
  while (temp) {
    std::cout << temp->data << " ";
    temp = temp->next.get();
  }

  std::cout << "\nsize is (" << size << ")";
}

bool Linklist::empty() { return size == 0; }

Linklist::~Linklist() {
  while (head) {
    head = std::move(head->next);
  }
}
