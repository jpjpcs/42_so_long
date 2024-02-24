/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:28:02 by joaosilva         #+#    #+#             */
/*   Updated: 2024/02/23 20:23:25 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __linux__
#include "../minilibx-linux/mlx.h"
#elif defined(__APPLE__)
#include "../minilibx_opengl_20191021/mlx.h"
#include "../minilibx-linux/mlx.h"
#endif



#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include <fcntl.h>

# define TILE_SIZE 32
//# define SP_LEN 2 define o número de sprites usados. no caso de termos 2 players terá de ser 2. foi usado po bónus.
# define TILLES "01CEP"
# define W_XPM "textures/1.xpm"
# define S_XPM "textures/0.xpm"
# define E_XPM "textures/E.xpm"
# define C_XPM "textures/C.xpm"
# define P_XPM "textures/P.xpm"
#define TRUE 1
#define FALSE 0

typedef enum e_key
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307,
	UP = 65362,
	LEFT = 65361,
	DOWN = 65364,
	RIGHT = 65363,
}				t_key;

typedef enum e_tile
{
	WALL = '1',
	SPACE = '0',
	EXIT = 'E',
	COLLECT = 'C',
	PLAYER = 'P',
}				t_tile;

/*#typedef enum e_img_index
#{
#	FACE_LEFT = 1,
	FACE_RIGHT = 0,
}				t_img_index;
*/

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_dummies
{
	t_point	current;
	char	current_tile;
	t_point	next;
	int		img_index;
	int		collect;
}				t_dummies;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	int			moves;
	t_dummies	player;
	//t_img		img_p[SP_LEN];
	int			player_count;
	int			exit;
	int			collect;
	int			spaces;
	t_img		img_walls;
	t_img		img_space;
	t_img		img_exit;
	t_img		img_collect;
	t_img		img_player;
	int			x;
	int			y;
}				t_game;

int		exit_error(t_game *game, char *msg);
int		exit_game(t_game *game, char *msg);
int		exit_esc(t_game *game);
void	check_map(t_game *game);
void	init_game(t_game *game);
int		key_press(int keycode, t_game *game);
// void	render_move(t_game *game, char current, char next, t_dummies *dummy);
void so_long (char *file);

#endif 