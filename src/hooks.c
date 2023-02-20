/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:22:58 by otait-ta          #+#    #+#             */
/*   Updated: 2023/02/18 12:40:43 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_click(int key, int x, int y, t_info *info)
{
	if (key == 1)
	{
		if (!ft_strcmp(info->av[1], "julia") && x >= 0 && y >= 0
			&& x <= info->width && y <= info->height)
		{
			info->c_re = (double)x / info->width;
			info->c_im = (double)y / info->height;
		}
	}
	return (1);
}

int	mouse_hook(int button, int x, int y, t_info *info)
{
	if (button == 4)
		info->zoom *= 1.1;
	if (button == 5)
		info->zoom /= 1.1;
	if (button == 1 && !ft_strcmp(info->av[1], "julia"))
		mouse_click(button, x, y, info);
	if (!ft_strcmp(info->av[1], "julia"))
		julia_start(info);
	if (!ft_strcmp(info->av[1], "mandelbrot"))
		mandel_start(info);
	return (0);
}

int	key_hook(int key, t_info *info)
{
	if (key == 123)
	{
		info->move.x -= 10;
	}
	else if (key == 124)
	{
		info->move.x += 10;
	}
	else if (key == 125)
	{
		info->move.y -= 10;
	}
	else if (key == 126)
	{
		info->move.y += 10;
	}
	else if (key == 53)
		exit(0);
	if (!ft_strcmp(info->av[1], "julia"))
		julia_start(info);
	if (!ft_strcmp(info->av[1], "mandelbrot"))
		mandel_start(info);
	return (0);
}

int	exit_handler(t_info *info)
{
	mlx_destroy_window(info->mlx.mlx_ptr, info->mlx.win_ptr);
	exit(0);
}
