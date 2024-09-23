unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *temp;

	while (*s)
	{
		for (temp = accept; *temp; temp++)
			if (*s == *temp)
				break;
		if (*temp == '\0')
			break;
		count++;
		s++;
	}
	return count;
}
