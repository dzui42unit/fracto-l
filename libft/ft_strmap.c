/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:53:17 by dzui              #+#    #+#             */
/*   Updated: 2016/11/23 15:02:47 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char ch))
{
	char	*res;
	int		i;

	if (s)
	{
		i = 0;
		res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!res)
			return (NULL);
		while (s[i] != '\0')
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
