/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:45:43 by joaosilva         #+#    #+#             */
/*   Updated: 2024/03/12 18:50:42 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Comment: render move passa a estar dentro da key press,
// e a função key press passa para o so_long. Assim o key_press
// passa a ter 5 funções (3 do keypress,
// pq retiramos a própria key_press, e 2 do render_move.c)
// linha 35: protótipo da mlx put image to window: int mlx_put_image_to_window
// (void *mlx_ptr, void *win_ptr, void *img_ptr,int x, int y)
// DÚVIDA linha 57: pq não se pode usar o printf("Moves:")?
// temos de registar no ficheiro de saída. e se temos qual a razão?
// comment linha 62: na função check_move não colocamos if se 
// for espaço pq se o tile
// para onde o player vai for espaço, não há problema o player mover
// - se para lá.apenas temos que atualizar o mapa com a nova posição
// do player e preenchendo a posição do espaço antiga pelo player.
// DÚVIDA linha 68 e 70: pq é que aqui passamos o colectable a espaço?
// Não devíamos também ter um if para o espaço? Resposta:
// aqui passamos o collectable pq ele foi "apanhado" pelo rato,
// DÚVIDA linha 79: pq é que aqui se usa PLAYER. Pq mando p?

#include "../include/so_long.h"

static void	put_tile(t_game *game, char tile, t_point point_location)
{
	if (tile == SPACE || tile == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img_space.img,
			point_location.x * TILE_SIZE, point_location.y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit.img,
			point_location.x * TILE_SIZE, point_location.y * TILE_SIZE);
	else if (tile == COLLECT)
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect.img,
			point_location.x * TILE_SIZE, point_location.y * TILE_SIZE);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player.img,
			point_location.x * TILE_SIZE, point_location.y * TILE_SIZE);
}

static void	render_move(t_game *game, char current_tile, char next_tile,
		t_dummies *dummy)
{
	put_tile(game, current_tile, dummy->current);
	put_tile(game, next_tile, dummy->next);
}

static void	print_moves(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(++game->moves, 1);
	ft_putchar_fd('\n', 1);
}

static void	check_move(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == WALL)
		return ;
	print_moves(game);
	if (game->map.grid[y][x] == COLLECT)
	{
		game->map.grid[y][x] = SPACE;
		logo desapareceu.game->collect--;
	}
	if (game->map.grid[y][x] == EXIT && !game->collect)
		exit_game(game, "Game ended! You have eaten all cheese 🧀🧀🧀 🐁");
	if (game->map.grid[y][x] == EXIT)
		ft_printf("You´re not fat enough. You must eat all cheese. 🧀🧀🧀 ");
	game->player.next = (t_point){x, y};
	render_move(game, game->player.current_tile, PLAYER, &game->player);
	game->map.grid[game->player.current.y][game->player.current.x] = game->player.current_tile;
	game->player.current = game->player.next;
	game->player.current_tile = game->map.grid[y][x];
	game->map.grid[y][x] = PLAYER;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP)
		check_move(game, game->player.current.x, game->player.current.y - 1);
	else if (keycode == A || keycode == LEFT)
		check_move(game, game->player.current.x - 1, game->player.current.y);
	else if (keycode == S || keycode == DOWN)
		check_move(game, game->player.current.x, game->player.current.y + 1);
	else if (keycode == D || keycode == RIGHT)
		check_move(game, game->player.current.x + 1, game->player.current.y);
	else if (keycode == ESC)
		exit_game(game, "You gave up! Nice. More 🧀 🧀 🧀 cheese left for me!");
	return (0);
}
