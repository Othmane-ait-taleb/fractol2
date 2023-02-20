/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:25:24 by otait-ta          #+#    #+#             */
/*   Updated: 2023/02/18 14:18:58 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_init(t_info *info)
{
	info->coordinates.min_re = -1;
	info->coordinates.max_re = 1;
	info->coordinates.min_im = -1;
	info->coordinates.max_im = 1;
	info->zoom = 0.6;
}

void	mandel_start(t_info *info)
{
	info->window.y = 0;
	while (info->window.y < info->height)
	{
		info->window.x = 0;
		while (info->window.x < info->width)
		{
			info->iter = 0;
			pxl_to_mandelbrotmap(info);
			iter_to_max(info);
			put_pixel_color(info);
			tow_axis(info);
			info->window.x++;
		}
		info->window.y++;
	}
	my_mlx_hook(info);
}
