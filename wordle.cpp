#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <fstream>
#include <sstream>
#include "SFML/Graphics.hpp"
#include "SFML/Window/Mouse.hpp"
//including classes
#include "Button.h"
#include "TextObject.h"

using namespace std;

//defining colours
#define objectColour sf::Color(170, 170, 170)
#define buttonColour sf::Color(204, 77, 5)
#define greenColour sf::Color(100, 200, 100)
#define yellowColour sf::Color(200, 150, 0)
//global variables
vector<string> inps = { "     ", "     ", "     ", "     ", "     ", "     " };
int currentInput;

bool keyboardButtonsEnabled = true;

string word;
//setting font size
sf::Font font;
int fontSize = 30;

//defining 2D vectors of TextObject
vector<vector<TextObject>> textObjects = { {
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(260, 110), objectColour, sf::Text("Q", font, fontSize)), // [0][0] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(320, 110), objectColour, sf::Text("Q", font, fontSize)), // [0][1] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(380, 110), objectColour, sf::Text("Q", font, fontSize)), // [0][2] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(440, 110), objectColour, sf::Text("Q", font, fontSize)), // [0][3] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(500, 110), objectColour, sf::Text("Q", font, fontSize)) // [0][4] 
        }, {
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(260, 110 + 60), objectColour, sf::Text("Q", font, fontSize)), // [1][0] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(320, 110 + 60), objectColour, sf::Text("Q", font, fontSize)), // [1][1] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(380, 110 + 60), objectColour, sf::Text("Q", font, fontSize)), // [1][2] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(440, 110 + 60), objectColour, sf::Text("Q", font, fontSize)), // [1][3] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(500, 110 + 60), objectColour, sf::Text("Q", font, fontSize)) // [1][4] 
        },{
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(260, 110 + 120), objectColour, sf::Text("Q", font, fontSize)), // [2][0] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(320, 110 + 120), objectColour, sf::Text("Q", font, fontSize)), // [2][1] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(380, 110 + 120), objectColour, sf::Text("Q", font, fontSize)), // [2][2] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(440, 110 + 120), objectColour, sf::Text("Q", font, fontSize)), // [2][3] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(500, 110 + 120), objectColour, sf::Text("Q", font, fontSize)) // [2][4] 
        },{
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(260, 110 + 180), objectColour, sf::Text("Q", font, fontSize)), // [3][0] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(320, 110 + 180), objectColour, sf::Text("Q", font, fontSize)), // [3][1] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(380, 110 + 180), objectColour, sf::Text("Q", font, fontSize)), // [3][2] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(440, 110 + 180), objectColour, sf::Text("Q", font, fontSize)), // [3][3] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(500, 110 + 180), objectColour, sf::Text("Q", font, fontSize)) // [3][4] 
        },{
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(260, 110 + 240), objectColour, sf::Text("Q", font, fontSize)), // [4][0] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(320, 110 + 240), objectColour, sf::Text("Q", font, fontSize)), // [4][1] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(380, 110 + 240), objectColour, sf::Text("Q", font, fontSize)), // [4][2] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(440, 110 + 240), objectColour, sf::Text("Q", font, fontSize)), // [4][3] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(500, 110 + 240), objectColour, sf::Text("Q", font, fontSize)) // [4][4] 
        },{
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(260, 110 + 300), objectColour, sf::Text("Q", font, fontSize)), // [5][0] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(320, 110 + 300), objectColour, sf::Text("Q", font, fontSize)), // [5][1] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(380, 110 + 300), objectColour, sf::Text("Q", font, fontSize)), // [5][2] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(440, 110 + 300), objectColour, sf::Text("Q", font, fontSize)), // [5][3] 
        TextObject(sf::Vector2f(50, 50), sf::Vector2f(500, 110 + 300), objectColour, sf::Text("Q", font, fontSize)) // [5][4] 
        }
};

