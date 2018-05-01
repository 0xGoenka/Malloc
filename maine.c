/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:19:52 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/01 18:58:30 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int main()
{

	t_zone *ptr = NULL;
	char *p;
	char *pt;
	char *s = "qwertyuiopsdfghjklzxcvbnmquireuaskdjczxmnkm,hnckjasssshdkjashdkasjdlkasjfkjdhsfkjhsdklfhsdkljfhsdkjfhksjdhfklsdhflkdsjhfklsdhfklsdhfkjdshfkdshkfljhsdklfjhdskjfhksdjhfkjsdhfjkdshfdskjdffdfdffffffffffssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";


	int t = 0;
	while (t < 100000)
	{
		p = ft_malloc(t);
		if (p == NULL)
		{
			ft_putstr("malloc failed");
			return 0;
		}

		pt = ft_memcpy(p, s, 1);
		t++;
	}
	return (0);
}
