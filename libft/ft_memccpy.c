/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpuy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:39:51 by dzui              #+#    #+#             */
/*   Updated: 2016/11/25 18:07:14 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*temp_dest;
	unsigned char const		*temp_src;
	size_t					i;

	temp_dest = (unsigned char*)dest;
	temp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if ((temp_dest[i] = temp_src[i]) == (unsigned char)c)
			return (temp_dest + i + 1);
		i++;
	}
	return (NULL);
}
