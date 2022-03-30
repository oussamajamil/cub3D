/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:19:04 by ojamil            #+#    #+#             */
/*   Updated: 2022/03/30 17:15:08 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_strlen(const char *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_stjoin(char *str1, char *str2)
{
    int l;
    char *result;
    int i;
    int j;

    result = NULL;
    i = 0;
    j = 0;
    if (!str1)
    {
        str1 = malloc(1);
        if (!str1)
            return (NULL);
        str1[0] = '\0';
    }
    l = ft_strlen(str1) + ft_strlen(str2);
    result = malloc(sizeof(char) * (l + 1));
    if (!result)
        return (NULL);
    while (str1[i])
    {
        result[i] = str1[i];
        i++;
    }
    while (str2[j])
    {
        result[i + j] = str2[j];
        j++;
    }
    result[i + j] = '\0';
    return (result);
}

char *get_line(int fd)
{
    char *line;
    char *buffer;
    int a;

    line = NULL;
    buffer = NULL;
    buffer = malloc(sizeof(char) * 2);
    a = 1;
    while (a > 0)
    {
        a = read(fd, buffer, 1);
        if (a < 0)
            return (NULL);
        else if (a == 0)
        {
            free(buffer);
            return (line);
        }
        else
        {
            buffer[1] = '\0';
            line = ft_stjoin(line, buffer);
        }
    }
    free(buffer);
    return (line);
}

char *get_next_line(int fd)
{
    char *line;

    if (fd < 0)
        return (NULL);
    line = get_line(fd);
    if (!line)
        return (NULL);
    return (line);
}

void get_width_height(char **map, int *width, int *height)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (*width < ft_strlen(map[i]))
            *width = ft_strlen(map[i]);
        i++;
    }
    *height = i;
}

int ft_check_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '\n' && line[i + 1] == '\n')
            return (-1);
        i++;
    }
    return (0);
}
char *ft_strdup(const char *s1)
{
    int i;
    int l;
    char *str;

    i = 0;
    l = ft_strlen(s1);
    str = malloc(sizeof(char) * (l + 1));
    if (!str)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

void ft_remplir_map(char **map, int width, int height)
{
    int i;
    int j;
    char *buffer;

    i = 0;
    j = 0;
    buffer = malloc(sizeof(char) * (width + 1));
    if (!buffer)
        return;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (j < ft_strlen(map[i]))
                buffer[j] = map[i][j];
            else
                buffer[j] = ' ';
            j++;
        }
        buffer[j] = '\0';
        free(map[i]);
        map[i] = ft_strdup(buffer);
        i++;
    }
    free(buffer);
}

int ft_check_map_horizontal(char **map, int width, int height)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while (i < height)
    {
        j = 0;
        while (map[i][j])
        {
            while (map[i][j] == ' ')
            {
                j++;
            }
            if (!map[i][j])
            {
                break;
            }
            if (map[i][j] != '1')
            {
                printf("i ama here1 i : %d  j : %d \n", i, j);
                return (-1);
            }
            else
            {
                while (map[i][j] != ' ' && map[i][j] != '\0')
                {
                    j++;
                }
                if (map[i][j - 1] != '1' && map[i][j] != '\0')
                {
                    printf("i am here2\n");
                    return (-1);
                }
            }
            j++;
        }
        i++;
    }
    return (0);
}

int ft_check_map_vertical(char **map, int width, int height)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < width)
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
        j++;
    }
    return (0);
}

int main()
{
    int width;
    int height;
    char *line;
    char **map;

    height = 0;
    width = 0;
    int fd = open("txt.txt", O_RDONLY);
    line = get_next_line(fd);
    if (ft_check_line(line) == -1)
    {
        write(1, "error\n", 6);
        return (0);
    }
    else
    {
        map = ft_split(line, '\n');
        get_width_height(map, &width, &height);
        ft_remplir_map(map, width, height);
        if (ft_check_map_horizontal(map, width, height) == 0 && ft_check_map_vertical(map, width, height) == 0)
            write(1, "OK", 2);
        else
            write(1, "error\n", 6);
    }
}
