/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:06:07 by dzui              #+#    #+#             */
/*   Updated: 2016/11/23 15:06:07 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int index, char ch))
{
	char	*res;
	int		i;

	i = 0;
	if (s)
	{
		res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!res)
			return (NULL);
		while (s[i] != '\0')
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
