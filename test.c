#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	int	written;
	int i = 1;
	int *ptr = &i;

	written = ft_printf("Lets test with a %p!\n", ptr);
	printf("Lets test with a %p!", ptr);
	printf("\n%i", written);

	//printf("Not the right amount of values %i, %i, %i", 1, 2); //does not compile
	//printf("Not the right amount of values %i, %i, %i", 1, 2, 3, 4); //does not compile

	//printf("%p", NULL);
}