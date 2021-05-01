
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int* prefixFunction(string sample) {
	int* values = new int[sample.length()];
	for (int i = 0; i < sample.length(); i++) {
		values[i] = 0;
	}
	for (int i = 1; i < sample.length(); i++) {
		int j = 0;
		while (i + j < sample.length() && sample[j] == sample[i + j]) {
			values[i + j] = Max(values[i + j], j + 1);
			j++;			
		}
	}	
	return values;
}

void KMPSearch(string text, string sample) {
	vector<int> found;
	int* prefixFunc = prefixFunction(sample);
	int i = 0;
	int j = 0;
	int n = 0;
	while (i < text.length()) {
		if (sample[j] == text[i]) {
			j++;
			i++;
			n++;
		}
		if (j == sample.length()) {
			found.push_back(i - j);
			j = prefixFunc[j - 1];
		}
		else if (i < text.length() && sample[j] != text[i]) {
			
			if (j != 0) {
				j = prefixFunc[j - 1];
			}
			else {
				i = i + 1;
			}
		}
	}
	cout << "number of comparisons: " << n << endl;
	cout << "prefix_func:";
	for (int i = 0; i < sample.length(); i++) {
		cout << prefixFunc[i] << ' ';
	}
	cout << endl;
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
	string text = "qwertyqwertyrtyuiopdfghjk";
	string sample = "qwerqwer";
	
	cout << "text: " << text << endl << "sample: " << sample << endl;
	prefixFunction(sample);	
	KMPSearch(text, sample);
	cout << endl;
	
	
	/*string text;
	string sample;
	cout << "text: ";
	cin >> text;
	cout << "sample: ";
	cin >> sample;
	prefixFunction(sample);
	KMPSearch(text, sample);*/
}

