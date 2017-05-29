/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:28:46 by dzui              #+#    #+#             */
/*   Updated: 2016/11/22 15:36:58 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	int				pos;

	i = 0;
	pos = -1;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			pos = i;
		i++;
	}
	if ((str[i] == (char)c) && ((char)c == '\0'))
		return ((char *)(str + i));
	if (pos == -1)
		return (NULL);
	return ((char *)(str + pos));
}
