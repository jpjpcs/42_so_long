/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:45:11 by joaosilva         #+#    #+#             */
/*   Updated: 2024/03/27 16:23:33 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_paths_rec(t_game *game, t_point current, char **grid)
{
	static int	collect = 0;
	static int	exit = 0;

	if (grid[current.y][current.x] == EXIT)
		exit++;
	if (grid[current.y][current.x] == COLLECT)
		collect++;
	if (grid[current.y][current.x] == WALL)
		return (0);
	grid[current.y][current.x] = WALL;
	check_paths_rec(game, (t_point){current.x, current.y - 1}, grid);
	check_paths_rec(game, (t_point){current.x, current.y + 1}, grid);
	check_paths_rec(game, (t_point){current.x - 1, current.y}, grid);
	check_paths_rec(game, (t_point){current.x + 1, current.y}, grid);
	if (collect == game->collect && exit == 1)
		return (1);
	return (0);
}

static void	check_paths(t_game *game)
{
	char	**grid;
	int		i;
	int		exit_reached;

	grid = ft_calloc(game->map.rows + 1, sizeof(char *));
	if (!grid)
		exit_error(game, "Couldn't allocate memory.");
	i = -1;
	while (++i < game->map.rows)
	{
		grid[i] = ft_strdup(game->map.grid[i]);
		if (!grid[i])
		{
			ft_free_array(grid);
			exit_error(game, "Couldn't allocate memory.");
		}
	}
	exit_reached = 0;
	exit_reached = check_paths_rec(game, game->player.current, grid);
	ft_free_array(grid);
	if (!exit_reached)
		exit_error(game, "Map has invalid path.");
}

static void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.grid[i][j] == PLAYER)
			{
				game->player_count++;
				game->player.current = (t_point){j, i};
				game->player.next = (t_point){j, i};
			}
			else if (game->map.grid[i][j] == EXIT)
				game->exit++;
			else if (game->map.grid[i][j] == COLLECT)
				game->collect++;
			else if (!ft_strchr(TILLES, game->map.grid[i][j]))
				exit_error(game, "Invalid character in map.");
		}
	}
	if (game->player_count != 1 || game->exit != 1 || game->collect < 1)
		exit_error(game, "Wrong number of players, exits or collectibles.");
}

static void	check_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.rows)
		if (game->map.grid[i][0] != WALL || game->map.grid[i][game->map.cols
			- 1] != WALL)
			exit_error(game, "Map is not surrounded by walls.");
	i = -1;
	while (++i < game->map.cols)
		if (game->map.grid[0][i] != WALL || game->map.grid[game->map.rows
			- 1][i] != WALL)
			exit_error(game, "Map is not surrounded by walls.");
}

void	check_map(t_game *game)
{
	check_walls(game);
	check_characters(game);
	check_paths(game);
}
