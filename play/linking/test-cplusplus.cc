int i;

extern "C" int sleep(int);

// local symbols

static int my_local_var; 

static int my_local_func(int x)
{
  return x+2;
}

// global symbols

int my_global_var;  

int my_global_func(int x)
{
  return x*x;
}

// extern symbols
extern int other_global_var;  

int other_global_func(int x); 

extern "C" int printf(const char *, ...);

int bar(int);

// Using the extern symbols
int my_test_func(int x)
{
  // these are references to the external symbols
  return other_global_var * other_global_func(x);
}

int main()
{
  my_local_var=32;
  my_global_var=64;
  other_global_var=42;

  my_local_func(93);
  my_test_func(93);
  other_global_func(93);

  //  bar(5);

  printf("Done.\n");

  while (1) { sleep(1); } 
}
