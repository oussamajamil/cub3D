/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:00:42 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/09 13:16:46 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
// void ft_free(t_map *data)
// {
//     int i;
//     char *tmp;

//     i = 0;
//     free(data->var1);
//     free(data->var2);
//     free(data->line);
// }
void ft_free_double_pointer(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
      free(str[i]);
      i++;
    }
    free(str);
    
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

int	ft_atoi(const char *str)
{
	int	i;
	int	cp;
	int	r;

	i = 0;
	cp = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cp = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * cp);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}