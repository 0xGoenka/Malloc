/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:12:44 by eleclet           #+#    #+#             */
/*   Updated: 2017/07/08 16:48:43 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#include "libft/libft.h"

void	*ft_malloc(size_t size);
void	t_free(void *ptr);
void	*ft_realloc(void *ptr, size_t size);

#endif
