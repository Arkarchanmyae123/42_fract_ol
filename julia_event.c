/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan-my <achan-my@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:14:10 by username          #+#    #+#             */
/*   Updated: 2026/07/07 14:14:35 by achan-my         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_handler(struct s_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	// Required for Minilibx-linux
	free(f->mlx);
	exit(0);
	return (0);
}

int	key_handler(int keysym, struct s_fractal *f)
{
	if (keysym == KEY_ESC)
		close_handler(f);
	return (0);
}

int	mouse_handler(int button, int x, int y, struct s_fractal *f)
{
	(void) x;
	(void) y;
	if (button == MOUSE_WHEEL_UP)
		f->zoom *= 1.1;
	else if (button == MOUSE_WHEEL_DOWN)
		f->zoom *= 0.9;
	render_julia(f);
	return (0);
}
