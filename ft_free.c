/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:03:13 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/16 17:56:29 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void ft_free(void *ptr)
{
	t_zone *gen = NULL;
	int size = 0;
	int blocknumber = 0;

	if (ptr == NULL)
		return ;
	gen = getstatic();

	while (gen)
	{
		if ((void*)gen->data <= ptr && (long int)gen->data + gen->len >= (long int)ptr)
			break;
		else
			gen = gen->next;
	}
	if (gen == NULL)
		return ;
	size = type_to_size(gen->type);
	blocknumber = ptr - gen->data;

	if (blocknumber != 0)
	{
		blocknumber = blocknumber / size;
		gen->state[blocknumber - 1] = 0;
	}
	gen->state[blocknumber] = 0;
	ft_bzero(ptr, size);
	ptr = NULL;
}
