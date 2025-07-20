#include <iostream>
#include <memory>

class Obj {
    private:
    std::shared_ptr<int> x;

    public:
    Obj(int val) : x(std::make_shared<int>(val)) {}
    std::shared_ptr<int> getX() const { return x; }
    void setX(int val) { *x = val; }
};

int main() {
    auto obj = std::make_shared<Obj>(42);
    std::cout << "Value of x: " << *obj->getX() << std::endl;

    auto ptr = obj->getX();

    *ptr = 5;
    std::cout << "Value of x after reset: " << *ptr << std::endl;

    return 0;
}