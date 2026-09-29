/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan-my <achan-my@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:15:21 by username          #+#    #+#             */
/*   Updated: 2026/07/07 14:35:40 by achan-my         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	my_pixel_put(struct s_fractal *f, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * f->line_len) + (x * (f->bpp / 8));
	dst = f->addr + offset;
	*(unsigned int *) dst = color;
}

static void	calculate_pixel(struct s_fractal *f, int x, int y)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	// Map screen pixels to the complex plane
	if (f->type == 1) // Julia
	{
		zx = ((x - WIDTH / 2.0) * (4.0 / WIDTH)) / f->zoom + f->shift_x;
		zy = ((y - HEIGHT / 2.0) * (4.0 / HEIGHT)) / f->zoom + f->shift_y;
	}
	else // Mandelbrot: c is the pixel, z starts at 0
	{
		f->c_re = ((x - WIDTH / 2.0) * (4.0 / WIDTH)) / f->zoom + f->shift_x;
		f->c_im = ((y - HEIGHT / 2.0) * (4.0 / HEIGHT)) / f->zoom + f->shift_y;
		zx = 0.0;
		zy = 0.0;
	}
	i = 0;
	while (i < f->max_iter && (zx * zx + zy * zy) < 4.0)
	{
		tmp = (zx * zx) - (zy * zy) + f->c_re;
		zy = 2.0 * zx * zy + f->c_im;
		zx = tmp;
		i++;
	}
	if (i == f->max_iter)
		my_pixel_put(f, x, y, 0x000000);
	else
		my_pixel_put(f, x, y, (i * 255 / f->max_iter) << 16 | (i * 100) << 8);
}

void	render_julia(struct s_fractal *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
