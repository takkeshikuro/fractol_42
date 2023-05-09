/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyB_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:57:23 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/01/15 15:03:16 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

void	move_in_screen(int key, t_fract *data)
{
	t_number	tmp;

	tmp = complex_init((data->max.x - data->min.x) * 0.05, \
						(data->max.y - data->min.y) * 0.05);
	if (key == 65361)
	{
		data->min.x = data->min.x - tmp.x;
		data->max.x = data->max.x - tmp.x;
	}
	else if (key == 65363)
	{
		data->min.x = data->min.x + tmp.x;
		data->max.x = data->max.x + tmp.x;
	}
	else if (key == 65364)
	{
		data->min.y = data->min.y - tmp.y;
		data->max.y = data->max.y - tmp.y;
	}
	else if (key == 65362)
	{
		data->min.y = data->min.y + tmp.y;
		data->max.y = data->max.y + tmp.y;
	}
}

int	close_window(t_fract *data)
{
	ft_putendl_fd("goodbye :)", 1);
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free (data->mlx);
	free (data->img);
	free (data);
	exit (1);
	return (0);
}

int	keymap(int key, t_fract *data)
{
	if (key == 65307)
		close_window(data);
	if (key == 32)
		default_init(data);
	if (key == 99)
		shift_color(data);
	if (key == 65362 || key == 65364 || key == 65361 || key == 65363)
		move_in_screen(key, data);
	if (key == 112)
			data->max_iter *= 1.2;
	if (key == 111)
			data->max_iter *= 0.8;
	ft_fractal(data, 750, 750);
	return (0);
}
