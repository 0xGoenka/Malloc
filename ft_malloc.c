/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:19:52 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/16 19:47:12 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_zone				*getstatic(void)
{
	static t_zone	*gen = NULL;

	if (gen == NULL)
		gen = gen_init(gen);
	return (gen);
}

void				*getmem(size_t size)
{
	void			*ptr;

	ptr = mmap(0, size, PROT_WRITE | PROT_READ,
	MAP_ANON | MAP_PRIVATE, -1, 0);
	if (MAP_FAILED == ptr)
	{
		ft_putendl("Mmap FAILED");
		return (NULL);
	}
	return (ptr);
}

void				*ft_malloc(size_t size)
{
	int				type;
	t_zone			*zone;
	t_zone			*gen;

	gen = getstatic();
	type = find_type(size);
	if ((zone = find_zone(type, gen)) == NULL)
		zone = create_zone(gen, type, size);
	if (zone == NULL)
	{
		printf("error\n");
		return (NULL);
	}
	show_mem(gen);
	return (find_storage(zone));
}
