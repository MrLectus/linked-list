#pragma once
#include "node.hpp"
#include <iostream>

class Linklist {
  Node *head;
  size_t size;

public:
  Linklist(int data);
  void push_back(int data);
  void pop_back();
  void push_front(int data);
  void pop_front();
  void remove(size_t index);
  size_t search(int data);
  void insert(size_t index, int data);
  size_t length();
  void print();
  ~Linklist();
};
