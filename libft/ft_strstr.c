/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:43:47 by dzui              #+#    #+#             */
/*   Updated: 2016/11/22 16:03:17 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!(*to_find))
		return ((char *)(str));
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0' && k < ft_strlen(str))
	{
		if (str[i] == to_find[j])
		{
			if (j == ft_strlen(to_find) - 1)
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
