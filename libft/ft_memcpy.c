/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:09:54 by dzui              #+#    #+#             */
/*   Updated: 2016/11/25 18:11:19 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *src, const void *dest, size_t n)
{
	unsigned long	i;
	char			*temp_src;
	const char		*temp_dest;

	i = 0;
	temp_src = src;
	temp_dest = dest;
	while (i < n)
	{
		temp_src[i] = temp_dest[i];
		i++;
	}
	return (src);
}
