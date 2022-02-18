#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

vector <char> stringToVector(string words);
vector <char> inverseEncrypterCalculator(vector <char> &elements);
vector <char> offsetEncrypterCalculator(vector <char> &elements);
void display(vector <char> &finalVec);


int main()
{
    string words;
    string answer;
    vector <char> wordsVector;

    cout << "Write something: ";
    getline(cin, words);
    wordsVector = stringToVector(words);

    while(answer != "4")
    {
        cout << "Would you like to invert the text (type '1'), offset it (type '2'), display it (type '3'), "
                "or quit (type '4')?: ";
        cin >> answer;

        if(answer == "1")
        {
            wordsVector = inverseEncrypterCalculator(wordsVector);
        }
        else if(answer == "2")
        {
            wordsVector = offsetEncrypterCalculator(wordsVector);
        }
        else if(answer == "3")
        {
            display(wordsVector);
            cout << endl;
        }
        else
        {
            break;
        }
        cout << endl << "Okay! What would you like to do next?" << endl;
    }
    cout << endl << "Thank you for trying the encrypter!" << endl;


    return 0;
}


///*****************************************************************************************************************///
/// This function takes a string and takes each character and puts it into a vector of chars which it then returns  ///
///*****************************************************************************************************************///

vector <char> stringToVector(string words)
{
    vector <char> wordsVector;
    for(int i = 0; i < words.length(); i++)
    {
        wordsVector.push_back(words[i]);
    }
    return wordsVector;
}


///*****************************************************************************************************************///
///      This function takes a vector of chars (created from a string sent to the stringToVector function) and      ///
///      converts the individual chars into their ASCII ints and then calculates their inverse and prints them      ///
///*****************************************************************************************************************///

vector <char> inverseEncrypterCalculator(vector <char> &elements)
{
    /// ASCII letters: 'A' = 65 & 'Z' = 90 && 'a' = 97 & 'z' = 122 ///
    /// ASCII numbers: '0' = 48 & '9' = 57 ///

    char character;

    for(int i = 0; i < elements.size(); i++)
    {
        if(isalpha(elements.at(i)))
        {
            switch(elements.at(i))
            {
                case 'A'...'Z':
                    character = char(91 - (int(elements.at(i)) - 64));
                    elements.at(i) = character;
                    break;

                case 'a'...'z':
                    character = char(123 - (int(elements.at(i)) - 96));
                    elements.at(i) = character;
                    break;

                default:
                    break;
            }
        }
        else if(isnumber(elements.at(i)))
        {
            character = char(58 - (int(elements.at(i)) - 47));
            elements.at(i) = character;
        }
    }
    return elements;
}


///*****************************************************************************************************************///
///      This function takes a vector of chars (created from a string sent to the stringToVector function) and      ///
///       converts the individual chars into their ASCII ints and then calculates the offset from the num that      ///
///                                      that the user inputs and then prints them                                  ///
///*****************************************************************************************************************///

vector <char> offsetEncrypterCalculator(vector <char> &elements)
{
    /// ASCII letters: 'A' = 65 & 'Z' = 90 && 'a' = 97 & 'z' = 122 ///
    /// ASCII numbers: '0' = 48 & '9' = 57 ///

    char character;
    int num;

    cout << "Offset by how much? ";
    cin >> num;

    for(int i = 0; i < elements.size(); i++)
    {
        if(isalpha(elements.at(i)))
        {
            switch(elements.at(i))
            {
                case 'A'...'Z':
                    if(((int(elements.at(i) - 64) + num) % 26) == 0)
                    {
                        character = char(((int(elements.at(i) - 64) + num) % 26) + 90);
                        elements.at(i) = character;
                    }
                    else
                    {
                        character = char((((int(elements.at(i)) - 64) + num) % 26) + 64);
                        elements.at(i) = character;
                    }
                    break;

                case 'a'...'z':
                    if(((int(elements.at(i) - 96) + num) % 26) == 0)
                    {
                        character = char(((int(elements.at(i) - 96) + num) % 26) + 122);
                        elements.at(i) = character;
                    }
                    else
                    {
                        character = char(((int(elements.at(i) - 96) + num) % 26) + 96);
                        elements.at(i) = character;
                    }
                    break;

                default:
                    break;
            }
        }
        else if(isnumber(elements.at(i)))
        {
            if((((int(elements.at(i)) - 47) + num) % 10) == 0)
            {
                character = char((((int(elements.at(i)) - 47) + num) % 10) + 57);
                elements.at(i) = character;
            }
            else
            {
                character = char((((int(elements.at(i)) - 47) + num) % 10) + 47);
                elements.at(i) = character;
            }

        }
    }
    return elements;
}


///*****************************************************************************************************************///
///                This is the display function, it displays the final vector of chars as a word                    ///
///*****************************************************************************************************************///

void display(vector <char> &finalVec)
{
    for(int i = 0; i < finalVec.size(); i++)
    {
        cout << finalVec.at(i);
    }
}
