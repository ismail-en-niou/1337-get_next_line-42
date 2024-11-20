/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:45:36 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/20 13:17:37 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_test_new(char *str);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*return_on_eof(char **line, char **buffer, char **xayata);
char	*process_buffer(char *line, char *buffer, int read_byte, char **xayata);
char	*handle_error(char **line, char **buffer, int flag);
char	*ft_strchr(const char *s, int c);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif