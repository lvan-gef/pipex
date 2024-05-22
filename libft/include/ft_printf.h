/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 17:51:54 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/05 02:09:16 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// src/ft_formatter.c
int	to_hex(unsigned long int size, size_t upper, size_t base);
int	format_int(int size, size_t upper, size_t base);
int	format_ptr(void *ptr, size_t upper, size_t base);

// src/ft_printf.c
int	ft_printf(const char *s, ...);

// src/ft_writers.c
int	write_ascii(int c);
int	write_str(char *s);
#endif
