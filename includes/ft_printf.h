/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 10:23:57 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/10 15:43:11 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <wchar.h>
# include <limits.h>
# define FLAGS "+0- #"
# define NBR "0132456789."
# define SPECIFIER "hljz"
# define CONVERT "uoxUOXpdDicCsS"

typedef struct	s_arg
{
	int				flags[5];
	int				specifier;
	int				conv;
	int				att;
	int				fg;
	int				bg;
	int				champ;
	int				pre;
	int				length;
	int				padding;
}				t_arg;

void			print1(char *str, t_arg *list);
int				parser(const char *str, t_arg *list);
int				bin_count(wchar_t v);

char			*convwstr(wchar_t *str);
char			*convc(int dec);
char			*convwchar(wint_t dec);
char			*convim(intmax_t nb);
char			*convuim(uintmax_t nb);
char			*convuimo(uintmax_t nb);
char			*convuimx(uintmax_t nb);

char			*convsigned(va_list va, t_arg *list);
char			*convunsigned(va_list va, t_arg *list);
int				*putf(va_list va, t_arg *list, const char *str, int *i);

char			*chooseconv(va_list va, t_arg *list);

void			colorise(t_arg *list);
int				parse_colors(char *str, t_arg *list);
void			reset_int_tab(int *i, int row);

int				ft_printf(const char *first, ...);
void			ft_putn_schar(char c, int nb);
void			ft_putnstr(char *str, size_t nb, t_arg *list);
int				initlist(t_arg *list);
int				charchr(char c, char *str);
int				get_fields(const char *str, int i, t_arg *tempm, int index);
#endif
