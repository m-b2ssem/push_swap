#include "./utiles/libft/libft.h"
#include <stddef.h>

typedef struct s_stack
{
	int		size;
	int		*top;
	int		*end;
	int		*arry;
}	t_stack;

int	ft_atoi(const char *str)
{
	int	cur;
	int	num;
	int	sign;

	cur = 0;
	num = 0;
	sign = 1;
	while ((str[cur] >= 9 && str[cur] <= 13) || str[cur] == ' ')
		cur++;
	if (str[cur] == '+' || str[cur] == '-')
	{
		if (str[cur] == '-')
			sign = -1;
		cur++;
	}
	while (str[cur] >= '0' && str[cur] <= '9')
	{
		num = num * 10 + str[cur] - '0';
		cur++;
	}
	return (num * sign);
}

size_t	ft_strlen(const char *str)
{
	const char	*i;

	i = str;
	while (*str)
		str++;
	return (str - i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	cur;
	char	*data;

	cur = 0;
	data = s;
	while (cur < n)
	{
		data[cur] = 0;
		cur++;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		return ;
	}
	write (fd, s, ft_strlen(s));
}

static int	numwords(char const *s, char c)
{
	int	cur;
	int	word_num;

	cur = 0;
	word_num = 0;
	while (s[cur] != 0)
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == 0))
			word_num++;
		cur++;
	}
	return (word_num);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cur;

	if (size == 0)
		return (ft_strlen(src));
	cur = 0;
	while (src[cur] && cur < (size - 1))
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = 0;
	return (ft_strlen(src));
}

static int	split_words(char **result, char const *s, char c, int word)
{
	int		start_cur;
	int		end_cur;

	end_cur = 0;
	start_cur = 0;
	while (s[end_cur])
	{
		if (s[end_cur] == c || s[end_cur] == 0)
			start_cur = end_cur + 1;
		if (s[end_cur] != c && (s[end_cur + 1] == c || s[end_cur + 1] == 0))
		{
			result[word] = malloc(sizeof(char) * (end_cur - start_cur + 2));
			if (!result[word])
			{
				while (word++)
					free(result[word]);
				return (0);
			}
			ft_strlcpy(result[word], (s + start_cur), end_cur - start_cur + 2);
			word++;
		}
		end_cur++;
	}
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (numwords(s, c) + 1));
	if (!result)
		return (0);
	if (!split_words(result, s, c, 0))
		return (0);
	return (result);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	if (nmemb && SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, total);
	return (ptr);
}
void	ft_erour(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
static int	ft_is_valid(char *arg)
{
	char	*ptr;

	ptr = arg;
	if (!arg)
		return (0);
	if (ft_strlen(arg) >= 12)
		ft_erour();
	if (((*arg == '-' || *arg == '+') && ft_isdigit(*(arg + 1))) || \
			ft_isdigit(*arg))
		arg++;
	else
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	free(ptr);
	return (1);
}

static int	ft_check_double(int *arry, int i, int num)
{
	if (!arry)
		return (0);
	while (i--)
		if (num == arry[i])
			return (0);
	return (1);
}

static int	ft_split_arg(int *arry, int *i, char **av)
{
	long int	tmp;
	char		**ptr;
	char		*str;

	ptr = av;
	while (*av)
	{
		str = *av;
		tmp = ft_atoi(*av++);
		if (tmp > INT_MAX || tmp < INT_MIN || !ft_check_double(arry, *i, tmp))
			ft_erour();
		arry[(*i)++] = (int)tmp;
		free(str);
	}
	free(ptr);
	return (*i);
}

int	*fill_arry(char **av, int size, int **arry)
{
	int		i;

	if (!av)
		return (NULL);
	*arry = ft_calloc(size, sizeof(int));
	i = 0;
	if (!arry)
		return (NULL);
	while (i < size)
	{
		ft_split_arg(*arry, &i, ft_split(*av++, ' '));
	}
	return (*arry);
}

static int	check_arg(char **av)
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = av;
	if (!av)
		return (0);
	while (*av)
	{
		if (!ft_is_valid(*av++))
			ft_erour();
		i++;
	}
	free (ptr);
	return (i);
}

int	ft_check_arg(char **av, int ac, int **arry)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (ac-- > 1)
	{
		i = check_arg(ft_split(av[ac], ' '));
		if (i)
			size += i;
		else
			ft_erour();
	}
	if (size > 1)
		fill_arry(++av, size, arry);
	else
		return (0);
	return (size);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arry;
	int		size;
    char *test[2] = {"test", "2 1 2"};
    argv = test;
    argc = 2;

	if (argc == 1)
		return (1);
	arry = NULL;
	size = ft_check_arg(argv, argc, &arry);
    return 0;
}