/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookprom12020 <macbookprom12020@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:02:08 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/12 03:11:59 by macbookprom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
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
void ft_hexa(int *data,char *str)
{
    char **res;
    int i;
    int r;

    i = 0;
    res = NULL;
    res = ft_split(str,',');
    while (res[i])
        i++;
    if (i != 3)
    {
        printf("error color");
        exit(0);
    }
    *data = ft_atoi(res[0]) *256 *256 + ft_atoi(res[1]) *256 + ft_atoi(res[0]);
    
}
void ft_norm_remplir_var1(t_map *data ,int *i,int *j,int *a)
{
      while (data->files[*i][*j] == ' ')
                *j = *j+1;
            if (data->files[*i][*j] == 'N' && data->files[*i][*j + 1] == 'O')
            {
                if (data->file_NO != NULL)
                    *a = 0;
                *j= *j + 2;
                while (data->files[*i][*j] == ' ')
                    *j= *j+1;
                data->file_NO = ft_strdup(&data->files[*i][*j]);
            }
            if (data->files[*i][*j] == 'S' && data->files[*i][*j + 1] == 'O')
            {
                if (data->file_SO)
                     *a = 0;
                *j = *j+2;
                while (data->files[*i][*j] == ' ')
                    *j = *j+1;
                data->file_SO = ft_strdup(&data->files[*i][*j]);
            }
}
void ft_norm_remplir_var2(t_map *data ,int *i,int *j,int *a)
{
    if (data->files[*i][*j] == 'W' && data->files[*i][*j + 1] == 'E')
            {
                if (data->file_WE)
                    *a = 0;
                *j=*j+2;
                while (data->files[*i][*j] == ' ')
                    *j = *j+1;
                data->file_WE = ft_strdup(&data->files[*i][*j]);
            }
            if (data->files[*i][*j] == 'E' && data->files[*i][*j + 1] == 'A')
            {
                if (data->file_EA)
                     *a = 0;
                *j= *j+2;
                while (data->files[*i][*j] == ' ')
                    *j = *j+1;
                data->file_EA = ft_strdup(&data->files[*i][*j]);
            }
}

void ft_norm_remplir_var3(t_map *data ,int *i,int *j,int *a)
{
    if (data->files[*i][*j] == 'C')
                {
                    if (data->file_c != -1)
                        *a = 0;
                    *j=*j+1;
                    while (data->files[*i][*j] == ' ')
                        *j=*j+1;
                    ft_hexa(&data->file_c, &data->files[*i][*j]);
                }
                if(data->files[*i][*j] == 'F')
                {
                    if (data->file_f != -1)
                        *a = 0;
                    *j = *j+ 1;
                    while (data->files[*i][*j] == ' ')
                      *j = *j+ 1;
                    ft_hexa(&data->file_f, &data->files[*i][*j]);
                }
}
void ft_remplir_var(t_map *data)
{
    int i;
    int j;
    int k;
    int a;

    i = -1;
    a = -1;
    while (data->files[++i])
    {
        j = -1;
        while (data->files[i][++j])
        {
          ft_norm_remplir_var1(data,&i,&j,&a);
          ft_norm_remplir_var2(data,&i,&j,&a);
          ft_norm_remplir_var3(data,&i,&j,&a);
        }
    }
    if (a == 0)
    {
        printf("error");
        exit(0);
    }
}
int ft_check_data_final(t_map *dt)
{
    if(dt->file_EA == NULL || dt->file_NO == NULL  ||
     dt->file_SO == NULL || dt->file_WE ==NULL
    ||dt->file_c == -1 || dt->file_f == -1)
    {
        return -1;
    }
    return(0);
}


void ft_check_content_data(int nb,char *str)
{
    int i;
    int cp;
    

    i = 0;
    cp = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] =='\n')
            i++;
      if (str[i] == 'E' || str[i] == 'W' || str[i] == 'S' || str[i] == 'N')
      {
          if (cp > 1)
          {
              printf("error 1");
              exit(0);
          }
          cp++;
      }
      if((str[i] == 'F' || str[i] == 'D') && nb == 0)
      {
          printf("error 2");
          exit(0);
      }
      if(str[i] != 'E' && str[i] != 'W' && str[i] != 'S' && str[i] != 'N' && str[i] != 'F' &&
       str[i] !='D' && str[i] != '0' && str[i] !='1' )
      {
          printf("error 3");
          exit(0);
      }
      i++;
    }
    
}

void ft_parse_map1(int nb, t_map *data,char *map)
{
    int fd;
    int i;
    
    i = 0;
    ft_initiale(data);
    fd = open(map, O_RDONLY);
    if(fd < 0)
    {
        printf("error");
        exit(0);
    }
    data->line = get_next_line(fd);
    data->pos = ft_handel_map(data->line);
    if (data->pos == -1)
    {
        printf("error c");
        exit(0);
    }
    ft_divis_line(data);
    if (data->var1 == NULL || data->var2 == NULL)
    {
        printf("error a");
         exit(0);
    }
    if (ft_check_line(data->var2) == -1)
    {
        printf("error aa");
         exit(0);
    }
    ft_check_content_data(nb,data->var2);
    data->map = ft_split(data->var2, '\n');
    get_width_height(data);
}
void ft_parse_map(int nb,t_map *data,char *map){
    ft_check_extens_map(map);
    ft_parse_map1(nb,data,map);
    ft_remplir_map(data);
    if (ft_check_map_horizontal(data->map, data->width, data->height) == 0 && ft_check_map_vertical(data->map, data->width, data->height) == 0)
    {
        data->files = ft_split(data->var1, '\n');
        ft_remplir_var(data);
        printf("%d\n",data->file_c);
         printf("%d\n",data->file_f);
        if (ft_check_data_final(data) == -1)
        {
            printf("error ooo");
             exit(0);
        }
        if(ft_check_file_exist(data->file_EA) == -1  ||ft_check_file_exist(data->file_EA) == -1 ||
        ft_check_file_exist(data->file_EA) == -1  ||ft_check_file_exist(data->file_EA) == -1)
        {
            printf("error file ");
            exit(0);
        }
    }
    else
        printf("error aaaa");
}

int main(int ac ,char *av[])
{
    t_map data;
      
    if (ac != 2)
    {
        printf("error");
        exit(0);
    }
    ft_parse_map(1,&data,av[1]);
}