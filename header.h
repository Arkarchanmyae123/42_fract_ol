/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan-my <achan-my@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:03:59 by username          #+#    #+#             */
/*   Updated: 2026/07/07 14:28:23 by achan-my         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800

/* MiniLibX Event Codes */
# define KEY_ESC 65307
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ON_DESTROY 17

struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	c_re;
	double	c_im;
	double	zoom;
	double	shift_x;
	double	shift_y;
	int		max_iter;
	int		type;
};

/* Prototypes */
void	render_julia(struct s_fractal *f);
int		close_handler(struct s_fractal *f);
int		key_handler(int keysym, struct s_fractal *f);
int		mouse_handler(int button, int x, int y, struct s_fractal *f);
double	ft_atof(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	put_str_fd(char *s, int fd);

#endif
