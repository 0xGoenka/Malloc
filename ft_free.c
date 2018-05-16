/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:03:13 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/16 19:42:45 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		ft_free(void *ptr)
{
	t_zone	*gen;
	int		size;
	int		blocknumber;

	if (ptr == NULL)
		return ;
	gen = getstatic();
	while (gen)
	{
		if (gen->data <= ptr && (long int)gen->data + gen->len >= (long int)ptr)
			break ;
		else
			gen = gen->next;
	}
	if (gen == NULL)
		return ;
	size = type_to_size(gen->type);
	if ((blocknumber = ptr - gen->data) != 0)
	{
		blocknumber = blocknumber / size;
		gen->state[blocknumber - 1] = 0;
	}
	gen->state[blocknumber] = 0;
	ft_bzero(ptr, size);
	ptr = NULL;
}
