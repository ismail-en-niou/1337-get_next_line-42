/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:45:36 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/15 16:36:22 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_xayata(char *str);
int     ft_test_new(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);


#  define BUFFER 2
#endif