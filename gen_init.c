/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:55:17 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/16 19:55:23 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_zone		*gen_init(void)
{
	t_zone *tmp;

	if ((tmp = getmem(sizeof(t_zone))) == NULL)
		return (NULL);
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->type = 0;
	return (tmp);
}
