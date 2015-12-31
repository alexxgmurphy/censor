#include <iostream>
#include <string>

int main()
{
	//variable declaration
	std::string original;
	std::string clean;
	std::string anotherInput;
	std::string word = "love";
	std::string wordsToCheck;
	int anotherYN = 1;
	int startIndex = 0;
	int endIndex = 0;
	int wordLength = 0;
	std::string dirtyWords[7]
	{
		"dren",
		"frak",
		"frel",
		"glob",
		"grud",
		"narf",
		"zark",
	};
	std::string dirtyWordsUpper[7]
	{
		"Dren",
		"Frak",
		"Frel",
		"Glob",
		"Grud",
		"Narf",
		"Zark",
	};


	//welcome
	std::cout << "Welcome to the censorship bureau." << std::endl;

	while (anotherYN = 1)
	{
		//get user input
		std::cout << "Enter text to have it automatically cleansed: " << std::endl;
		std::getline(std::cin, original);

		//analyze characters
		clean = original;
		for (int i = 0; i < original.length(); i++)
		{
			if (original[i] == ' ')
			{
				endIndex = i - 1;
				wordLength = (endIndex + 1) - startIndex;
				if (wordLength == 4)
				{
					for (int x = 0; x < 5; x++)
					{
						word[x] = original[startIndex + x];
					}
					for (int x = 0; x < 7; x++)
					{
						if (dirtyWords[x] == word)
						{
							clean[startIndex] = 'l';
							clean[startIndex + 1] = 'o';
							clean[startIndex + 2] = 'v';
							clean[startIndex + 3] = 'e';
						}
					}
					for (int x = 0; x < 7; x++)
					{
						if (dirtyWordsUpper[x] == word)
						{
							clean[startIndex] = 'L';
							clean[startIndex + 1] = 'o';
							clean[startIndex + 2] = 'v';
							clean[startIndex + 3] = 'e';
						}
					}
				}
				startIndex = i + 1;
			}
			else if (original[i] == '.' || original[i] == ',' || original[i] == '!' || original[i] == '?')
			{
				endIndex = i - 1;
				wordLength = endIndex - startIndex + 1;
				if (wordLength == 4)
				{
					for (int x = 0; x < 5; x++)
					{
						word[x] = original[startIndex + x];
					}
					for (int x = 0; x < 7; x++)
					{
						if (dirtyWords[x] == word)
						{
							clean[startIndex] = 'l';
							clean[startIndex + 1] = 'o';
							clean[startIndex + 2] = 'v';
							clean[startIndex + 3] = 'e';
						}
					}
					for (int x = 0; x < 7; x++)
					{
						if (dirtyWordsUpper[x] == word)
						{
							clean[startIndex] = 'L';
							clean[startIndex + 1] = 'o';
							clean[startIndex + 2] = 'v';
							clean[startIndex + 3] = 'e';
						}
					}
				}
				startIndex = i + 2;
			}
			else if (i == original.length() - 1)
			{
				endIndex = i;
				wordLength = endIndex - startIndex + 1;
				if (wordLength == 4)
				{
					for (int x = 0; x < 5; x++)
					{
						word[x] = original[startIndex + x];
					}
					for (int x = 0; x < 7; x++)
					{
						if (dirtyWords[x] == word)
						{
							clean[startIndex] = 'l';
							clean[startIndex + 1] = 'o';
							clean[startIndex + 2] = 'v';
							clean[startIndex + 3] = 'e';
						}
					}
					for (int x = 0; x < 7; x++)
					{
						if (dirtyWordsUpper[x] == word)
						{
							clean[startIndex] = 'L';
							clean[startIndex + 1] = 'o';
							clean[startIndex + 2] = 'v';
							clean[startIndex + 3] = 'e';
						}
					}
				}
			}
			else
			{
				continue;
			}
		}
		startIndex = 0;
		
		//output
		std::cout << "Your input has been successfully censored: \n" << clean << std::endl;

		//another?
		std::cout << "Do you have another portion of text to be cleansed? ";
		std::cin >> anotherInput;
		if (anotherInput == "No" || anotherInput == "no")
		{
			anotherYN = 0;
			break;
		}
		else if (anotherInput == "Yes" || anotherInput == "yes")
		{
			anotherYN = 1;
		}
		else
		{
			std::cout << "Please enter either 'yes' or 'no'" << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return 0;
}
