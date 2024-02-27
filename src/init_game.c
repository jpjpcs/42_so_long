/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:45:37 by joaosilva         #+#    #+#             */
/*   Updated: 2024/02/26 15:58:57 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Rendering a map or Brings the peaces all together. Rendering is the finalization process of a digital image or a 3D model using computer software. It lets users bring together the visuals, from the shadows and lighting effects to the textures, and generate the final result. Rendering of a map is the process of making a visual image on the basis of raw geospatial data and tags
static void render_map(t_game *game, int y, int x)
{
    t_img	*tile;
    
    //DUVIDA: pq inicializamos como img_walls? pq temos de inicializar com alguma coisa, e essa é a primeira?
    tile = &game->img_walls; // DUVIDA:se colocar sem o & dá este erro: a value of type "t_img" cannot be assigned to an entity of type "t_img *"
    while (game->map.rows > ++y)
    {
        x = -1;
        while (game->map.cols > ++x)
        {
            if (game->map.grid[y][x] == WALL)
                tile = &game->img_walls;
            else if (game->map.grid[y][x] == SPACE)
                tile = &game->img_space;
            else if (game->map.grid[y][x] == EXIT)
                tile = &game->img_exit;
            else if (game->map.grid[y][x] == COLLECT)
                tile = &game->img_collect;
            else if (game->map.grid[y][x] == PLAYER)
                tile = &game->img_player;
            mlx_put_image_to_window (game->mlx, game->win, tile->img, x * TILE_SIZE, y * TILE_SIZE);
        }
    } 
}

static void check_textures (t_game *game)
{
    if (!game->img_walls.img || !game->img_space.img || !game->img_exit.img || !game->img_collect.img || !game->img_player.img)
    exit_error(game, "Textures loading failed.");
}

static void load_textures (t_game *game)
{
    game->img_walls.img = mlx_xpm_file_to_image(game->mlx, W_XPM, &game->x, &game->y);
    game->img_space.img = mlx_xpm_file_to_image(game->mlx, S_XPM, &game->x, &game->y);
    game->img_exit.img = mlx_xpm_file_to_image(game->mlx, E_XPM, &game->x, &game->y);
    game->img_collect.img = mlx_xpm_file_to_image(game->mlx, C_XPM, &game->x, &game->y);
    game->img_player.img = mlx_xpm_file_to_image(game->mlx, P_XPM, &game->x, &game->y);
    check_textures (game);
}

//DUVIDA: PORQUE É QUE NAO POSSO INICIAR PRIMEIRO A MLX e dps fazer load das textures antes da window?
static void init_mlx_and_textures(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        exit_error(game, "mlx initialization failed.");
    load_textures (game);
    game->win = mlx_new_window(game->mlx, game->map.cols * TILE_SIZE, game->map.rows * TILE_SIZE, "so_long");
    if (!game->win)
        exit_error(game, "window creation failed.");
}

void init_game (t_game *game)
{
    init_mlx_and_textures(game); //DÙVIDA: pq é que aqui passo game e na check_map(&game) ou mm na própria init_game(&game) passo com o &
    render_map(game, -1, -1);
}