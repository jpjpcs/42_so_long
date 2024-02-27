/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:44:03 by joaosilva         #+#    #+#             */
/*   Updated: 2024/02/26 15:45:11 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//create map é mais map_import_from_file ou map_load_from_file, 
//e o create map será mais o render_map

//Opçoes:
/* Get grid dimensions
Load grid from file
Check map

//Poderia dividir ainda mais
check_grid ou get_map_dimensions
get_grid ou load_grid_to_game
chek_map */
static void create_map (t_game *game, char *file)
{
    int		fd;
	char	*line;
	int		i;

	game->map.grid = ft_calloc(game->map.rows + 1, sizeof(char *)); //O calloc retorna um ponteiro para ponteiros...reserva espaço de memória (aponta para a primeira posição do bloco de memória, e o que define qts passos/espaços posso dar/andar é o malloc ou calloc através do size que lhe passamos...ou seja, se for 2 char já sabe que anda 2 bytes ou seja 16 bits po lado. se for int já sabe que são 4 bytes ou seja 32 bits) onde vou colocar os ponteiros das linhas todos seguidinhos, o que me permite iterar entre eles. seguidamente são criados os ponteiros para as linhas, no while seguinte, que faz calloc usando a função trim e retira o \n a seguir. 
	if (!game->map.grid)
		exit_error(NULL, "Couldn't allocate memory.");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(game, "Couldn't open requested file.");
	line = get_next_line(fd);
	i = -1;
	while (line)
	{
		game->map.grid[++i] = ft_strtrim(line, "\n"); //o calloc acima aponta para primeiro ponteiro. este while cria cada ponteiro da limha. Logo num mapa com 5 linhas, ele faz 5 mallocs (a trim usa malloc e não calloc). só preciso de saber o num. de rows. ele aponta para o ponteiro que está a apontar para o primeiro caracter da linha. As colunas são os restantes caractéres da str.
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int check_get_grid_dimensions (t_game *game, char *file)
{
    int fd;
    int		rectangle;
	char *line;

	fd = open(file, O_RDONLY);
	//DUVIDA: tenho de colocar sempre esta verificação cada vez que abro o fd? ou basta ter no check_file_open no main?
	if (fd == -1)
		exit_error(NULL, "Couldn't open requested file.");
    line = get_next_line (fd);
	// em vez de (ft_strclen(line, '\n') utilizei ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n')
	// retira o último \n ao ler com o strlen
	game->map.cols = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
    if (!game->map.cols)
		exit_error(NULL, "Map is empty.");
    game->map.rows = 0; //podíamos verificar a quantidade de rows.deveria ser 3 para o mapa ter à volta walls. mas aqui não verifico isso pq a função só pode ter 25 linhas.
    rectangle = TRUE;
    while (line && ++game->map.rows)
	{
		if ((ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n') != (size_t)game->map.cols))
			rectangle = FALSE;
		free(line);
		line = get_next_line(fd);
	}
	if (rectangle == FALSE)
		exit_error(NULL, "Map is not a rectangle.");
	close(fd);
	return (rectangle);
}

void so_long (char *file)
{
    t_game game;

    ft_bzero (&game, sizeof(t_game));
	//mudei o nome de check_get_grid para check_get_grid_dimensions
	//check_and_create_map
	check_get_grid_dimensions (&game, file); // aqui tinha if (!check_get_grid_dimensions (&game, file))
													//exit_error(NULL, "Map is not a rectangle."); 
													//aqui envia-se o game e o file de forma a retornar o valor do retangulo, senão retorna o endereço da função, e esse é sempre verdadeiro.
    create_map (&game, file);
    check_map(&game);
    init_game(&game);
    //void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, exit_esc, &game);
	mlx_loop(game.mlx);
}
