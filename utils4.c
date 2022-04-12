/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookprom12020 <macbookprom12020@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:25:26 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/12 02:01:58 by macbookprom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_check_extens_map(char *str)
{
    char **res = ft_split(str,'.');
    if(ft_strcmp(res[1],"cub") != 0)
    {
        printf("error map\n");
        ft_free_double_pointer(res);
        exit(0);
    }
    else
        ft_free_double_pointer(res);
}

int ft_check_file_exist(char *str)
{
    int fd = open(str,O_RDONLY);
    if (fd < 0)
        return(-1);
    close(fd);
    return(0);
}

void ft_divis_line(t_map *data)
{
    int i;
    int j;
    int l;

    i = -1;
    j = 0;
    data->var1 = malloc(sizeof(char) * (data->pos + 1));
    if (data->var1 == NULL)
        return;
    while (++i < data->pos)
        data->var1[i] = data->line[i];
    data->var1[i] = 0;
    l = ft_strlen(data->line) - data->pos;
    data->var2 = malloc(sizeof(char) * (l + 1));
    if (data->var2 == NULL)
        return;
    while (j < l - 1)
    {
        data->var2[j] = data->line[i];
        i++;
        j++;
    }
    data->var2[j] = 0;
}

int ft_check_map_vertical(char **map, int width, int height)
{
    int i;
    int j;

    j = -1;
    while (++j < width)
    {
        i = 0;
        while (i < height)
        {
            while (i < height && map[i][j] == ' ')
                i++;
            if (i == height)
                break;
            if (map[i][j] != '1')
                return -1;
            while (i < height && map[i][j] != ' ')
                i++;
            if (map[i - 1][j] != '1')
                return -1;
            while (i < height && map[i][j] == ' ')
                i++;
        }
    }
    return (0);
}