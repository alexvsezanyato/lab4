#include <iostream>

class Test {
    virtual void fun();
};

class Child {
    Test run(Test test);
};

int main() {
    Child app;
    return 0;
}
