/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:47:57 by dzui              #+#    #+#             */
/*   Updated: 2017/02/27 15:48:14 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_julia(t_env *world)
{
	pthread_t	threads[THREADS];
	t_data		data[THREADS];
	int			i;

	clear_image(world);
	i = 0;
	while (i < THREADS)
	{
		data[i].w = world;
		data[i].y_st = HEIGHT / THREADS * i;
		data[i].y_end = HEIGHT / THREADS * (i + 1);
		pthread_create(&(threads[i]), NULL, draw_julia, &(data[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
	ft_draw_controls(world);
	return (0);
}

void	*draw_julia(void *arg)
{
	t_complex		z;
	t_complex		c;
	t_data			*inf;
	int				x;

	inf = (t_data*)arg;
	while (inf->y_st != inf->y_end)
	{
		x = 0;
		while (x < WIDTH)
		{
			inf->x = x;
			z.real = 0;
			z.imag = 0;
			c.real = 1.5 * (x - WIDTH / 2) / (0.5 * inf->w->zoom * WIDTH);
			c.real += inf->w->move_x;
			c.imag = (inf->y_st - HEIGHT / 2) / (0.5 * inf->w->zoom * HEIGHT);
			c.imag += inf->w->move_y;
			check_point_julia(inf, &z, &c);
			x++;
		}
		inf->y_st += 1;
	}
	pthread_exit(NULL);
}

void	check_point_julia(t_data *info, t_complex *z, t_complex *c)
{
	int		n;

	n = 0;
	while (n < info->w->iter)
	{
		z->real = c->real;
		z->imag = c->imag;
		c->real = z->real * z->real - z->imag * z->imag;
		c->real += info->w->constant.real;
		c->imag = 2.0 * z->real * z->imag + info->w->constant.imag;
		if ((c->real * c->real + c->imag * c->imag) > 4)
			break ;
		n++;
	}
	set_color(info, n);
}

void	set_color(t_data *data, int n)
{
	if (data->w->fract == 1 || data->w->fract == 2)
	{
		if (n == data->w->iter)
			data->color = (0x0080CBC4 * n / (data->w->iter));
		if (n < data->w->iter / 2)
			data->color = (0x0000838f * n / (data->w->iter * 2));
		else
			data->color = 0x0080D8FF;
	}
	else
	{
		if (n == data->w->iter)
			data->color = (0x00FFF176 * n / (data->w->iter));
		if (n < data->w->iter / 2)
			data->color = (0x00FBC02D * n / (data->w->iter * 5));
		else
			data->color = 0x004DD0E1;
	}
	put_pixel_to_img(data->w, data->x, data->y_st, data->color);
}
