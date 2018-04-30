#include "ft_malloc.h"

void	*find_zone(char type, t_zone *gen)
{
	t_zone *ptr;

	ptr = gen;
	while (ptr->next != NULL)
	{
		if (ptr->type == type)
		{
			return (ptr);
		}
		ptr = ptr->next;
	}
	return (0);
}
void	*find_storage(t_zone *zone)
{
	int i = 0;

	t_zone *g = zone;
	if (zone->type == -1) // if zone == ove4r classic size
		return (NULL);
	while (i < 100)
	{
		if (zone->state[i] == 0)
		{
			zone->state[i] = 1;
			return (zone->data + (i * type_to_size(zone->type)));
		}
		i++;
	}
	ft_putstr("return NULL");
		
	return (create_zone(zone, zone->type, type_to_size(zone->type)));
}
int		find_type(size_t size)
{
	if (size <= 10)
		return (1);
	if (size <= 100)
		return (2);
	if (size <= 1000)
		return (3);
	if (size <= 10000)
		return (4);
	if (size <= 100000)		
		return (5);
	return (-1);
}

int		type_to_size(char type)
{
	int ret = 1;
	if (type == -1)
		return (-1);
	while (type > 0)
	{
		ret = ret * 10;
		type--;
	}
	return ret;
}

void	*create_zone(t_zone *gen, char type, size_t size)
{
	t_zone *new;
	t_zone *tmp;

	int i = 0;
	new = getmem(sizeof(t_zone));
	tmp = gen;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
	new->type = type;
	if (type == -1)
		new->data = getmem(sizeof(size)); 
	else
	{
		new->data = getmem(sizeof(size  * 100));
		new->state[0] = 1;
	}
	return new->data;
}
