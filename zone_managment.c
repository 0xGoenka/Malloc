/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:47:23 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/16 19:51:16 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*find_zone(char type, t_zone *gen)
{
	t_zone	*ptr;

	ptr = gen->next;
	if (type == -1)
		return (0);
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

void		*find_storage(t_zone *zone)
{
	int		i;

	i = 0;
	if (zone == NULL)
		return (NULL);
	if (zone->type == -1)
		return (zone->data);
	while (i < 100)
	{
		if (zone->state[i] == 0)
		{
			zone->state[i] = 1;
			return (zone->data + (sizeof(char) * i * type_to_size(zone->type)));
		}
		i++;
	}
	return (0);
}

int			find_type(size_t size)
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

int			type_to_size(char type)
{
	t_zone	*gen;
	int		ret;

	ret = 1;
	if (type == -1)
	{
		gen = getstatic();
		return (gen->len);
	}
	while (type > 0)
	{
		ret = ret * 10;
		type--;
	}
	return (ret);
}

void		*create_zone(t_zone *gen, char type, size_t size)
{
	t_zone	*new;
	t_zone	*tmp;
	int		i;

	i = 0;
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
	{
		printf("we got a winner %d\n", size);
		new->len = size;
	}
	else
		new->len = type_to_size(type) * 100;
	new->data = getmem(new->len);
	return (new);
}
