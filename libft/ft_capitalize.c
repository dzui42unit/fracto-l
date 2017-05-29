/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:30:22 by dzui              #+#    #+#             */
/*   Updated: 2016/12/01 16:30:29 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalize(const char *str)
{
	size_t		i;
	char		*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	if (ft_isalpha(str[i]) && ft_islower(str[i]))
		res[i] = ft_toupper(str[i]);
	i++;
	while (i < ft_strlen(str))
	{
		if (ft_isalpha(str[i]) && (!ft_isspace(str[i - 1]))
			&& (ft_isupper(str[i])))
			res[i] = ft_tolower(str[i]);
		else if (ft_isalpha(str[i]) && ft_isspace(str[i - 1])
					&& ft_islower(str[i]))
			res[i] = ft_toupper(str[i]);
		else
			res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
