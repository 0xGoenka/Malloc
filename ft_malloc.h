/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:12:44 by eleclet           #+#    #+#             */
/*   Updated: 2018/04/12 18:24:52 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#include "libft/libft.h"
#include <stdio.h>
#include <sys/mman.h>
#include <sys/ressource.h>

typedef		struct	s_gen
{
	
}			t_gen;

typedef		struct	s_zone
{
	char		type;
	int		len;
	int		state[100];
	struct s_zone 	*prev;
	struct s_zone 	*next;
	void		*data;
}			t_zone;

typedef		struct	s_block
{
	int		len;
	
}			t_block;

void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	*ft_realloc(void *ptr, size_t size);

void	*getmem(size_t size);


t_zone	*gen_init(t_zone *gen);

#endif
