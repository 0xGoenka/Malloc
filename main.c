/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:21:41 by eleclet           #+#    #+#             */
/*   Updated: 2018/04/13 20:54:59 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

typedef struct s_zone
{
	char *str;
	int i;

}t_zone;


int		main()
{

	struct rlimit *r;

	t_zone  *zone;

	zone = (void*)mmap(0, sizeof(t_zone), PROT_WRITE | PROT_READ,MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("%d\n", sizeof(t_zone));
	zone->str = ft_strdup("sdksjddksj");
	zone->i = 10;
	printf("%s", zone->str);

	getrlimit(RLIMIT_DATA, r);
	printf("%llu\n",r->rlim_cur);
	printf("%llu ",r->rlim_max);
	return (0);
}
