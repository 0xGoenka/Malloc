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

	t_zone *ptr = NULL;
	char *p;
	char *pt;
	char *s = "qwertyuiopsdfghjklzxcvbnmquireuaskdjczxmnkm,hnckjasssshdkjashdkasjdlkasjfkjdhsfkjhsdklfhsdkljfhsdkjfhksjdhfklsdhflkdsjhfklsdhfklsdhfkjdshfkdshkfljhsdklfjhdskjfhksdjhfkjsdhfjkdshfdskjdffdfdffffffffffssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";


	int t = 0;
	while (t < 5)
	{
		p = ft_malloc(10);
		if (p == NULL)
		{
			ft_putstr("malloc failed");
			return 0;
		}

		pt = ft_memcpy(p, s, 1);
		ft_free(p);
		t++;
	}
	return (0);
}
