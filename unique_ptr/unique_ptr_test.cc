#include <iostream>
#include <memory>

// 一个简单的类来演示资源管理
class Resource {
public:
    Resource(int value) : data(value) {
        std::cout << "Resource constructed with value " << data << std::endl;
    }
    ~Resource() {
        std::cout << "Resource destroyed with value " << data << std::endl;
    }
    int getData() const { return data; }
private:
    int data;
};

// 函数返回一个 unique_ptr
std::unique_ptr<Resource> createResource(int value) {
    return std::make_unique<Resource>(value);
}

// 函数接受一个 unique_ptr 并使用它
void useResource(const std::unique_ptr<Resource>& resource) {
    if (resource) {
        std::cout << "Using resource with value: " << resource->getData() << std::endl;
    }
}

int main() {
    // 创建一个 unique_ptr
    std::unique_ptr<Resource> res1 = std::make_unique<Resource>(42);
    
    // 使用 unique_ptr
    useResource(res1);
    
    // 从函数返回 unique_ptr
    std::unique_ptr<Resource> res2 = createResource(100);
    
    // 使用返回的 unique_ptr
    useResource(res2);
    
    // 转移所有权
    std::unique_ptr<Resource> res3 = std::move(res1);
    
    // res1 现在为空
    if (!res1) {
        std::cout << "res1 is now empty" << std::endl;
    }
    
    // 使用转移后的 unique_ptr
    useResource(res3);
    
    // 资源会在 unique_ptr 离开作用域时自动释放
    std::cout << "Exiting main function" << std::endl;
    return 0;
}
