#include <iostream>

template <typename T, typename ... Candidates>
struct is_same_type;

template<typename T>
struct is_same_type<T, T> {
  static const bool value = true;
};

template<typename T, typename U>
struct is_same_type<T, U> {
  static const bool value = false;
};

template <typename T, typename C, typename ... Candidates>
struct is_same_type<T, C, Candidates...> {
  static const bool value = is_same_type<T, C>::value || is_same_type<T, Candidates...>::value;
};

int main() {
  bool b = is_same_type<float, int, float>::value;
  if (b) {
    std::cout << "equal" << std::endl;
  } else {
    std::cout << "not equal" << std::endl;
  }
  return 0;
}
