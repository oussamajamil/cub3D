/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookprom12020 <macbookprom12020@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:00:42 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/09 03:04:54 by macbookprom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void ft_free(t_map *data)
{
    int i;
    char *tmp;

    i = 0;
    free(data->var1);
    free(data->var2);
    free(data->line);
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
    data->file_EA = NULL;
    data->file_NO = NULL;
    data->file_SO = NULL;
    data->file_WE = NULL;
    data->file_c = -1;
    data->file_f = -1;
}