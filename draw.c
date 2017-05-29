/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:00:52 by dzui              #+#    #+#             */
/*   Updated: 2017/02/22 16:00:53 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_env *world, int x, int y, int color)
{
	char	*px;
	int		p;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		px = mlx_get_data_addr(world->img, &p, &p, &p);
		p = WIDTH * 4 * y + x * 4;
		px[p + 0] = get_blue(color);
		px[p + 1] = get_green(color);
		px[p + 2] = get_red(color);
	}
}

void	clear_image(t_env *world)
{
	char	*px;
	int		p;

	px = mlx_get_data_addr(world->img, &p, &p, &p);
	ft_bzero(px, WIDTH * HEIGHT * 4);
}

int		get_red(int color)
{
	return ((int)(((color >> 16) & 0xFF)));
}

int		get_green(int color)
{
	return ((int)(((color >> 8) & 0xFF)));
}

int		get_blue(int color)
{
	return ((int)((color) & 0xFF));
}
