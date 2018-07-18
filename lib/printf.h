#ifndef PRINTF_H_
# define PRINTF_H_

int	put_str(va_list *list, const char *str);
int	put_str_(va_list *list, const char *str);
int	put_nbr(va_list *list, const char *str);
int	putnbr_u(va_list *list, const char *str);
int	put_nbrbase(va_list *list, const char *str);
int	put_nbrbase_(va_list *list, const char *str);
int	put_nbroctal(va_list *list, const char *str);
int	put_err(va_list *list, const char *str);
int	put_char(va_list *list, const char *str);
int	putptr(va_list *list, const char *str);

#endif /* PRINTF_H_ */
