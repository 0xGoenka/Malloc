#include "ft_malloc.h"

t_zone		*gen_init(t_zone *gen);
{
	t_zone *tmp;

	tmp = getmem(sizeof(t_zone));

	tmp->prev	= NULL;
	tmp->next	= NULL;
	tmp->type	= 0;
	
	return (tmp);
}