/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:54:59 by dzui              #+#    #+#             */
/*   Updated: 2016/11/23 11:30:44 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	int		temp_n;
	size_t	len;

	i = 0;
	temp_n = n;
	while (temp_n-- != 0 && dest[i] != '\0')
		i++;
	len = i;
	temp_n = n - len;
	j = i;
	if (temp_n == 0)
		return (i + ft_strlen(src));
	i = 0;
	while (src[i] != '\0')
	{
		if (temp_n-- > 1)
			dest[j++] = src[i];
		i++;
	}
	dest[j] = '\0';
	return (len + ft_strlen(src));
}
