/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:24:42 by npalissi          #+#    #+#             */
/*   Updated: 2024/07/28 19:36:52 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_get_word_by_index(char *str)
{
	int		i;
	char	*word;

	while (*str == ' ' || *str == ':')
		str++;
	i = 0;
	while (str[i] != '\n')
		i++;
	word = malloc(sizeof(char) * (i + 1) + 1);
	if (!word)
		return (0);
	i = -1;
	while (str[i++] != '\n')
		word[i] = str[i];
	word[i - 1] = '\0';
	return (word);
}

char	*ft_get_word(char *str, char *index)
{
	int	i;

	while (*str)
	{
		if (*str == index[0])
		{
			i = 0;
			while (*str && *str == index[i] && index[i] != '\0')
			{
				i++;
				str++;
			}
			if (index[i] == '\0')
				return (ft_get_word_by_index(str));
		}
		else
			str++;
	}
	return (0);
}
