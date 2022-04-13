/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 04:24:06 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/13 22:58:09 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>


typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_map
{
	int				width;
	int				height;
	char			**parse;
	int				collectable;
	void				*collectable_img;
	int				steps;
	int			the_exit;
	void			*the_exit_img;
	int			player;
	void			*player_img;
	void			*mlx;
	void			*win;
	void			*floor_img;
	void			*ceiling_img;
	int			collectable_x;
	int			collectable_y;
	int  			player_x;
	int  			player_y;
	int the_exit_x;
	int the_exit_y;
	int			enemy;
	void			*enemy_img;
	int			enemy_x;
	int			enemy_y;
	int		count_moves;
}					t_map;
void add_texture(t_map *map);
void	add_images(t_map *map);
void check_walls_map(t_map *map);
void	start_window(t_map *map);
int check_collectables(t_map *map);
int check_exit(t_map *map);
int check_player(t_map *map);
int elements_check(t_map *map, int i, int j);
void	add_images(t_map *map);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *str, size_t n);
int	parsing_checking_map(char *map_arg, t_map *map);
void	prepare_functions(char *map_arg);
int	check_arguments(int argc, char **argv);
void	error(char *str);
void ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strstr(char *source, char *search);
int ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t num, size_t size);
int		parsing_checking_map_2(char *map_arg, t_map *map, char *array);
 int	count_width(char *map);
char *ft_strdup(char *str);
void	free_map(t_map *map, int flag);
char *ft_substr(char   *s, unsigned int start, size_t len);
size_t ft_strlcpy(char *dest, char *src, size_t size);
int check_walls(t_map *map);
int	check_objects(t_map * map);
//gnl
char	*get_next_line(int fd);
int	ft_strlen(char *string);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *string, int n);
int check_enemy(t_map *map);
void	put_c_or_n(t_map *map, int index1, int index2);
void	put_the_floor(t_map *map, int index1, int index2);
void	put_the_ceiling(t_map *map, int index1, int index2);
void	put_the_exit(t_map *map, int index1, int index2);
void	put_the_player(t_map *map, int index1, int index2);
void	put_the_collectable(t_map *map, int index1, int index2);
void	put_the_enemy(t_map *map, int index1, int index2);


int	mouvements(int key, t_map *map);
int	exit_program(t_map *map);
int	ft_intlen(int n);
char *ft_itoa(int n);
int do_moves(t_map *map, int index1, int index2);
int		annouce_win(t_map *map);
void print_score(t_map *map);
void	ft_putnbr_fd(int n, int fd);
#endif