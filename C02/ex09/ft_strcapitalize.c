/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:11:58 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/15 18:30:03 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	ft_strlowcase(str);
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
			if ('a' > str[i - 1] || str[i - 1] > 'z')
				if ('A' > str[i - 1] || str[i - 1] > 'Z')
					if ('0' > str[i - 1] || str[i - 1] > '9')
						str[i] -= 32;
		i++;
	}
	return (str);
}
