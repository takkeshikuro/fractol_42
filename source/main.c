/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:31:54 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/01/19 19:19:35 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

void	ft_fractal(t_fract *data, int width, int height)
{
	int			x;
	int			y;
	t_number	scale;

	scale = complex_init((data->max.x - data->min.x) / width, \
							(data->max.y - data->min.y) / height);
	y = 0;
	while (y < height)
	{
		data->now.y = data->max.y - y * scale.y;
		x = 0;
		while (x < width)
		{
			data->now.x = data->min.x + x * scale.x;
			data->eqn(data);
			if (data->i < data->max_iter)
				put_pixel(data, x, y, color_init(data));
			else
				put_pixel(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 2);
}

void	go_init(t_fract *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, 750, 750, "fract'ol");
	if (!data->win)
		exit(1);
	img_init(data);
	default_init(data);
	mlx_hook(data->win, 2, 1L << 0, &keymap, data);
	mlx_mouse_hook(data->win, &ctrl_mouse, data);
	mlx_hook(data->win, 17, 1L << 17, &close_window, data);
	ft_fractal(data, 750, 750);
	mlx_loop(data->mlx);
}

void	something_wrong(void)
{
	ft_putendl_fd("------------------------------", 1);
	ft_putendl_fd("How to use: ./fractol :", 1);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Available Fractals :", 1);
	ft_putendl_fd("  ~ Mandelbrot = ./fractol mandelbrot", 1);
	ft_putendl_fd("  ~ Julia = ./fractol julia", 1);
	ft_putendl_fd("  ~ other Julia = ./fractol julia 'value x' 'value y'", 1);
	ft_putendl_fd("(julia's varient)", 1);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Mouse :", 1);
	ft_putendl_fd("Zoom-in / zoom-out : scroll", 1);
	ft_putendl_fd("Keys :", 1);
	ft_putendl_fd("use arrows to move into the window", 1);
	ft_putendl_fd("~ O and P to increase or decrease iterations", 1);
	ft_putendl_fd("~ C to shift colors", 1);
	ft_putendl_fd("~ SPACE to reset the fractal at start", 1);
	ft_putendl_fd("~ ESC to quit the program\n", 1);
	ft_putendl_fd("------------------------------", 1);
	exit(0);
}

void	go_arg(char *arg)
{
	t_fract	*data;

	data = malloc(sizeof(t_fract));
	if (!data)
		exit(1);
	if (!(ft_strncmp(arg, "mandelbrot", 10)) && ft_strlen(arg) == 10)
	{
		data->eqn = &ft_mandelbrot;
		data->checkjuliab = 2;
		go_init(data);
	}
	else if (!(ft_strncmp(arg, "julia", 5)) && strlen(arg) == 5)
	{
		data->eqn = &ft_julia;
		data->checkjuliab = 0;
		go_init(data);
	}
	free (data);
	something_wrong();
}

int	main(int ac, char **av)
{
	if (ac == 2)
		go_arg(av[1]);
	if (ac == 4)
		go_arg2(av[1], av[2], av[3]);
	else
		something_wrong();
	return (0);
}
