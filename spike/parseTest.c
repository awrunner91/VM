#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void alter_array(int arr[])
{
	arr[0] = 17;
}

void change_num(int *a)
{
	*a = 13;
}

int main()
{
	int a = 4;
	int b = 2;
	int res = a | b;

	printf("RES: %d\n",res);
	
	return 0;
}
