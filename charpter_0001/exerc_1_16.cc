#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int input_data = 0;
  long sum = 0;
  while(cin >> input_data) {
    sum += (long)input_data;
  }
  cout << "The sum is " << sum << endl;
  return 0;
}
