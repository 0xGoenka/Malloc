#include "ft_malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *tmp;
	t_zone *gen = NULL;

	gen = getstatic();

	if (ptr == NULL)
		return (0);
	while (gen)
	{
		if ((void*)gen->data <= ptr && (int)gen->data + gen->len >= (int)ptr)
			break ;
		else
			gen = gen->next;
	}

	tmp = ft_malloc(size);
	ft_memcpy(tmp, ptr, gen->len);
	ft_free(ptr);
	ptr = tmp;
	return (0);
}
