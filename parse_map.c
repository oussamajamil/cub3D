/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:02:08 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/03 23:02:48 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
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

int ft_handel_map(char *line)
{
    int pos;
    int i;
    int a;

    pos = -1;
    i = 0;
    while (line[i])
    {
        while (line[i] != '\n' && line[i] != '1' && line[i] != '0')
            i++;
        if (line[i] == '\n')
        {
            while (line[i] == '\n')
            {
                i++;
            }

            pos = i;
            i++;
            while (line[i] == ' ')
                i++;
            if (line[i] == '1' || line[i] == '0')
                return pos;
        }
        i++;
    }
    return (-1);
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

void ft_remplir_var(t_map *data)
{
    int i;
    int j;
    int k;

    i = -1;
    while (data->files[++i])
    {
        j = -1;
        while (data->files[i][++j])
        {
            while (data->files[i][j] == ' ')
                j++;
            if (data->files[i][j] == 'N' && data->files[i][j + 1] == 'O')
            {
                j += 2;
                while (data->files[i][j] == ' ')
                    j++;
                data->file_NO = ft_strdup(&data->files[i][j]);
            }
            if (data->files[i][j] == 'S' && data->files[i][j + 1] == 'O')
            {
                j += 2;
                while (data->files[i][j] == ' ')
                    j++;
                data->file_SO = ft_strdup(&data->files[i][j]);
            }
            if (data->files[i][j] == 'W' && data->files[i][j + 1] == 'E')
            {
                j += 2;
                while (data->files[i][j] == ' ')
                    j++;
                data->file_WE = ft_strdup(&data->files[i][j]);
            }
            if (data->files[i][j] == 'E' && data->files[i][j + 1] == 'A')
            {
                j += 2;
                while (data->files[i][j] == ' ')
                    j++;
                data->file_EA = ft_strdup(&data->files[i][j]);
            }
        }
    }
}

int main()
{
    t_map data;
    int fd;

    ft_initiale(&data);
    fd = open("txt.txt", O_RDONLY);
    data.line = get_next_line(fd);
    data.pos = ft_handel_map(data.line);
    if (data.pos == -1)
    {
        printf("error1");
        return 0;
    }
    ft_divis_line(&data);
    if (data.var1 == NULL || data.var2 == NULL)
    {
        printf("error2");
        return 0;
    }
    if (ft_check_line(data.var2) == -1)
    {
        printf("error3");
        return 0;
    }

    data.map = ft_split(data.var2, '\n');
    get_width_height(&data);
    ft_remplir_map(&data);
    if (ft_check_map_horizontal(data.map, data.width, data.height) == 0 && ft_check_map_vertical(data.map, data.width, data.height) == 0)
    {
        data.files = ft_split(data.var1, '\n');
        ft_remplir_var(&data);
    }
    else
        printf("error");
}