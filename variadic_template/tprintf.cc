#include <iostream>

void tprintf(const char *format) {
  std::cout << format;
}

template<typename T, typename... Targs>
void tprintf(const char *format, T value, Targs... Fargs) {
  //std::cout << sizeof...(Targs) << std::endl;
  //std::cout << sizeof...(Fargs) << std::endl;  
  for (; *format !='\0'; ++format) {
    if (*format == '%') {
      std::cout << value;
      tprintf(format+1, Fargs...);
      return;
    }
    std::cout << *format;
  }
}

int main() {
  tprintf("% world% %\n", "Hello", '!', 123);
  return 0;
}
