/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:12:44 by eleclet           #+#    #+#             */
/*   Updated: 2018/05/02 19:58:32 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#include "libft/libft.h"
#include <stdio.h>
#include <sys/mman.h>
#include <sys/resource.h>

typedef		struct	s_zone
{
	int		type;
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


t_zone	*gen_init();

int	find_type(size_t size);
int	type_to_size(char type);
void	*find_storage(t_zone *zone);
void	*find_zone(char type, t_zone *gen);
void	*create_zone(t_zone *gen, char type, size_t size);
void	show_mem(t_zone *gen);
void	print_state(t_zone *zone);
t_zone	*getstatic(void);


#endif
