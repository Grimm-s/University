/*# include <limits.h>
# include <string.h>
# include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

# define NO_OF_CHARS 256
using namespace std;
// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// The preprocessing function for Boyer Moore's bad character heuristic
void shift_table(string str, int size, int badchar[NO_OF_CHARS])
{
	int i;

	// Initialize all occurrences as -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = size;

	// Fill the actual value of last occurrence of a character
	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}

void search(string txt, string pat)
{
	vector<int> found;
	int m = pat.length();//strlen(pat);
	int n = txt.length();//strlen(txt);
	int badchar[NO_OF_CHARS];
	shift_table(pat, m, badchar);
	for (int p = 0; p < NO_OF_CHARS; p++) {
		if (badchar[p] != -1) {
			std::cout << badchar[p];
		}
		else {
			continue;
		}
	}
	*/
	/*
	int s = 0; // s is shift of the pattern with respect to text
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		if (j < 0)
		{			
			found.push_back(s);
			std::cout << "index:" << s << std::endl;
			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

		}

		else
			s += max(1, j - badchar[txt[s + j]]);
	}
	int s = 0;
	while (s <= n - m) {
		int j = m - 1;
		std::cout << s + j << std::endl;
		while (j >= 0 && pat[j] == txt[s + j])
			j--;
		if (j < 0) {
			found.push_back(s);
			//std::cout << "index:" << s << std::endl;
			s += badchar[(int)txt[s + j]];
		}
		else {
			s += badchar[(int)txt[s + j]];
		}
	}
	if (found.empty()) {
		cout << "element not found";
	}
	else {
		cout << "occurrences: ";
		for (int i = 0; i < found.size(); i++) {
			cout << found[i] << ' ';
		}
	}
}



int main()
{

	string txt = "DAAABsDAACdACD";
	string pat = "CD";
	search(txt, pat);
	return 0;
}

void BM_Search(char *txt, char*pat) {
	int n = strlen(txt);
	int m = strlen(pat);
	int i;
	for (i = m - 2; i < 0;i++) {



	}

}*/
# include <limits.h>
# include <string.h>
# include <stdio.h>
#include <vector>
#include <iostream>
#include <string>



int max(int a, int b)
{
	return (a > b) ? a : b;
}

void shift_table(std::string str, int size, int table[256])
{
	int i;	
	for (i = 0; i < 256; i++)
		table[i] = -1;	
	for (i = 0; i < size; i++)
		table[(int)str[i]] = i;
}

void ВМ_search(std::string txt, std::string pat)
{
	int k = 0;
	std::vector<int> found;
	int m = pat.length();//strlen(pat);
	int n = txt.length();
	int table[256];
	shift_table(pat, m, table);
	std::cout <<"Array:";
	for (int p = 0; p <256; p++) {
		if (table[p] != 100) {
			std::cout << table[p];
		}
		else {
			continue;
		}
	}
	std::cout << std::endl;
	int s = 0; 	
	while (s <= (n - m))
	{		
		int j = m - 1;
		k++;
		//std::cout << s + j << std::endl;
		while (j >= 0 && pat[j] == txt[s + j]) {
			k++;
			j--;
		}		
		if (j < 0)
		{
			found.push_back(s);
			//printf("\n pattern occurs at shift = %d", s);

			s += (s + m < n) ? m - table[txt[s + m]] : 1;
		}
		else { s += max(1, j - table[txt[s + j]]); }
	}
	std::cout << "number of comparisons: " << k << std::endl;
	if (found.empty()) {
		std::cout << "element not found";
	}
	else {
		std::cout << "occurrences: ";
		for (int i = 0; i < found.size(); i++) {
			std::cout << found[i] << ' ';
		}
	}
}

/* Driver program to test above funtion */
int main()
{
	
	std::string text = "ghjklujmghjklasdfghtgbyhnrtyurtyuhjrtyuyuiohjklrtyurtyuhjrtyuhjkl";
	std::string sample = "rtyurtyuhjrtyu";
	std::cout << "text: " << text << std::endl << "sample: " << sample << std::endl;	
	ВМ_search(text, sample);
	return 0;
	/*string text;
	string sample;
	cout << "text: ";
	cin >> text;
	cout << "sample: ";
	cin >> sample;
	prefixFunction(sample);
	KMPSearch(text, sample);*/
}