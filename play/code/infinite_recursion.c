long fib(long x)
{
   if (x==0 || x==1) { 
      return 1;
   } else {
     return fib(x-1)+fib(x-2);
   }
}

int main()
{
  return fib(999999999999LL);
}

