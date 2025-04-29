#include <iostream>

class test
{
private: 
    int a;
public:
    test() : a(0) {}  // Initialize a to avoid undefined behavior
    test(int x) : a(x) {}
    ~test() {}

    // Friend function for operator<<
    friend std::ostream& operator<<(std::ostream& os, const test& t);
    
    void showAdress()
    {
        std::cout << "Object address: " << this << std::endl;
        std::cout << "Object value: " << *this << std::endl;
    }
    
    // Getter for a (useful for printing)
    int getValue() const {
        return a;
    }
};

// Define operator<< outside the class
std::ostream& operator<<(std::ostream& os, const test& t)
{
    os << "test(a=" << t.a << ")";
    return os;
}

int main(void)
{ 
    test obj(42);
    obj.showAdress();
    
    // Direct usage of operator<<
    //std::cout << "Direct output: " << obj << std::endl;
    std::cout << std::scientific << 3.75f;
    
    return 0;
}