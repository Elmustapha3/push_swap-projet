/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:11:29 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/05 20:47:27 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (i < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;
	int		len;

	len = ft_strlen((char *)s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
		{
			str = (char *)&s[i];
			return (str);
		}
		i++;
	}
	return (0);
}
