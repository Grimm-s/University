#include <iostream>
#include <vector>
using namespace  std;
void searchNaive(string text, string sample) {
    vector<int> foundPositions;
    int n = 0;
    for (int i = 0; i < text.length(); i++) {
        int j = 0;
        while (j < sample.length() && i + j < text.length() && sample[j] == text[i + j]) {
            n++;
            j++;
        }
        if (j == sample.length()) {
            foundPositions.push_back(i);
        }
    }
    cout << "number of comparisons: " << n<<endl;
    if (foundPositions.empty()) {
        cout << "element not found";
    }
    else {
        cout << "occurrences: ";
        for (int i = 0; i < foundPositions.size(); i++) {
            cout << foundPositions[i] << ' ';
        }
    }
}
int main()
{
string text = "aabaabaaaaaabaabaabaabbaaab";
string sample= "afkf";
cout << "text: " << text << endl << "sample: "<<sample<<endl;
searchNaive(text, sample);

/*string text;
string sample;
cout << "text: ";
cin >> text;
cout << "sample: ";
cin >> sample;
searchNaive(text, sample);*/

return 0;
}