//defining vectors of Buttons
vector<Button> buttons = {
    Button(sf::Vector2f(50, 50), sf::Vector2f(140, 640), buttonColour, sf::Text("A", font, fontSize), Button::ButtonType::Letter), // a
    Button(sf::Vector2f(50, 50), sf::Vector2f(440, 700), buttonColour, sf::Text("B", font, fontSize), Button::ButtonType::Letter), // b
    Button(sf::Vector2f(50, 50), sf::Vector2f(320, 700), buttonColour, sf::Text("C", font, fontSize), Button::ButtonType::Letter), // c
    Button(sf::Vector2f(50, 50), sf::Vector2f(260, 640), buttonColour, sf::Text("D", font, fontSize), Button::ButtonType::Letter), // d
    Button(sf::Vector2f(50, 50), sf::Vector2f(230, 580), buttonColour, sf::Text("E", font, fontSize), Button::ButtonType::Letter), // e
    Button(sf::Vector2f(50, 50), sf::Vector2f(320, 640), buttonColour, sf::Text("F", font, fontSize), Button::ButtonType::Letter), // f
    Button(sf::Vector2f(50, 50), sf::Vector2f(380, 640), buttonColour, sf::Text("G", font, fontSize), Button::ButtonType::Letter), // g
    Button(sf::Vector2f(50, 50), sf::Vector2f(440, 640), buttonColour, sf::Text("H", font, fontSize), Button::ButtonType::Letter), // h
    Button(sf::Vector2f(50, 50), sf::Vector2f(530, 580), buttonColour, sf::Text("I", font, fontSize), Button::ButtonType::Letter), // i
    Button(sf::Vector2f(50, 50), sf::Vector2f(500, 640), buttonColour, sf::Text("J", font, fontSize), Button::ButtonType::Letter), // j
    Button(sf::Vector2f(50, 50), sf::Vector2f(560, 640), buttonColour, sf::Text("K", font, fontSize), Button::ButtonType::Letter), // k
    Button(sf::Vector2f(50, 50), sf::Vector2f(629, 640), buttonColour, sf::Text("L", font, fontSize), Button::ButtonType::Letter), // l
    Button(sf::Vector2f(50, 50), sf::Vector2f(560, 700), buttonColour, sf::Text("M", font, fontSize), Button::ButtonType::Letter), // m
    Button(sf::Vector2f(50, 50), sf::Vector2f(500, 700), buttonColour, sf::Text("N", font, fontSize), Button::ButtonType::Letter), // n
    Button(sf::Vector2f(50, 50), sf::Vector2f(590, 580), buttonColour, sf::Text("O", font, fontSize), Button::ButtonType::Letter), // o
    Button(sf::Vector2f(50, 50), sf::Vector2f(650, 580), buttonColour, sf::Text("P", font, fontSize), Button::ButtonType::Letter), // p
    Button(sf::Vector2f(50, 50), sf::Vector2f(110, 580), buttonColour, sf::Text("Q", font, fontSize), Button::ButtonType::Letter), // q
    Button(sf::Vector2f(50, 50), sf::Vector2f(290, 580), buttonColour, sf::Text("R", font, fontSize), Button::ButtonType::Letter), // r
    Button(sf::Vector2f(50, 50), sf::Vector2f(200, 640), buttonColour, sf::Text("S", font, fontSize), Button::ButtonType::Letter), // s
    Button(sf::Vector2f(50, 50), sf::Vector2f(350, 580), buttonColour, sf::Text("T", font, fontSize), Button::ButtonType::Letter), // t
    Button(sf::Vector2f(50, 50), sf::Vector2f(470, 580), buttonColour, sf::Text("U", font, fontSize), Button::ButtonType::Letter), // u
    Button(sf::Vector2f(50, 50), sf::Vector2f(380, 700), buttonColour, sf::Text("V", font, fontSize), Button::ButtonType::Letter), // v
    Button(sf::Vector2f(50, 50), sf::Vector2f(170, 580), buttonColour, sf::Text("W", font, fontSize), Button::ButtonType::Letter), // w
    Button(sf::Vector2f(50, 50), sf::Vector2f(260, 700), buttonColour, sf::Text("X", font, fontSize), Button::ButtonType::Letter), // x
    Button(sf::Vector2f(50, 50), sf::Vector2f(410, 580), buttonColour, sf::Text("Y", font, fontSize), Button::ButtonType::Letter), // y
    Button(sf::Vector2f(50, 50), sf::Vector2f(200, 700), buttonColour, sf::Text("Z", font, fontSize), Button::ButtonType::Letter), // z

    Button(sf::Vector2f(100, 50), sf::Vector2f(50, 700), buttonColour, sf::Text("Enter", font, fontSize), Button::ButtonType::Enter), // enter

    Button(sf::Vector2f(100, 50), sf::Vector2f(650, 700), buttonColour, sf::Text("Delete", font, fontSize), Button::ButtonType::Delete) // backspace
};
sf::Text nText = sf::Text("igozdev", font, 20);
Button resetButton(sf::Vector2f(100, 50), sf::Vector2f(360, 30), buttonColour, sf::Text("Reset", font, fontSize), Button::ButtonType::Reset);

sf::Text endText = sf::Text("", font, 25);

vector<string> words;

char NormalizeCase(char c)
{
    if (c >= 65 && c <= 90)
        return c + 32;
    else return c;
}

