/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:28:06 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/01/15 08:21:35 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

double	linear_interpolation(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	ctrl_mouse(int key, int x, int y, t_fract *data)
{
	t_number	mouse;
	double		zoom;

	mouse.x = (data->min.x + x * ((data->max.x - data->min.x) / 750));
	mouse.y = (data->max.y - y * ((data->max.y - data->min.y) / 750));
	if (key == 5)
		zoom = 1.2;
	else if (key == 4)
		zoom = 0.8;
	else
		zoom = 1.0;
	data->min.x = linear_interpolation(mouse.x, data->min.x, zoom);
	data->min.y = linear_interpolation(mouse.y, data->min.y, zoom);
	data->max.x = linear_interpolation(mouse.x, data->max.x, zoom);
	data->max.y = linear_interpolation(mouse.y, data->max.y, zoom);
	ft_fractal(data, 750, 750);
	return (0);
}
