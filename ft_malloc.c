/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:19:52 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/01 18:36:15 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*getmem(size_t size)
{
	void *ptr = mmap(0, size, PROT_WRITE | PROT_READ,
	MAP_ANON | MAP_PRIVATE, -1, 0);

	if (MAP_FAILED == ptr)
	{
		ft_putendl("Mmap FAILED");
		return NULL;
	}
	perror("error");
	return ptr;
}

void	*ft_malloc(size_t size)
{
	static t_zone *gen = NULL;
	int type = -1;
	t_zone *zone = 0;
	if (gen == NULL)
	{
		if((gen = gen_init(gen)) == NULL)
			return NULL;
		
	}
	type = find_type(size);


	if ((zone = find_zone(type, gen)) == NULL)
		zone = create_zone(gen, type, size);
	if (zone == NULL)
		return NULL;

	//show_mem(gen);
	return find_storage(zone);
}
