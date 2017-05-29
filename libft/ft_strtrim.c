/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:42:45 by dzui              #+#    #+#             */
/*   Updated: 2016/11/25 18:58:55 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_blank_or_empty(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != ' ') && (s[i] != '\n')
			&& (s[i] != '\t'))
			return (0);
		i++;
	}
	return (1);
}

static	int		find_first(const char *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	return (i);
}

static	int		find_last(const char *s)
{
	int	last;

	last = ft_strlen(s) - 1;
	while ((s[last] == ' ') || (s[last] == '\n') || (s[last] == '\t'))
		last--;
	return (last);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	last;
	char			*res;

	if (s)
	{
		if (is_blank_or_empty(s))
		{
			res = (char *)malloc(sizeof(char));
			*res = '\0';
			return (res);
		}
		i = find_first(s);
		last = find_last(s);
		res = (char *)malloc(sizeof(char) * (last - i) + 2);
		if (!res)
			return (NULL);
		j = 0;
		while (i <= last)
			res[j++] = s[i++];
		res[j] = '\0';
		return (res);
	}
	return (NULL);
}
