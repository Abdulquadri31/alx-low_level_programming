char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *temp = dest;
	while (n--)
		*dest++ = *src++;
	return temp;
}
