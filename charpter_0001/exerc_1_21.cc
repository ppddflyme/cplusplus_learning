#include <iostream> 
#include "sales_item.h"
using namespace book_store;
using std::cin;
using std::cout;
using std::endl;

int main() {
  sales_item item1, item2;
  cin >> item1 >> item2;
  cout << item1 + item2 << endl;
  return 0;
}
