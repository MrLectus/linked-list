#pragma once
#include <memory>
struct Node {
  int data;
<<<<<<< HEAD
  Node *next;
  Node(int data);
=======
  std::unique_ptr<Node> next;

public:
  Node(int data) : data{data}, next{nullptr} {};
>>>>>>> 5235024 (added more functions)
};
