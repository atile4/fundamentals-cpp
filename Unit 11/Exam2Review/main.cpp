#include <iostream>
#include<cstring>

using namespace std;

char mostFrequentCharacter_String(string);
char mostFrequentCharacter_CString(char [], int);

int main()
{
    string example = "hello world";
    char other[] = "hi world";

    int N = strlen(other);

    cout << mostFrequentCharacter_String(example) << endl;
    cout << mostFrequentCharacter_CString(other, N) << endl;
    return 0;
}

char mostFrequentCharacter_String(string str)
{
    int size;
    int max = 0;
    char res;
    int count = 0;

    size = str.length();
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (str.at(j) == str.at(i))
            {
                count = count + 1;
            }
        }
        if (count > max)
        {
            max = count;
            res = str[i];
        }
    }
    return res;
}

char mostFrequentCharacter_CString(char arr[], int size)
{

    int max = 0;
    int count = 0;
    char res;

    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == arr[i])
            {
                count = count + 1;
            }
        }
        if (count > max)
        {
            max = count;
            res = arr[i];
        }
    }
    return res;
}
