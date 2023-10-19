/**
 * is_integer - Function to check if a string is an integer
 * @str: pointer to a string
 *
 * Return: 1 if success otherwise fail
 */
int is_integer(const char *str)
{
	int i;

	if (!str || *str == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
