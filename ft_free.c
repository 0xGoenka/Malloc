/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:03:13 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/02 19:58:33 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void ft_free(void *ptr)
{
	t_zone *gen = NULL;
	int size = 0;
	int blocknumber = 0;

	gen = getstatic(NULL);

	while (gen)
	{
		if ((void*)gen->data <= ptr && (int)gen->data + gen->len >= (int)ptr)
			break;
		else
			gen = gen->next;
		ft_putendl("while free");
	}
	if (gen == NULL)
	{
		ft_putendl("free buf");
		return ;
	}
	size = type_to_size(gen->type);
	blocknumber = ptr - gen->data;

	if (blocknumber != 0)
		blocknumber = blocknumber / size;
	gen->state[blocknumber] = 0;
	show_mem(gen);
	ptr = NULL;
}
