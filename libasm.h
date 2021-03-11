/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmicheal <bmicheal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:29:14 by bmicheal          #+#    #+#             */
/*   Updated: 2021/01/07 13:24:11 by bmicheal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
#define LIBASM_H

#include <stdio.h>

size_t	ft_strlen(const char *str);
ssize_t	ft_write(unsigned int fd, const char *buf, size_t count);
ssize_t	ft_read(unsigned int fd, const char *buf, size_t count);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
