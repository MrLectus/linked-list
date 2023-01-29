#include "link_list.hpp"
#include <memory>
int main() {
  std::unique_ptr<Linklist> list(new Linklist());
  list->push_back(21);
  list->push_back(34);
  list->push_back(70);
  list->push_back(100);
  list->push_back(300);
  list->push_back(200);
  list->push_back(300);
  std::cout << "value: " << list->search(100) << "\n";
  list->print();
}
