/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:34:06 by dzui              #+#    #+#             */
/*   Updated: 2016/11/25 18:22:12 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	print_nb(int n, int fd)
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
		write(fd, "-", 1);
		n *= -1;
	}
	while (pow != 0)
	{
		res = ((n / pow) % 10) + '0';
		write(fd, &res, 1);
		pow /= 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n != -2147483648)
		print_nb(n, fd);
	else
	{
		write(fd, "-", 1);
		print_nb(2147483, fd);
		print_nb(648, fd);
	}
}
