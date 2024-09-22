#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << '\n';
		return (0);
	}
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			argv[i][j] = std::toupper(argv[i][j]);
			j++;
		}
		std::cout << argv[i];
		std::cout << " ";
		i++;
	}
	std::cout << '\n';
	return(0);
}

/*
class Word
{
private :
	char *s;

public :
	Word(char *w) : s(w) {}
	void upper()
	{
		int i = 0;
		while (s[i] != '\0')
		{
			s[i] = std :: toupper(s[i]);
			i++;
		}
	}
};
*/