#pragma once
#include "node.hpp"
#include <iostream>

class Linklist{
  Node *head;
  size_t size;

  public:
  Linklist(int data);
  void push_back(int data);
  void push_front(int data);
  size_t length();
  void print();
};
