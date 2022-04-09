/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:21:39 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/09 13:52:57 by ojamil           ###   ########.fr       */
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
    char **map;
    char *line;
    char *var1;
    char *var2;
    char **files;
    int  width;
    int  pos;
    int  height;
    char *file_NO;
    char *file_SO;
    char *file_WE;
    char *file_EA;
    int file_c;
    int file_f;
} t_map;
char    *get_get_next_line(int fd);
char    **ft_split(char *s, char c);
void    ft_initial(t_map *data);
char    *get_next_line(int fd);
char    *get_line(int fd);
char    *ft_stjoin(char *str1, char *str2);
int     ft_strlen(const char *str);
char    *ft_strdup(const char *s1);
void    get_width_height(t_map *data);
int     ft_check_line(char *line);
int     ft_check_map_horizontal(char **map, int width, int height);
void    ft_remplir_map(t_map *data);
void    ft_free(t_map *data);
void    ft_initiale(t_map *data);
int     ft_atoi(const char *str);
int     ft_strcmp(char *s1, char *s2);
void    ft_free_double_pointer(char **str);
void    ft_check_extens_map(char *str);
void    ft_check_file_exist(char *str);
void    ft_divis_line(t_map *data);
int     ft_check_map_vertical(char **map, int width, int height);
# endif