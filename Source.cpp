#include <string>
#include <iostream>
using namespace std;
int GetCorrectSize()
{
	int size;
	while (!(cin >> size) || (cin.peek() != '\n') || size < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведите корректное число:\t";
	}
	return size;
}
int GetCorrectNumber(int size)
{
	int number;
	while (!(cin >> number) || (cin.peek() != '\n') || number < 0 || number > size)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведите корректное число:\t";
	}
	return number;
}

void FillArray(string* parr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "¬ведите " << i << "-й элемент массива" << endl;
		cin >> parr[i];
	}
}
void PrintArray(string* parr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << "-й элемент:\t" << parr[i] << endl;
	}
}
void PushArray(string*& arr, int& size, int number)
{
	string* NewArray = new string[size + 1];
	string value;
	cout << "¬ведите строку:";
	cin >> value;
	for (int i = 0; i < number; i++)
	{
		NewArray[i] = arr[i];
	}
	NewArray[number] = value;
	size++;
	for (int i = number + 1; i < size; i++)
	{
		NewArray[i] = arr[i - 1];
	}
	delete[] arr;
	arr = NewArray;
	NewArray = nullptr;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "¬ведите изначальную длину массива:\t";
	size = GetCorrectSize();
	cout << endl;
	string* arr = new string[size];

	FillArray(arr, size);
	PrintArray(arr, size);

	cout << "¬ведите номер элемента" << endl;
	int number;
	number = GetCorrectNumber(size);

	PushArray(arr, size, number);
	PrintArray(arr, size);


	delete[] arr;
	arr = nullptr;
}