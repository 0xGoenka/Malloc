/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:19:52 by eleclet           #+#    #+#             */
/*   Updated: 2018/04/30 18:24:22 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int main()
{

	t_zone *ptr = NULL;
	char *p;
	char *s = "qwertyuiopsdfghjklzxcvbnmquireuaskdjczxmnkm,hnckjashdkjashdkasjdlkasjfkjdhsfkjhsdklfhsdkljfhsdkjfhksjdhfklsdhflkdsjhfklsdhfklsdhfkjdshfkdshkfljhsdklfjhdskjfhksdjhfkjsdhfjkdshfdskjdffdfdffffffffffssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";

	int t = 0;
	while (t < 130)
	{
		p = ft_malloc(10);
		if (p == NULL)
		{
			ft_putstr("malloc failed");
			return 0;
		}
		ft_memccpy(p,s,0,10);
		t++;
	}

	return (0);
}
