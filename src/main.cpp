#include "link_list.hpp"
int main() {
  Linklist *list = new Linklist(400);
  list->push_back(20);
  list->push_back(45);
  list->push_back(56);
  list->push_front(666);
  list->insert(100, 179);
  list->insert(1, 205);
  list->pop_front();
  list->pop_front();
  list->pop_back();
  list->print();
  std::cout << "length is (" << list->length() << ")";
  std::cout << "\n";
  delete list;
}
