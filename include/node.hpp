#pragma once
#include <memory>
struct Node {
  int data;
  Node(int data);
  std::unique_ptr<Node> next;
};
