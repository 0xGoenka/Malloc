/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:19:52 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/02 19:58:36 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int main()
{

	t_zone *gen = NULL;
	char *p;
	char *s = "qwertyuiopsdfghjklzxcvbnmquireuaskdjczxmnkm,hnckjasssshdkjashdkasjdlkasjfkjdhsfkjhsdklfhsdkljfhsdkjfhksjdhfklsdhflkdsjhfklsdhfklsdhfkjdshfkdshkfljhsdklfjhdskjfhksdjhfkjsdhfjkdshfdskjdffdfdffffffffffssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";


	int t = 0;
	while (t < 3)
	{
		p = ft_malloc(10);
		if (p == NULL)
		{
			ft_putstr("malloc failed");
			return 0;
		}

		p = ft_memcpy(p, s, 10);
		gen = getstatic();
		show_mem(gen);
		ft_free(p);
		gen = getstatic();
		show_mem(gen);
		t++;
	}

	char *l;

	
	ft_putendl("============= END ==============");
	gen = getstatic();
	ft_putendl("============= ONE ==============");
	show_mem(gen);
	l = ft_malloc(1000);
	ft_putendl("============= tWO ==============");
	gen = getstatic();
	show_mem(gen);
	ft_free(l);
	ft_putendl("============= THRE +++++++++++++");
	gen = getstatic();
	show_mem(gen);

	ft_realloc(l, 10);
	return (0);
}
