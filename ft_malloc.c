/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:19:52 by eleclet           #+#    #+#             */
/*   Updated: 2018/04/30 18:24:25 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*getmem(size_t size)
{
	return mmap(0, sizeof(t_zone), PROT_WRITE | PROT_READ,
	MAP_ANON | MAP_PRIVATE, -1, 0);
}

void	*ft_malloc(size_t size)
{
	static t_zone *gen = NULL;
	int type = -1;
	t_zone *zone = 0;
	if (gen == NULL)
	{
		gen = gen_init(gen);
	}
	type = find_type(size);
	ft_putstr("size = ");
	ft_putnbr(size);
	ft_putstr("  type == ");
	ft_putnbr(type);
	ft_putchar('\n');
	if ((zone = find_zone(type, gen)) == NULL)
	{
		return (create_zone(gen, type, size));
	}
		
	show_mem(gen);
	return find_storage(zone);
}
