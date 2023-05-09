/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:31:38 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/01/19 19:26:10 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

t_number	complex_init(double x, double y)
{
	t_number	complex;

	complex.x = x;
	complex.y = y;
	return (complex);
}

void	img_init(t_fract *data)
{
	data->img = malloc(sizeof(t_image));
	if (!data->img)
		exit(1);
	data->img->img = mlx_new_image(data->mlx, 750, 750);
	data->img->data_addr = mlx_get_data_addr(data->img->img, &(data->img->bpp),
			&(data->img->line_size),
			&(data->img->endian));
}

void	default_init(t_fract *data)
{
	data->max_iter = 120;
	data->min.x = -2.0;
	data->max.x = 2.0;
	data->min.y = -2.0;
	data->max.y = 2.0;
	if (data->checkjuliab == 0)
		data->julia = complex_init(0.285, 0.01);
	else if (data->checkjuliab == 1)
		data->julia = complex_init(data->b1, data->b2);
	data->shift = 1;
}
