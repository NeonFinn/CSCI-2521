/**
 * @file Exercise2_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 04/14/26
 * @brief translates user input into morse code
 */

#include <iostream>
#include <string>
#include <cctype> // allows for functions like toupper() and tolower()

using namespace std;

/**
 * @class MorseCodeTranslator
 * @brief translates characters into morse code
 */
class MorseCodeTranslator
{
private:
    string morseTable[26];

public:
    /**
     * @brief MorseCodeTranslator object and initializes the morse code table for the letters
     */
    MorseCodeTranslator()
    {
        morseTable[0] = ".-"; // A
        morseTable[1] = "-..."; // B
        morseTable[2] = "-.-."; // C
        morseTable[3] = "-.."; // D
        morseTable[4] = "."; // E
        morseTable[5] = "..-."; // F
        morseTable[6] = "--."; // G
        morseTable[7] = "...."; // H
        morseTable[8] = ".."; // I
        morseTable[9] = ".---"; // J
        morseTable[10] = "-.-"; // K
        morseTable[11] = ".-.."; // L
        morseTable[12] = "--"; // M
        morseTable[13] = "-."; // N
        morseTable[14] = "---"; // O
        morseTable[15] = ".--."; // P
        morseTable[16] = "--.-"; // Q
        morseTable[17] = ".-."; // R
        morseTable[18] = "..."; // S
        morseTable[19] = "-"; // T
        morseTable[20] = "..-"; // U
        morseTable[21] = "...-"; // V
        morseTable[22] = ".--"; // W
        morseTable[23] = "-..-"; // X
        morseTable[24] = "-.--"; // Y
        morseTable[25] = "--.."; // Z
    }

    /**
     * @brief converts all letters to uppercase
     * @param text the letters to convert
     * @return a copy of the string with all the letters uppercase
     */
    string toUpperCase(string text)
    {
        // loop through each character in the string
        for (int i = 0; i < text.length(); i++)
        {
            // convert to upper case
            text[i] = toupper(text[i]);
        }
        return text;
    }

    /**
     * @brief translates a letter to morse code
     * @param letter the character to translate
     * @return the letter as its morse code equivalent
     */
    string translateCharacter(char letter)
    {
        // convert the letter to uppercase
        letter = toupper(letter);

        // if its a valid letter
        if (letter >= 'A' && letter <= 'Z')
        {
            // find its alphabetical position and return the corresponding morse code
            return morseTable[letter - 'A'];
        }
        // ignore if its not a letter
        return "";
    }

    /**
     * @brief translates the sentence into morse code
     * @param sentence the sentence to translate
     * @return the user entered string now translated into morse code
     */
    string translateSentence(string sentence)
    {
        string result = "";

        // make the whole sentence uppercase
        sentence = toUpperCase(sentence);

        // for each character in the sentence
        for (size_t i = 0; i < sentence.length(); i++)
        {
            // translate it to morse code
            string morseSymbol = translateCharacter(sentence[i]);

            // if it is valid
            if (morseSymbol != "")
            {
                // add space between symbols
                if (result != "")
                {
                    result += " ";
                }

                // add the morse code to the previous result
                result += morseSymbol;
            }
        }

        // return translated sentence
        return result;
    }
};

/**
 * @class TranslationApp
 * @brief user interaction and execution for the translator
 */
class TranslationApp
{
private:
    MorseCodeTranslator translator;

    /**
     * @brief prompts the user for a sentence to translate
     * @return the sentence the user input
     */
    string getSentence()
    {
        string sentence;
        cout << "Enter a sentence (maximum 50 characters): ";
        // using gitline to include spaces
        getline(cin, sentence);
        return sentence;
    }

    /**
     * @brief checks if the entered text is shorter than 50 characters
     * @param sentence the text to check
     * @return true if sentence is less than 50 charaters
     */
    bool isValidLength(const string& sentence)
    {
        // check if the sentence is 50 characters or less
        return sentence.length() <= 50;
    }

    /**
     * @brief prompts the user if they want to translate another sentence
     * @return true if user wants to continue
     */
    bool askToContinue()
    {
        char choice;
        // ask if they want to keep translating
        cout << "\nWould you like to translate another sentence? (y/n): ";
        cin >> choice;
        cin.ignore(1000, '\n');

        // makes user input lowercase for easier checking
        choice = tolower(static_cast<unsigned char>(choice));

        // returns true if the user enters y
        return choice == 'y';
    }

public:
    /**
     * @brief runs the translation application
     */
    void run()
    {
        bool keepRunning = true;

        // run until players says they dont want to anymore
        while (keepRunning)
        {
            // get user input
            string sentence = getSentence();

            // keep asking for valid input until its given
            while (!isValidLength(sentence))
            {
                cout << "That sentence is too long. Please enter 50 characters or fewer.\n";
                sentence = getSentence();
            }

            // translate the sentence
            string morseCode = translator.translateSentence(sentence);

            // display result
            cout << "Morse Code: " << morseCode << endl;

            // ask if user wants to keep going
            keepRunning = askToContinue();
            cout << endl;
        }

        cout << "Program ended.\n";
    }
};

/**
 * @brief Entry point of the program.
 * @return 0 when the program finishes successfully.
 */
int main()
{
    TranslationApp app;
    app.run();
    return 0;
}