/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 01:13:03 by ablin             #+#    #+#             */
/*   Updated: 2018/09/02 21:14:48 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../libft.h"
# include <stdarg.h>

# define FUN_C { "c%", c_padding }
# define FUN_CC { "C", print_wchar }
# define FUN_S { "s ", str_handler }
# define FUN_SS { "S", print_wstr }
# define FUN_INT { "dDi", int_handler }
# define FUN_HEX { "oOuUxXp", hex_handler }

typedef enum		e_mod
{
	NONE = 0, HH = 1, H = 2, L = 3, LL = 4, J = 5, Z = 6
}					t_mod;

typedef struct		s_arg
{
	char			*wflag;
	char			*buf;
	char			flag;
	int				base;
	t_mod			mod;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_fun
{
	char			*conv;
	void			(*handler)(t_arg *, va_list, int *);
}					t_fun;

/*
** ft_printf.c
*/
int					ft_printf(const char *restrict format, ...);
void				get_handler(t_arg *lst, va_list ap, int *retour);
void				cycle_arg(t_arg *lst, va_list ap, int *retour);
void				get_length_mod(t_arg *lst);

/*
** fill_list.c
*/
t_arg				*add_buffer(t_arg *lst, char flag, char *wflag);
t_arg				*add_arg(t_arg *lst, char flag, char *wflag);
t_arg				*add_str(t_arg *lst, char *str);
int					handle_exc(char *twflag, char *wflag, char flag, int mode);
void				fetch_arg(t_arg **lst, const char *restrict format);

/*
** padding.c
*/
int					flag_exc(char flag);
int					blank_and_sign(t_arg *lst, int signe, int toprint);
int					precision_and_zero(t_arg *lst, int size, int signe);
void				minus_flag(t_arg *lst, int toprint, int signe);

/*
** length_handler.c
*/
intmax_t			handle_length(t_arg *lst, va_list ap);
uintmax_t			handle_ulength(t_arg *lst, va_list ap);

/*
** char_handler.c
*/
void				c_padding(t_arg *lst, va_list ap, int *r);
int					putstr_exc(char *str, char *wflag);
void				str_handler(t_arg *lst, va_list ap, int *r);

/*
** nb_handler.c
*/
void				int_handler(t_arg *lst, va_list ap, int *r);
void				hex_handler(t_arg *lst, va_list ap, int *r);

/*
** wide_char_handler.c
*/
void				print_wchar(t_arg *lst, va_list ap, int *r);
void				print_wstr(t_arg *lst, va_list ap, int *r);
int					ft_putwstr_preci(wchar_t *str, char *wflag,
					int (*func)(wchar_t));

/*
** utils.c
*/
int					is_there(char *wflag, char c);
int					is_z(char *wflag);
int					get_pad(char *str);
int					get_preci(char *str);
int					htag(t_arg *lst, int signe, int mode);

/*
** utils2.c
*/
int					divide_nb(intmax_t nb, int divider, char *wflag);
int					divide_unb(uintmax_t nb, int base, char *wflag);
int					to_print(char c, int toprint);
void				to_print_s(t_arg *lst, int toprint, int signe);
int					wchar_len(wchar_t c);

/*
** modified libft func
*/
void				pf_itoa_base(uintmax_t n, int base, char flag);
char				*pf_strdup(const char *s1);
#endif
