char *_memset(char *s, char b, unsigned int n)
{
	char *temp = s;
	while (n--)
		*s++ = b;
	return temp;
}
