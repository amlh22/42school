unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
)

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
  	unsigned int	src_len;
  	unsigned int    i;
  	unsigned int    j;
  
  	dest_len = ft_strlen(dest);
  	src_len = ft_strlen(src);
  	i = 0;
  	j = dest_len;
  	if (size <= dest_len)
  		return (size + src_len);
	while (src[i] != '\0' && j < size - 1)
  	{
		dest[j] = src[i];
	  	j++;
	  	i++;
  	}
  	dest[j] = '\0';
  	return (dest_len + src_len);
}
