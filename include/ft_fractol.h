/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:23:44 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/01/17 14:24:28 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../lib/MLX/mlx.h"
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_number
{
	double	x;
	double	y;
}			t_number;

typedef struct s_image
{
	void	*img;
	char	*data_addr;
	int		bpp;
	int		line_size;
	int		endian;
}			t_image;

typedef struct s_fract
{
	t_image		*img;
	void		*mlx;
	void		*win;
	int			i;
	int			max_iter;
	int			shift;
	int			checkjuliab;
	double		b1;
	double		b2;
	t_number	max;
	t_number	min;
	t_number	now;
	t_number	julia;
	void		(*eqn)(struct s_fract *);

}			t_fract;

void		go_arg(char *arg);
void		something_wrong(void);
void		go_init(t_fract *data);
void		ft_fractal(t_fract *data, int width, int height);
void		default_init(t_fract *data);
void		img_init(t_fract *data);
t_number	complex_init(double x, double y);
void		ft_mandelbrot(t_fract *data);
void		ft_julia(t_fract *data);
int			ctrl_mouse(int key, int x, int y, t_fract *data);
double		linear_interpolation(double start, double end, double zoom);
int			keymap(int key, t_fract *data);
void		shift_color(t_fract *data);
void		move_in_screen(int key, t_fract *data);
int			close_window(t_fract *data);
void		put_pixel(t_fract *data, int x, int y, int color);
int			color_init(t_fract *data);
int			ft_isspace(char c);
double		ft_atof(const char *s, double val, double power);
void		go_arg2(char *arg, const char *X, const char *Y);
int			check_arg_str(const char *s1, const char *s2);

#endif
