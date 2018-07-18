#ifndef MY_H_
# define MY_H_
# define BUF_SIZE 4096

char	*get_next_line(const int fd);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_putnbr(int nb);
long	my_putnbr_ld(long nb);
int	my_putnbr_base(int nb, char *);
void	my_putnbr_base_ld(long nb, char *);
int	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_getnbr_base(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
char	**my_str_to_wordtab(char *str);
void	my_show_wordtab(char **);
int	my_isnum(char *);
int	my_printf(const char *format, ...);

#endif /* MY_H_ */
