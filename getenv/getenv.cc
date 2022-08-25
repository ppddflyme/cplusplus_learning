#include <iostream>
#include <stdlib.h> // getenv

int main() {
#ifdef _MSC_VER
// suppress "unsafe" warning on getenv
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
  char* pPath;
  pPath = getenv("PATH");
  if (pPath) {
    std::cout << "The current path is: " << pPath << std::endl;
  }
  return 0;
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}
