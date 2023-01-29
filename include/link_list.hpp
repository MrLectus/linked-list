#pragma once
#include "node.hpp"
#include <iostream>
#include <memory>

class Linklist {
  std::unique_ptr<Node> head;
  size_t size{};

public:
  Linklist();
  void push_back(int data);
  void pop_back();
  void push_front(int data);
  void pop_front();
  void remove(size_t index);
  size_t search(int data);
  size_t get(int index);
  void insert(size_t index, int data);
  size_t length();
  bool empty();
  void print();
  ~Linklist();
};
