/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:27:24 by flima             #+#    #+#             */
/*   Updated: 2025/03/10 15:33:58 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//Character Functions
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isspace(int c);
// String Functions
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
void	ft_bzero(void *s, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// input/output Functions
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char	*s, int fd);
void	ft_putnbr_fd(int n, int fd);
// Memory Functions
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t len, size_t size);
// Math Functions
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
char	*ft_itoa(int n);
//bonus functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list	*lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list	**lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//ft_printf functions
int		ft_putchar_n(int c);
int		ft_putstr_n(char *s);
int		ft_putnbr_n(int nb);
int		ft_putunsig_n(unsigned int n);
int		ptr_tohex(unsigned long nbr);
int		dec_tohex(unsigned int n, const char *chr);
int		ft_printf(const char *format, ...);
//gnl functions
char	*get_next_line(int fd);
char	*gnl_strdup(const char *s);
char	*gnl_strjoin(const char *s1, const char *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*gnl_strchr(const char *str, int c);

#endif