/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_4_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:59:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/01/19 19:16:44 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

double	ft_atof(const char *s, double val, double power)
{
	int	sign;

	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
	{
		val = 10.0 * val + (*s - '0');
		s++;
	}
	if (*s == '.')
	{
		s++;
		while (ft_isdigit(*s))
		{
			val = 10.0 * val + (*s - '0');
			power *= 10.0;
			s++;
		}
	}
	return (sign * val / (power));
}

int	check_arg_str(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_isspace(s1[i]) && s1[i] != '+' && s1[i] != '-' && s1[i] != '.')
		{
			if (ft_isdigit(s1[i]) == 0)
				return (0);
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!ft_isspace(s2[i]) && s2[i] != '+' && s2[i] != '-' && s2[i] != '.')
		{
			if (ft_isdigit(s2[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void	go_arg2(char *arg, const char *X, const char *Y)
{
	t_fract	*data;
	double	val4atof;
	double	power4atof;

	val4atof = 0.0;
	power4atof = 1.0;
	data = malloc(sizeof(t_fract));
	if (!data)
		exit(1);
	if (!(ft_strncmp(arg, "julia", 5)) && ft_strlen(arg) == 5)
	{
		if (!check_arg_str(X, Y))
		{
			free (data);
			something_wrong();
		}
		data->eqn = &ft_julia;
		data->checkjuliab = 1;
		data->b1 = ft_atof(X, val4atof, power4atof);
		data->b2 = ft_atof(Y, val4atof, power4atof);
		go_init(data);
	}
	else
		free (data);
	something_wrong();
}
