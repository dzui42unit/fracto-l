/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:08:50 by dzui              #+#    #+#             */
/*   Updated: 2016/11/25 18:08:28 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t					i;
	const unsigned char		*temp_str;

	i = 0;
	temp_str = (unsigned char *)str;
	while (i < n)
	{
		if (temp_str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
