/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:23:39 by dzui              #+#    #+#             */
/*   Updated: 2016/11/23 16:35:22 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char			*res;
	unsigned int	i;

	if (s)
	{
		res = (char *)malloc(sizeof(char) * n + 1);
		if (!res)
			return (NULL);
		i = 0;
		while (i < n)
		{
			res[i] = s[start];
			i++;
			start++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
