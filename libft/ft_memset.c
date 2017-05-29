/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:12:03 by dzui              #+#    #+#             */
/*   Updated: 2016/11/21 12:33:45 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int n, size_t len)
{
	unsigned long	i;
	unsigned char	*temp;

	i = 0;
	temp = str;
	while (i < len)
	{
		temp[i] = (unsigned char)n;
		i++;
	}
	return (str);
}
