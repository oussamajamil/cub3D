/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:19:04 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/02 20:09:45 by ojamil           ###   ########.fr       */
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

void get_width_height(t_map *data)
{
    int i;

    i = 0;
    while (data->map[i])
    {
        if (data->width < ft_strlen(data->map[i]))
            data->width= ft_strlen(data->map[i]);
        i++;
    }
    data->height = i;
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

void ft_remplir_map(t_map *data)
{
    int i;
    int j;
    char *buffer;

    i = 0;
    j = 0;
    buffer = malloc(sizeof(char) * (data->width + 1));
    if (!buffer)
        return;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if (j < ft_strlen(data->map[i]))
                buffer[j] = data->map[i][j];
            else
                buffer[j] = ' ';
            j++;
        }
        buffer[j] = '\0';
        free(data->map[i]);
        data->map[i] = ft_strdup(buffer);
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
                return (-1);
            else
            {
                while (map[i][j] != ' ' && map[i][j] != '\0')
                {
                    j++;
                }
                if (map[i][j - 1] != '1' && map[i][j] != '\0')
                    return (-1);
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

int ft_handel_map(char *line)
{
    int pos;
    int i;
    int a;

    pos = -1;
    i = 0;
    while (line[i])
    {
        while (line[i]!= '\n' && line[i] != '1' && line[i]!= '0')
            i++;
        if(line[i] == '\n')
        {
            while (line[i] =='\n')
            {
                i++;
            }
            
            pos = i;
            i++;
            while (line[i] == ' ')
                i++;
            if(line[i] == '1' || line[i] =='0')
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
    
    i = 0;
    l = 0;
    j = 0;
    data->var1 = malloc(sizeof(char) * (data->pos + 1));
    if (data->var1 == NULL)
        return;
    while (i < data->pos)
    {
        data->var1[i] = data->line[i];
        i++;
    }
    data->var1[i] = 0;
    l = ft_strlen(data->line) - data->pos;
    data->var2 = malloc(sizeof(char) * (l + 1));
   if (data->var2 == NULL)
        return;
    while (j < l-1)
    {
        data->var2[j] = data->line[i];
        i++;
        j++;
    }
     data->var2[j] = 0;
}

void ft_initiale(t_map *data)
{
    data->map = NULL;
    data->height = 0;
    data->files = NULL;
    data->var1 = NULL;
    data->var2 = NULL;
    data->width = 0;
    data->pos = 0;
    data->line = NULL;
}

void ft_free(t_map *data)
{
    int i;
    char *tmp;
    
    i = 0;
    free(data->var1);
    free(data->var2);
    free(data->line);
    // while (data->map[i])
    // {
    //     tmp = data->map[i];
    //     i++;
    //     free(tmp);
    // }
    // // free(data->map);
    // i = 0;
    //  while (data->files[i])
    // {
    //    tmp = data->files[i];
    //    i++;
    //    free(tmp);
    
    // }
    // free(data->files);
}

int main()
{
    t_map data;

    ft_initiale(&data);
    int fd = open("txt.txt", O_RDONLY);
    data.line = get_next_line(fd);
    data.pos = ft_handel_map(data.line);
    if (data.pos == -1)
        printf("error1");
    else
    {
        ft_divis_line(&data);
        if (data.var1 == NULL || data.var2  == NULL)
            printf("error2");
        else
        {
            if(ft_check_line(data.var2) == -1)
                printf("error3");
            else
            {
                data.map = ft_split(data.var2, '\n');
                get_width_height(&data);
                ft_remplir_map(&data);
                if (ft_check_map_horizontal(data.map, data.width, data.height) == 0 && ft_check_map_vertical(data.map, data.width, data.height) == 0){
                    data.files = ft_split(data.var1,'\n');
                }
                else
                    printf("error");
            }
        }
    }
}
    
    // 
    // printf("%s",map[0]);
    // 
    // printf("%s",map[0]);
    // while (/* condition */)
    // {
    //     /* code */
    // }
    
    // if (ft_check_line(line) == -1)
    // {
    //     write(1, "error\n", 6);
    //     return (0);
    // }
    // else
    // {
    //     map = ft_split(line, '\n');
    //     get_width_height(map, &width, &height);
    //     ft_remplir_map(map, width, height);
    //     if (ft_check_map_horizontal(map, width, height) == 0 && ft_check_map_vertical(map, width, height) == 0)
    //         write(1, "OK", 2);
    //     else
    //         write(1, "error\n", 6);
    // }
