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
  //cudaError_t cuda_error = cudaMalloc((void**)&ptr, bytes);
  //cudaError_t cuda_error = 
  cout << "call cudaMalloc" << endl;
  //if (cuda_error != cudaSuccess) {
    //throw cuda_exception("Failed to allocate memory", cuda_error);
  //}

  return ptr;
}

/// Device allocation abstraction that tracks size and capacity
template <typename T>
struct allocation {
  /// Delete functor for CUDA device memory
  struct deleter {
    void operator()(T* ptr) {
      ASSERT_RT(cudaFree(ptr));
      //cudaFree(ptr);
      //cudaError_t cuda_error = cudaGetLastError();
      cout << "call cudaFree" << endl;
      //if (cuda_error != cudaSuccess) {
        // noexcept
        //                throw cuda_exception("cudaFree() failed", cuda_error);
        //cout << "call cudaFree failed!!!" << cudaGetErrorString(cuda_error) << endl;
        //return;
      //}
    }
  };
  //
  // Data members
  //

  /// Number of elements of T allocated on the current CUDA device
  size_t capacity;

  /// Smart pointer
  std::unique_ptr<T, deleter> smart_ptr;

  //
  // Methods
  //

  /// Constructor: allocates no memory
  allocation() : capacity(0) {}

  /// Constructor: allocates \p capacity elements on the current CUDA device
  allocation(size_t _capacity) : smart_ptr(allocate<T>(_capacity)), capacity(_capacity) {}

  /// Destructor
  ~allocation() { reset(); }

  /// Deletes the managed object and resets capacity to zero
  void reset() {
    capacity = 0;
    smart_ptr.reset();
  }

  /// Returns a pointer to the managed object
  T* get() const { return smart_ptr.get(); }
};

int main () {
  allocation<int> a(10);
  int * p = a.get();

  return 0;
}
