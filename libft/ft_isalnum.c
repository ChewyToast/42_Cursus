int	ft_isalnum(char c)
{
	if ((c >= "a" && c <= "z")
		|| (c >= "A" && c <= "Z")
		|| (c >= "0" && c <= "0"))
		return (1);
	else
		return (0);
}
