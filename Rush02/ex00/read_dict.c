/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:04:54 by npalissi          #+#    #+#             */
/*   Updated: 2024/07/28 00:26:27 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>

int	ft_get_size_dict(char *dict_name)
{
	int		ft;
	int		num;
	int		i;
	char	buf[60000];

	ft = open(dict_name, O_RDONLY);
	if (ft == -1)
		return (-1);
	i = 0;
	num = 1;
	while (num == 1)
	{
		num = read(ft, buf, 1);
		i++;
	}
	if (close(ft) == -1)
		return (-1);
	return (i);
}

char	*ft_read_dict(char *dict_name)
{
	char	*str;
	int		ft;
	int		i;

	i = ft_get_size_dict(dict_name);
	if (i == -1)
		return (0);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	ft = open(dict_name, O_RDONLY);
	if (ft == -1 || read(ft, str, i - 1) == -1)
	{
		free(str);
		return (0);
	}
	str[i] = '\0';
	return (str);
}
