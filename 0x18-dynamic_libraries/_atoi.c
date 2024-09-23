int _atoi(char *s)
{
	int res = 0, sign = 1, i = 0;

	while (s[i] == ' ')
		i++;

	if (s[i] == '-' || s[i] == '+')
		sign = (s[i++] == '-') ? -1 : 1;

	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');

	return res * sign;
}
