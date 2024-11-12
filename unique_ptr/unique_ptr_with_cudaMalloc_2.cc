// unique_ptr constructor example
#include <iostream>
#include <memory>
#include <cuda_runtime.h>
using std::cout;
using std::endl;

#define ASSERT_RT_ERR(call, expVal)                                                                             \
  do {                                                                                                          \
    cudaError_t stat;                                                                                           \
    (call);                                                                                                     \
    stat = cudaGetLastError();                                                                                  \
    if (stat != (expVal)) {                                                                                     \
      cout << "Error in " << #call << ": in " << __FILE__ << ":" << __LINE__ << ". Expected Value:" << expVal   \
             << ", Actual Value:" << stat << endl;                                                              \
    }                                                                                                           \
  } while (0)

#define ASSERT_RT(call) ASSERT_RT_ERR(call, cudaSuccess)

/// Allocate a buffer of \p count elements of type \p T on the current CUDA device
template <typename T>
T* allocate(size_t count = 1) {
  T* ptr = 0;
  size_t bytes = sizeof(T) * count;

  ASSERT_RT(cudaMalloc((void**)&ptr, bytes));
  cout << "call cudaMalloc" << endl;

  return ptr;
}

auto deleter = [](int* ptr) {
  ASSERT_RT(cudaFree(ptr));
  cout << "call cudaFree" << endl;
};

int main () {
  std::unique_ptr<int, decltype(deleter)> ptr (allocate<int>(100), deleter);

  return 0;
}
