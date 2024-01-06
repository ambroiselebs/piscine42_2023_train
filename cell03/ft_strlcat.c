#include "lib/ft_strlen.h"

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len = ft_strlen(dest);
	int total_len = dest_len + ft_strlen(src);

	for (unsigned int i = 0; i < size; i++)
	{
		dest[dest_len+i] = src[i];
	}

	dest[total_len+1] = '\0';
	printf("%s", dest);

	return total_len;
}
