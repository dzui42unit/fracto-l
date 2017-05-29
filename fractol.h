/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:41:34 by dzui              #+#    #+#             */
/*   Updated: 2017/02/21 18:07:04 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# define THREADS 32
# define WIDTH 720
# define HEIGHT 480

typedef struct	s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	double		zoom;
	int			color;
	double		move_x;
	double		move_y;
	int			iter;
	int			inter;
	char		*name;
	double		real_init;
	int			fract;
	t_complex	constant;
}				t_env;

typedef struct	s_data
{
	t_env		*w;
	int			y_st;
	int			y_end;
	int			x;
	int			color;
}				t_data;

void			event(int key_code, t_env *world);
void			set_default(t_env *world);
void			set_color(t_data *data, int n);
int				mouse_zoom(int key_code, int x, int y, t_env *world);
int				ft_julia(t_env *world);
void			*draw_julia(void *arg);
void			check_point_julia(t_data *info, t_complex *z, t_complex *c);
int				mouse_move(int x, int y, t_env *world);
void			put_pixel_to_img(t_env *world, int x, int y, int color);
int				ft_mandel(t_env *world);
void			*draw_mandel(void *args);
void			check_point_mandel(t_data *info, t_complex *z, t_complex *c);
void			clear_image(t_env *world);
int				get_red(int color);
int				get_green(int color);
int				get_blue(int color);
int				my_key_func(int key_code, t_env *world);
void			ft_print_set(void);
void			create_window(t_env *world);
int				ft_ships(t_env *world);
void			*draw_ships(void *arg);
void			check_point_ships(t_data *info, t_complex *z, t_complex *c);

#endif
