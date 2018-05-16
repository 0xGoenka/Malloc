#include "ft_malloc.h"


void	*ft_realloc(void *ptr, size_t size)
{
	ft_free(ptr);
	ft_malloc(size);
	return (0);
}
