#include "lib/ft_strlen.h"

int ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);

	return (0);
}
