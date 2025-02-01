/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:01:12 by ahavu             #+#    #+#             */
/*   Updated: 2024/11/28 15:24:23 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(const char *initial_str, ...);
int		print_char(int c);
int		print_hex(uintptr_t unb, char c);
int		print_nbr(int n);
int		print_ptr(uintptr_t ptr);
int		print_str(char *s);
int		print_uint(unsigned int n);
char	*ft_strchr(const char *s, int c);

#endif
