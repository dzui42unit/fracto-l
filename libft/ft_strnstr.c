/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:28:32 by dzui              #+#    #+#             */
/*   Updated: 2016/11/22 16:47:00 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!(*to_find))
		return ((char *)(str));
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0' && (k < n && k < ft_strlen(str)))
	{
		if (str[i] == to_find[j])
		{
			if (j == (ft_strlen(to_find) - 1))
				return ((char *)(str + k));
			j++;
		}
		else
		{
			j = 0;
			i = k++;
		}
		i++;
	}
	return (NULL);
}
