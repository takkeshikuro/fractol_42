/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:37:50 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/01/15 10:07:35 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

void	ft_mandelbrot(t_fract *data)
{
	t_number	math;

	math = complex_init(data->now.x, data->now.y);
	data->i = 0;
	while ((math.x * math.x) + (math.y * math.y) <= 4.0
		&& data->i < data->max_iter)
	{
		math = complex_init((math.x * math.x) - (math.y * math.y) + \
		data->now.x, 2 * math.x * math.y + data->now.y);
		data->i++;
	}
}

void	ft_julia(t_fract *data)
{
	t_number	math;

	math = complex_init(data->now.x, data->now.y);
	data->i = 0;
	while ((math.x * math.x) + (math.y * math.y) <= 4
		&& data->i < data->max_iter)
	{
		math = complex_init((math.x * math.x) - (math.y * math.y)
				+ data->julia.x, \
				2.0 * math.x * math.y + data->julia.y);
		data->i++;
	}
}
