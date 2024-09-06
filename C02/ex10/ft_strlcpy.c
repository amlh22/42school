unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
    	len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
    		return (src_len);
	while (src[i] && i < size - 1)
	{
    		dest[i] = src[i];
    		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
