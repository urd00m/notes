int *z=0;

int main()
{
	volatile int x;

	x=*z;

	return x;
}
