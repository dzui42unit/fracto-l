/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:44:45 by dzui              #+#    #+#             */
/*   Updated: 2016/11/25 15:47:59 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	print_nb(int n)
{
	int		pow;
	int		init;
	char	res;

	init = n;
	pow = 1;
	while ((init /= 10) != 0)
		pow *= 10;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	while (pow != 0)
	{
		res = ((n / pow) % 10) + '0';
		write(1, &res, 1);
		pow /= 10;
	}
}

void			ft_putnbr(int n)
{
	if (n != -2147483648)
		print_nb(n);
	else
	{
		write(1, "-", 1);
		print_nb(2147483);
		print_nb(648);
	}
}
