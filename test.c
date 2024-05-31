#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	int	written;

	written = ft_printf("Lets test with a %s %s!", "string", "and another");
	printf("\n%i", written);

	//printf("Not the right amount of values %i, %i, %i", 1, 2); //does not compile
	//printf("Not the right amount of values %i, %i, %i", 1, 2, 3, 4); //does not compile
}