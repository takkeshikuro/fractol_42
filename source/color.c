/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:56:39 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/01/15 15:52:40 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

void	put_pixel(t_fract *data, int x, int y, int color)
{
	char	*dest;

	dest = data->img->data_addr + (y * data->img->line_size)
		+ x * (data->img->bpp / 8);
	*(unsigned int *)dest = color;
}

void	shift_color(t_fract *data)
{
	data->shift++;
	if (data->shift > 4)
		data->shift = 1;
}

int	color_init(t_fract *data)
{
	int		color[4];

	color[0] = 0;
	if (data->shift == 1)
	{
		color[1] = 0x5050A * data->i;
		return (color[1]);
	}
	if (data->shift == 2)
	{
		color[2] = 0x5150A * data->i;
		return (color[2]);
	}
	if (data->shift == 3)
	{
		color[3] = 0x654321 * data->i;
		return (color[3]);
	}
	if (data->shift == 4)
	{
		color[4] = 0x08ED55 * data->i;
		return (color[4]);
	}
	return (0);
}
