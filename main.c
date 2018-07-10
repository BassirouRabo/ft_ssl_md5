# include "sha512.h"
# include "libft/libft.h"
# include <stdio.h>

void    init_words(char *str);
char    *get_words(char *str);
char    *ft_concert_string_to_binary(char *input);
char    *ft_convert_string_to_hex(char *input);


int main()
{
	char *words = get_words("abc");
	printf("%s\n", words);
	init_words(words);
	return (0);
}

char    *get_words(char *str)
{
	char    *bin_input;
	char    *bin_size;
	char    *bin;
	size_t  padding;
	size_t  len_input_size;
	size_t  n_block;

	bin_input = ft_str_new_suffix(ft_convert_string_to_hex(str), '8', 1);
	bin_size = ft_itoa_base((int)(ft_strlen(str) * 8), 16);
	padding = 0;
	n_block = 1;
	len_input_size = ft_strlen(bin_input) + ft_strlen(bin_size);
	if (len_input_size < 256)
		padding = 256 - len_input_size;
	else if (len_input_size > 256)
	{
		padding = len_input_size % 256;
		n_block = len_input_size / 256;
	}
	if (!(bin = ft_memalloc(n_block * 256 + 1)))
		return (NULL);
	return (ft_strjoin(ft_str_new_suffix(ft_strcpy(bin, bin_input) , '0', padding * n_block), bin_size));
}

void    init_words(char *str)
{
	int i;
	int index;

	index = 0;
	while (str && *str)
	{
		i = 0;
		while (i < 16)
			g_words[index][i++] = *str++;
		g_words[index][i] = 0;
		printf("[%d] [%s]\n", index, g_words[index]);
		index++;
	}
}

char    *ft_concert_string_to_binary(char *input)
{

	char    *bin_input;
	char    *bin_char;
	char    *tmp;

	bin_input = NULL;
	while (input && *input)
	{
		bin_char = ft_itoa_base(*input++, 2);
		bin_char = ft_str_new_prefix(bin_char, '0', 8 - ft_strlen(bin_char));
		tmp = ft_str_new_concat(bin_input, bin_char);
		ft_strdel(&bin_char);
		ft_strdel(&bin_input);
		bin_input = tmp;
	}
	return (bin_input);
}

char    *ft_convert_string_to_hex(char *input)
{
	char    *bin_input;
	char    *bin_char;
	char    *tmp;

	bin_input = NULL;
	while (input && *input)
	{
		bin_char = ft_itoa_base(*input++, 16);
		tmp = ft_str_new_concat(bin_input, bin_char);
		ft_strdel(&bin_char);
		ft_strdel(&bin_input);
		bin_input = tmp;
	}
	return (bin_input);
}