string get_file_contents(const char* filename)
{
    ifstream t(filename);
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

void GetWords()
{
    int wordveccount = 0;

    string buff = get_file_contents("wordlist.txt");
    string wordbuff = "";
    for (char c : buff)
    {
        if (c != '\n')
        {
            wordbuff += NormalizeCase(c);
        }
        if (c == '\n')
        {
            words.resize(words.size() + 1);
            words[wordveccount] = wordbuff;
            wordbuff = "";
            wordveccount++;
        }
    }
}

void Loose()
{
    keyboardButtonsEnabled = false;
    endText.setString(string("You lost. The word was \"") + word + string("\".\nPress reset to start again"));
    cout << "\nLoose state";
}

void Win()
{
    keyboardButtonsEnabled = false;
    endText.setString(std::string("You won in ") + to_string(currentInput) + string(" guess(es).\nPress reset to start again"));
    cout << "\nWin state";
}

bool LetterPresent(char letter, string word)
{
    for (char c : word)
        if (letter == c)
            return true;
    return false;
}

void GenWord()
{
    word = words[rand() % words.size()];
}

void UpdateTextObjectText()
{
    for (int i = 0; i < 5; i++)
    {
        textObjects[currentInput][i].SetText(inps[currentInput][i]);
    }
}

void ResetTextObjects()
{
    for (int ic = 0; ic < 6; ic++)
        for (int i = 0; i < 5; i++)
        {
            textObjects[ic][i].SetColour(objectColour);
            textObjects[ic][i].SetText(" ");
        }

    for (int i = 0; i < 26; i++)
        buttons[i].SetColour(buttonColour);
}

bool IsValidWord(string input)
{
    for (string word : words)
        if (input == word)
            return true;
    return false;
}

void AddLetter(char letter)
{
    for (int i = 0; i < 5; i++)
    {
        if (inps[currentInput][i] == ' ')
        {
            inps[currentInput][i] = letter;
            break;
        }
    }
}

void RemoveLetter()
{
    for (int i = 0; i < 5; i++)
    {
        if (inps[currentInput][i] == ' ' && i - 1 > -1)
        {
            inps[currentInput][i - 1] = ' ';
            break;
        }
        if (i == 5 - 1)
            inps[currentInput][i] = ' ';
    }
}

enum LetterState
{
    None, Present, Correct
};

void UpdateKeyboardColour(char letter, LetterState state)
{
    int buttonIndex = letter - 97;
    switch (state)
    {
    case None:
        buttons[buttonIndex].SetColour(objectColour);
        break;

    case Present:
        buttons[buttonIndex].SetColour(yellowColour);
        break;

    case Correct:
        buttons[buttonIndex].SetColour(greenColour);
        break;
    }
}

void Enter()
{
    string checkWord = inps[currentInput];
    for (int i = 0; i < 5; i++)
        checkWord[i] = NormalizeCase(checkWord[i]);

    // If current word is valid, 
    if (IsValidWord(checkWord))
    {
        int numCorrect = 0;

        for (int i = 0; i < 5; i++)
        {
            if (checkWord[i] == word[i])
            {
                numCorrect++;
                textObjects[currentInput][i].SetColour(greenColour);
                UpdateKeyboardColour(checkWord[i], Correct);
            }
            else if (LetterPresent(checkWord[i], word))
            {
                textObjects[currentInput][i].SetColour(yellowColour);
                UpdateKeyboardColour(checkWord[i], Present);
            }
            else
            {
                UpdateKeyboardColour(checkWord[i], None);
            }
        }

        currentInput++;
        if (numCorrect == 5)
        {
            Win();
        }
        else
        {
            if (currentInput >= 6)
            {
                Loose();
            }
        }
    }
}

void Reset()
{
    keyboardButtonsEnabled = true;
    currentInput = 0;
    inps = { "     ", "     ", "     ", "     ", "     ", "     " };
    endText.setString("");
    ResetTextObjects();
    GenWord();
}

void ButtonAction(Button button)
{
    Button::ButtonType type = button.GetButtonType();
    switch (type)
    {
    case Button::ButtonType::Letter:
        cout << "\nLetter: " << (char)button.GetText()[0];
        AddLetter((char)button.GetText()[0]);
        UpdateTextObjectText();
        break;

    case Button::ButtonType::Enter:
        cout << "\nEnter";
        Enter();
        break;

    case Button::ButtonType::Delete:
        cout << "\nDelete";
        RemoveLetter();
        UpdateTextObjectText();
        break;

    case Button::ButtonType::Reset:
        cout << "\nReset";
        Reset();
        break;
    }
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 800), "wordle", sf::Style::Titlebar | sf::Style::Close);
    sf::Mouse mouse;
    font.loadFromFile("font.ttf");
    GetWords();

    sf::Font font;
    if (!font.loadFromFile("C:/Users/Administrator/OneDrive/Documents/cpp/Project1/Project1/font.ttf")) {
        //handle font loading failure
        return EXIT_FAILURE;
    }

    Reset();
    for (int i = 0; i < 6; i++)
        for (int ic = 0; ic < 5; ic++)
            textObjects[i][ic].SetText(" ");

    nText.setPosition(370, 760);

    //Game will play on loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (keyboardButtonsEnabled)
                    for (Button button : buttons)
                        if (button.MouseCollides(mouse, window))
                            ButtonAction(button);
                if (resetButton.MouseCollides(mouse, window))
                    ButtonAction(resetButton);
            }
        }

        window.clear(sf::Color(20, 30, 50)); // Color background
        for (Button button : buttons)
            button.DrawObject(window);
        for (vector<TextObject> textObjectVec : textObjects)
            for (TextObject textObject : textObjectVec)
                textObject.DrawObject(window);
        resetButton.DrawObject(window);

        window.draw(endText);
        window.draw(nText);

        window.display();   //window is done drawing
    }

    return 0;
}
