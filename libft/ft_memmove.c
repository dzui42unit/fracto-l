/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:28:42 by dzui              #+#    #+#             */
/*   Updated: 2016/11/25 18:14:39 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	const char		*temp_src;
	char			*temp_dest;
	char			*buff;

	i = 0;
	temp_dest = dest;
	temp_src = src;
	buff = (char *)malloc(sizeof(char) * n + 1);
	while (i < n)
	{
		buff[i] = temp_src[i];
		i++;
	}
	buff[i] = '\0';
	i = 0;
	while (i < n)
	{
		temp_dest[i] = buff[i];
		i++;
	}
	free(buff);
	return (temp_dest);
}
