/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:55:59 by dzui              #+#    #+#             */
/*   Updated: 2016/11/22 17:07:55 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int						i;
	const unsigned char		*t_s1;
	const unsigned char		*t_s2;

	i = 0;
	t_s1 = (const unsigned char *)s1;
	t_s2 = (const unsigned char *)s2;
	if (t_s1[i] == '\0')
		return (0 - t_s2[i]);
	if (t_s2[i] == '\0')
		return (t_s1[i] - 0);
	while ((t_s1[i] != '\0') || (t_s2[i] != '\0'))
	{
		if (t_s1[i] != t_s2[i])
			return (t_s1[i] - t_s2[i]);
		i++;
	}
	return (0);
}
