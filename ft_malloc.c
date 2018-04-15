/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:19:52 by eleclet           #+#    #+#             */
/*   Updated: 2018/04/12 18:24:49 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"


void	*getmem(size_t size)
{
	return mmap(0, sizeof(t_zone), PROT_WRITE | PROT_READ,
	MAP_ANON | MAP_PRIVATE, -1, 0);
}

void	*ft_malloc(size_t size)
{
	static t_zone *gen = NULL;
	char type = -1;

	if (gen == NULL)
		gen_init(gen);

	type = find_type(size);
		
	if (find_zone(type, gen) == 0)
		return (create_zone());
}	


