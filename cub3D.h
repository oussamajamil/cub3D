/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:21:39 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/03 11:00:44 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
typedef struct  s_map{
    char **map;
    char *line;
    char *var1;
    char *var2;
    char **files;
    int width;
    int pos;
    int height;
    char *file_NO;
    char *file_SO;
    char *file_WE;
    char *file_EA;
}t_map;
char *get_get_next_line(int fd);
char	**ft_split(char *s, char c);
void ft_initial(t_map *data);
#endif