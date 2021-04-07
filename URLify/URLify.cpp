#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool isStringUnique(const string& str) // Array and string 1.1 // find if all chars are unique
{
	map<char, bool> unique;
	bool exist = false;
	for (int i = 0; i < str.length(); ++i)
	{
		if (unique.find(str[i]) == unique.end())
			unique.insert({ str[i], exist });
		else return false;
	}
	return true;
}

bool isPermutationOfEachOther(string str1, string str2) // 1.2
{
	if (str1.length() != str2.length())
		return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

string urlify(string& str)
{
	string needed = "%20";
	string result = "";
	int counter = 0;
	int size = str.length() - 1;
	while (str[size] == ' ')
	{
		str.erase(std::prev(str.end()));
		--size;
	}
	while (counter != str.length())
	{
		if (str[counter] == ' ')
		{
			result += needed;
		}
		else result += str[counter];
		++counter;
	}

	return result;
}

bool oneWay(string origin, string checked) //1.5 // check if it is edited once/ one char removed, edited, added
{
	if (origin == checked)
		return false;
	int OL = origin.length();
	int CL = checked.length();
	if ((OL - CL) >= 2 || (CL - OL) >= 2) {
		return false;
	}
	int edits = 0;
	int j = 0;
	int i = 0;
	do {
		if (origin[i] != checked[j])
			edits++;
		++i, ++j;
		if (OL > checked.length() && j == CL)
			--j;
		else if (origin.length() < checked.length() && i == OL)
			--i;
	} while (i < OL && j < CL);

	return (edits >= 2) ? false : true;
}

struct stringCmp
{
	char letter;
	int counter=1;
};

vector<stringCmp> CompressionString(string str) //1.6
{
	stringCmp obj;
	vector<stringCmp> result;
	int current = 0;
	do
	{
		if (str[current] == str[current + 1])
		{
		++	obj.counter;
		}
		else {
			obj.letter = str[current];
			result.push_back(obj);
			obj.counter = 1;
		}
		++current;
	} while (str[current] != '\0');
	return result;
}
const int N = 3;
const int M = 4;
void print_matrix(int mat[][N])
{
	cout << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}
void rotate_Matrix( int mat[][N]) //1.7
{
	for (int x = 0; x < N / 2; x++) {
		for (int y = x; y < N - x - 1; y++) {
			int temp = mat[x][y];

			mat[x][y] = mat[y][N - 1 - x];
			mat[y][N - 1 - x]	= mat[N - 1 - x][N - 1 - y];
			mat[N - 1 - x][N - 1 - y]= mat[N - 1 - y][x];

			mat[N - 1 - y][x] = temp;
		}
	}
	
	print_matrix(mat);
	
}

void Zero_matrix(int mat[M][N]) // 1.8
{
	
	bool zeroM[M];
	bool zeroN[N];
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] == 0) {
				zeroM[i] = true;
				zeroN[j] = true;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (zeroM[i] ==	1||zeroN[j]==1)
				mat[i][j] = 0;
		}
	}
	print_matrix(mat);
}

bool isSubstring(string str1, string str2) //1.9
{
	if (str1.length() != str2.length())
		return false;

	string temp = str1 + str1;
	return (temp.find(str2) )? true : false;
	//temp.find(str2)!= string::npos);
}



int main()
{
	int counter = 0;
	string str = "water";
	string str1 = "erwat";
	 int Arr[M][N];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Arr[i][j] = counter++;
			cout << Arr[i][j] << "\t";
		}
		cout << endl;
	}
//	cout<<str.insert(4, " 11111111 ");
	cout<< isSubstring(str, str1)<<endl;

}

