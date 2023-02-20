/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:57:26 by otait-ta          #+#    #+#             */
/*   Updated: 2023/02/20 10:32:16 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	ft_atof(const char *str)
{
	double	decimal;
	int		power;
	int		sign;

	decimal = ft_atoi(str);
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
	}
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	power = 1;
	while (*str && ft_isdigit(*str))
	{
		decimal = decimal * 10 + (*str - '0');
		str++;
		power *= 10;
	}
	return (sign * (decimal / power));
}

void	print_and_exit(char *d)
{
	if (*d == 'd')
		ft_putstr_fd("Error can you Enter mandelbrot or julia please ?\n", 2);
	else
		ft_putstr_fd(d, 2);
	exit(0);
}

void	is_less_than_tow(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	if (av[i] == '2' && av[i + 1] != '\0')
		print_and_exit(" less than 2 pleas");
	if (av[i] != '0' && av[i] != '1')
		print_and_exit("Enter a number between 2 and - 1");
	if (av[++i] == '\0')
		return ;
	if (av[i] == '.')
	{
		while (av[++i] != '\0')
			if (!ft_isdigit(av[i]))
				print_and_exit("Number after comma must be a number");
	}
	else
		print_and_exit("Enter a number between 2 and - 1");
}

void	tow_axis(t_info *info)
{
	if (info->window.x == info->width / 2 || info->window.y == info->height / 2)
	{
		info->iter = 100;
		put_pixel_color(info);
	}
}