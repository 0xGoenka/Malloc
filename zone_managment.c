#include "ft_malloc.h"

void	*find_zone(char type, t_zone *gen)
{
	t_zone *ptr;

	ptr = gen
	while (ptr->next)
	{
		if (ptr->type == type)
		{
			return (ptr);
		}
	}
	return (0);
}
char	find_type(size_t size)
{
	if (size <= 100)
		return (1);
	if (size <= 1000)
		return (2);
	if (size <= 10000)
		return (3);
	if (size <= 100000)
		return (4);
	return (5);
}
