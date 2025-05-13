

#include<stdio.h>

class x
{
 public :
    void f1()
    {
        printf("x function \n");
    }
};

class b:virtual public x
{
    public :
    void f1()
    {
        printf("b function \n");
    }
};

class a:virtual public x
{
    public :
    void f1()
    {
        printf("a function \n");
    }
};

class d:public a, public b
{
    public :
    void f1()
    {
        printf("b function \n");
    }
};

int main(void)
{
    d obj;
    //obj.f1();
    obj.a::f1(); // Calls a's f1()
    obj.b::f1(); 
    obj.x::f1();
}