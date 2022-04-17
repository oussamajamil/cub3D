/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrabi <hdrabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:04:22 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/17 02:03:25 by hdrabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

void	ft_hexa(int *data, char *str)
{
	char	**res;
	int		i;
	int		r;
	int		l;

	i = 0;
	l = ft_strlen(str);
	if (str[l - 1] == ',')
		ft_message_and_exit("Error : invalid RGB value");
	res = NULL;
	res = ft_split(str, ',');
	while (res[i])
		i++;
	if (i != 3)
		ft_message_and_exit("Error : invalid RGB value");
	if (ft_is_number(res[0]) == -1 || ft_is_number(res[1]) == -1
		|| ft_is_number(res[2]) == -1)
		ft_message_and_exit("Error : invalid RGB value");
	if (ft_atoi(res[0]) < 0 || ft_atoi(res[0]) > 300
		||ft_atoi(res[1]) < 0 || ft_atoi(res[1]) > 300
		||ft_atoi(res[2]) < 0 || ft_atoi(res[2]) > 300)
		ft_message_and_exit("Error : invalid RGB value");
	*data = ft_atoi(res[0]) * 256 * 256
		+ft_atoi(res[1]) * 256 + ft_atoi(res[0]);
	ft_free_double_pointer(res);
}

void	ft_check_text_incorrect(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] != 'C' && str[0] != 'F' && str[0] != 'N' && str[0] != 'S'
			&& str[0] != 'E' && str[0] != 'W')
			ft_message_and_exit("Error : Information Incorrects");
		if ((str[0] == 'N' && str[1] != 'O') || (str[0] == 'S' && str[1] != 'O')
			|| (str[0] == 'E' && str[1] != 'A')
			|| (str[0] == 'W' && str[1] != 'E'))
			ft_message_and_exit("Error : Information Incorrects");
		i++;
	}
}
