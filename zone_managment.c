#include "ft_malloc.h"

void	*find_zone(char type, t_zone *gen)
{
	t_zone *ptr;

	ptr = gen->next;
	while (ptr)
	{
		if (ptr->type == type && ptr->state[99] == 0)
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

	if (zone == NULL)
		return NULL;
	if (zone->type == -1) // if zone == ove4r classic size
		return (NULL);
	while (i < 100)
	{
		if (zone->state[i] == 0)
		{
			zone->state[i] = 1;
			return (zone->data + (sizeof(char) * i * type_to_size(zone->type)));
		}
		i++;
	}
	
	//ft_putstr("=================================================================");

	//return (find_storage(create_zone(zone, zone->type, type_to_size(zone->type))));
	return (0);
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
		new->len = size;
	else
		new->len = type_to_size(type) * 100;
	new->data = getmem(new->len);
	return new;
}
