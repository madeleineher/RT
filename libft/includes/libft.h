/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:26:04 by jebae             #+#    #+#             */
/*   Updated: 2019/12/12 18:10:15 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define FT_SUCCESS					0
# define FT_FAIL					1
# define FT_LONG_LIMIT				0x7FFFFFFFFFFFFFFF
# define FT_CHARACTER_TABLE_SIZE	256

/*
** std output color
*/
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KNRM "\x1B[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_queue
{
	t_list			*front;
	t_list			*rear;
}					t_queue;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*content;
}					t_btree;

typedef struct		s_set
{
	t_btree			*tree;
	int				(*cmpf)(void *, void *);
}					t_set;

/*
** memory
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_swap(void *p1, void *p2, size_t size);
void				ft_memnegate(unsigned char *mem, size_t size);

/*
** string
*/
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
double				ft_atof(const char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *as));
void				ft_striteri(char *s, void (*f)(unsigned int i, char *as));
char				*ft_strmap(const char *s, char (*f)(char ch));
char				*ft_strmapi(
	const char *s,
	char (*f)(unsigned int i, char ch)
);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_boyer_moore(const char *text, const char *pat);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(
	const char *haystack,
	const char *needle,
	size_t len
);
int					ft_hexatoi(const char *str);
int					ft_ishexdigit(int c);
int					ft_iswhitespace(char ch);
void				ft_to_utf8(wchar_t wch, char *utf8);
int					ft_utf8_byte_len(char *utf8);

/*
** io
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				put_color_str(const char *color, const char *s);

/*
** linked list
*/
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(
	t_list **alst,
	void (*del)(void *content, size_t content_size)
);
void				ft_lstdel(
	t_list **alst,
	void (*del)(void *content, size_t content_size)
);
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_sorted_lstadd(
	t_list **alst,
	t_list *n,
	int (*compare)(t_list *, t_list *)
);
t_list				*ft_sorted_lstpop(t_list **alst);
void				ft_lstsort(
	t_list **alst,
	int (*compare)(t_list *, t_list *)
);
void				ft_lstrev(t_list **alst);
size_t				ft_lstlen(t_list *lst);
void				ft_lstiter_with_arg(
	t_list *lst,
	void (*f)(t_list *elem, void *arg),
	void *arg
);

/*
** file
*/
char				*get_file_content(int fd);

/*
** queue
*/
t_queue				queue_init(void);
void				queue_push(
	t_queue *queue,
	void *content,
	size_t content_size
);
void				*queue_pop(t_queue *queue);

/*
** binary tree
*/
t_btree				*btree_create_node(void *content, size_t content_size);
void				btree_insert_data(
	t_btree **root,
	void *content,
	size_t content_size,
	int (*cmpf)(void *, void *)
);
void				btree_bfs(t_btree *root, void (*f)(void *content));
void				btree_apply_inorder(
	t_btree *root,
	void (*applyf)(void *)
);
void				btree_apply_postorder(
	t_btree *root,
	void (*applyf)(void *)
);
void				btree_delone(t_btree **node, void (*del)(void *content));
void				btree_del(t_btree **root, void (*del)(void *content));
void				*btree_search_one(
	t_btree *root,
	void *p_data,
	int (*cmpf)(void *, void *)
);
void				btree_remove_if(
	t_btree **root,
	void *p_data,
	int (*cmpf)(void *, void *)
);
void				btree_foreach(
	t_btree *root,
	void (*f)(void *content)
);
void				btree_foreach_with_arg(
	t_btree *root,
	void *arg,
	void (*f)(void *content, void *arg)
);

/*
** set
*/
t_set				set_init(int (*cmpf)(void *, void *));
void				set_add(
	t_set *set,
	void *content,
	size_t content_size
);
void				set_remove_if(
	t_set *set,
	void *p_data,
	int (*cmpf)(void *, void *)
);
void				set_del(t_set *set);
void				set_foreach(t_set *set, void (*f)(void *content));
void				set_foreach_with_arg(
	t_set *set,
	void *arg,
	void (*f)(void *content, void *arg)
);
size_t				set_length(t_set *set);

/*
** math
*/
long long			ft_powd(long long num, size_t e);
unsigned long long	ft_powud(unsigned long long num, size_t e);
size_t				ft_bit_reverse(size_t x, size_t num_bits);
unsigned int		ft_int_log2(size_t num);
void				ft_extract_double(
	double num,
	short *exponent,
	unsigned long long *mantissa
);
int					ft_is_inf(double num);
int					ft_is_nan(double num);
void				ft_extract_ldouble(
	long double num,
	short *exponent,
	unsigned long long *mantissa
);
int					ft_is_inf_l(long double num);
int					ft_is_nan_l(long double num);
long long			ft_max_int(long long a, long long b);
long long			ft_min_int(long long a, long long b);
double				ft_abs_double(double a);
void				ft_swap_double(double *a, double *b);

#endif
