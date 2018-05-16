/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:35:28 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/16 17:55:36 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	show_mem(t_zone *gen)
{
	static int j = 0;
	t_zone *tmp;

	tmp = gen;
	if (tmp == NULL)
		ft_putstr("gen == NULL");
	ft_putstr("\n\n\n\n");
	while (tmp)
	{
		if (tmp->type == 0)
			ft_putendl("GENESIS");
		else if(tmp->type == -1)
			ft_putendl("Large block");
		else
		{

			ft_putstr("BLOCK TYPE == ");
			ft_putnbr(tmp->type);
			ft_putchar('\n');
			print_state(tmp);
			ft_putchar('\n');
		}
			tmp = tmp->next;
	}
	ft_putnbr(j);
	j++;
}

void	print_state(t_zone *zone)
{
	int i = 0;
	int count = 0;
	while (i < 100)
	{
		if (zone->state[i] == 1)
			count++;
		ft_putnbr(zone->state[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("\n Count: ");
	ft_putnbr(count);
	ft_putendl("/100");
}
