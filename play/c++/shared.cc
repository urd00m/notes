#include <memory>
#include <iostream>

using namespace std;

class Cow {
private:
  Cow *afriend;
  int num_stomachs;
public:
  virtual void MakeSound(void) const { cout << "moo" << endl; }
};

Cow global_cow;

Cow global_cows[100];

int main()
{
  Cow stack_cow;

  // "new Cow()" means malloc(sizeof(Cow)), then run the Cow constructor on that memory
  Cow *ptr_to_heap_cow = new Cow();

  shared_ptr<Cow> shared_ptr_to_heap_cow(new Cow());
  shared_ptr<Cow> another_shared_ptr_to_heap_cow;
  
  global_cow.MakeSound();
  stack_cow.MakeSound();
  ptr_to_heap_cow->MakeSound();
  shared_ptr_to_heap_cow->MakeSound();
  
  cout << "shared_ptr has use count "<< shared_ptr_to_heap_cow.use_count()<<endl;
  
  cout << "another_shared_ptr has use count "<< another_shared_ptr_to_heap_cow.use_count()<<endl;
  
  another_shared_ptr_to_heap_cow = shared_ptr_to_heap_cow;

  cout << "shared_ptr has use count "<< shared_ptr_to_heap_cow.use_count()<<endl;
  
  cout << "another_shared_ptr has use count "<< another_shared_ptr_to_heap_cow.use_count()<<endl;
  

}

  
