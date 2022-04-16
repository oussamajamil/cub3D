/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:21:39 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/16 18:13:40 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	char	*line;
	char	*var1;
	char	*var2;
	char	**files;
	int		width;
	int		pos;
	int		height;
	char	*file_no;
	char	*file_so;
	char	*file_we;
	char	*file_ea;
	int		file_c;
	int		file_f;
}	t_map;

char	*get_get_next_line(int fd);
char	**ft_split(char *s, char c);
void	ft_initial(t_map *data);
char	*get_next_line(int fd);
char	*get_line(int fd);
char	*ft_stjoin(char	*str1, char	*str2);
int		ft_strlen(const	char *str);
char	*ft_strdup(const	char *s1);
void	get_width_height(t_map	*data);
int		ft_check_line(char	*line);
int		ft_check_map_horizontal(char	**map, int width, int height);
void	ft_remplir_map(t_map	*data);
void	ft_free(t_map	*data);
void	ft_initiale(t_map	*data);
int		ft_atoi(const char	*str);
int		ft_strcmp(char	*s1, char	*s2);
void	ft_free_double_pointer(char	**str);
void	ft_check_extens_map(char	*str);
int		ft_check_file_exist(char	*str);
void	ft_divis_line(t_map	*data);
int		ft_check_map_vertical(char	**map, int width, int height);
int		ft_handel_map(char *line);
void	ft_message_and_exit(char *str);
int		ft_check_data_final(t_map *dt);
void	ft_parse_map(int nb, t_map *data, char *map);
void	ft_remplir_var(t_map *data);
void	ft_norm_remplir_var1(t_map *data, int *i, int *j, int *a);
void	ft_norm_remplir_var2(t_map *data, int *i, int *j, int *a);
void	ft_norm_remplir_var3(t_map *data, int *i, int *j, int *a);
void	ft_parse_map1(int nb, t_map *data, char *map);
void	ft_check_content_data(int nb, char *str);
void	ft_printf_data(t_map *data);
int		ft_is_number(char *str);
void	ft_hexa(int *data, char *str);
#endif
