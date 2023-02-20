/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:33:54 by otait-ta          #+#    #+#             */
/*   Updated: 2023/02/20 09:59:41 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pxl_to_juliamap(t_info *info)
{
	info->fractal.x = (info->zoom * ((info->window.x - info->move.x
					- (info->width / 2)) / (info->width / 2))
			* (info->coordinates.max_re - info->coordinates.min_re));
	info->fractal.y = info->zoom * ((info->window.y + info->move.y
				- (info->height / 2)) / (info->height / 2))
		* (info->coordinates.max_im - info->coordinates.min_im);
}

void	pxl_to_mandelbrotmap(t_info *info)
{
	pxl_to_juliamap(info);
	info->c_re = info->fractal.x;
	info->c_im = info->fractal.y;
}

void	iter_to_max(t_info *info)
{
	double	tmp_x;
	double	tmp_y;

	while (info->iter < info->max_iterations)
	{
		tmp_x = info->fractal.x * info->fractal.x - info->fractal.y
			* info->fractal.y;
		tmp_y = 2 * info->fractal.x * info->fractal.y;
		info->fractal.x = tmp_x + info->c_re;
		info->fractal.y = tmp_y + info->c_im;
		if ((info->fractal.x * info->fractal.x + info->fractal.y
				* info->fractal.y) > sqrt(2 * pow(2, 2)))
			break ;
		info->iter++;
	}
}

void	put_pixel_color(t_info *info)
{
	if (info->iter == info->max_iterations)
		info->iter = 0;
	info->pxl_index = (info->img_data.size_line * info->window.y)
		+ info->window.x * 4;
	info->img_data.addr[info->pxl_index] = info->iter * 30;
	info->img_data.addr[info->pxl_index + 1] = info->iter * 1;
	info->img_data.addr[info->pxl_index + 2] = info->iter * 5;
	info->img_data.addr[info->pxl_index + 3] = 10;
}
