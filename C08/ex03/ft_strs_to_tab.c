/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:33:31 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/29 18:33:32 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strovk_str.h"

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*tab;

	i = 0;
	len = 0;
	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len + 1] = '\0';
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	return (tab);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

struct s_stock_str *ft_strs_to_tab(int argc, char **agrv)
{
	int	i;
	t_stock_str	*tab;
	t_stock_str	*tmp;
	tab = (t_stock_str*)malloc(sizeof(*tab) * argc + 1);
	if (!tab)
		return (NULL);
	tmp = tab;
	i = 0;
	while (i < argv - 1)
	{
		tmp -> size = ft_strlen(*argv)
		tmp -> str = *argv
		tmp -> copy = ft_strdup(*argv)
		argv++;
		tmp++;
		i++;
	}
	tmp ->
}
