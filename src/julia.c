/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:44:55 by otait-ta          #+#    #+#             */
/*   Updated: 2023/02/20 10:28:39 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_info *info)
{
	info->coordinates.min_re = -2;
	info->coordinates.max_re = 2;
	info->coordinates.min_im = -2;
	info->coordinates.max_im = 2;
	if (info->ac == 2)
	{
		info->c_re = -0.687;
		info->c_im = -0.312;
	}
	else
	{
		info->c_re = ft_atof(info->av[2]);
		info->c_im = ft_atof(info->av[3]);
	}
	info->zoom = 0.6;
}

void	julia_start(t_info *info)
{
	info->window.y = 0;
	while (info->window.y < info->height)
	{
		info->window.x = 0;
		while (info->window.x < info->width)
		{
			info->iter = 0;
			pxl_to_juliamap(info);
			iter_to_max(info);
			put_pixel_color(info);
			tow_axis(info);
			info->window.x++;
		}
		info->window.y++;
	}
	my_mlx_hook(info);
}
