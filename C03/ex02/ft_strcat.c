char	*ft_strcat(char *dest, char *src)
{
	char	*end;

	*end = dest;
	while (*end != '\0')
    		end++;
	while (*src)
	{   
    		*end = *src;
    		end++;
    		src++;
	}   
	*end = '\0';
	return (dest);
}   
