/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:28:05 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/15 16:34:05 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		result[len1 + i] = s2[i];
		i++;
	}
	result[len1 + len2] = '\0';
	return (result);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len]) // Calculate the length of s1 manually
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len) // Copy characters manually
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0'; // Null-terminate the new string
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start >= i)
		return (NULL);
	if (len > i - start)
		len = i - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int ft_test_new(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		s++;
	}
	if (s[i] == '\0') 
		return (i);
	return (-1);
}

