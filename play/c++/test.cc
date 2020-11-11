#include <iostream>

using namespace std;

class BaseClass {
public:
   virtual int VirtualFunction() { return 99; }
} ;

int foo(BaseClass &x) {
   return x.VirtualFunction();
}

class DerivedClass : public BaseClass {
public:
   virtual int VirtualFunction() { return 11; }
} ;

int main()
{
  BaseClass base;
  DerivedClass derived;

  cout << "foo(base) = "<<foo(base)<<endl;
  cout << "foo(derived) = "<<foo(derived)<<endl;

}
