#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ios>
#include <algorithm>
#include <ctime>
#include <istream>

void buildBoard(std::vector < std::vector < std::pair <char, int> > > &board)
{
    std::vector <std::pair <char, int> > line;
    for (int i = 0; i < 15; i++)
    {
        board.push_back(line);
        for (int j = 0; j < 15; j++)
        {
            std::pair <char, int> pair;
            pair.first = '-';
            pair.second = 0;
            board.at(i).push_back(pair);
            //std::cout << pair.first << std::endl;
        }
    }
    /* Assign special spots
     *
     * 0 = none
     * 1 = triple word
     * 2 = triple letter
     * 3 = double word
     * 4 = double letter
     */
    //row  1
    board.at(0).at(0).second = 1;
    board.at(0).at(3).second = 4;
    board.at(0).at(7).second = 1;
    board.at(0).at(11).second = 4;
    board.at(0).at(14).second = 1;
    //row 2
    board.at(1).at(1).second = 3;
    board.at(1).at(5).second = 2;
    board.at(1).at(9).second = 2;
    board.at(1).at(13).second = 3;
    //row 3
    board.at(2).at(2).second = 3;
    board.at(2).at(6).second = 4;
    board.at(2).at(8).second = 4;
    board.at(2).at(12).second = 3;
    //row 4
    board.at(3).at(0).second = 4;
    board.at(3).at(3).second = 3;
    board.at(3).at(7).second = 4;
    board.at(3).at(11).second = 3;
    board.at(3).at(14).second = 4;
    //row 5
    board.at(4).at(4).second = 3;
    board.at(4).at(10).second = 3;
    //row 6
    board.at(5).at(1).second = 2;
    board.at(5).at(5).second = 2;
    board.at(5).at(9).second = 2;
    board.at(5).at(13).second = 2;
    //row 7
    board.at(6).at(2).second = 4;
    board.at(6).at(6).second = 4;
    board.at(6).at(8).second = 4;
    board.at(6).at(12).second = 4;
    //row 8
    board.at(7).at(0).second = 1;
    board.at(7).at(3).second = 4;
    board.at(7).at(7).second = 3;
    board.at(7).at(11).second = 4;
    board.at(7).at(14).second = 1;
    //row 9
    board.at(8).at(2).second = 4;
    board.at(8).at(6).second = 4;
    board.at(8).at(8).second = 4;
    board.at(8).at(12).second = 4;
    //row 10
    board.at(9).at(1).second = 2;
    board.at(9).at(5).second = 2;
    board.at(9).at(9).second = 2;
    board.at(9).at(13).second = 2;
    //row 11
    board.at(10).at(4).second = 3;
    board.at(10).at(10).second = 3;
    //row 12
    board.at(11).at(0).second = 4;
    board.at(11).at(3).second = 3;
    board.at(11).at(7).second = 4;
    board.at(11).at(11).second = 3;
    board.at(11).at(14).second = 4;
    //row 13
    board.at(12).at(2).second = 3;
    board.at(12).at(6).second = 4;
    board.at(12).at(8).second = 4;
    board.at(12).at(12).second = 3;
    //row 14
    board.at(13).at(1).second = 3;
    board.at(13).at(5).second = 2;
    board.at(13).at(9).second = 2;
    board.at(13).at(13).second = 3;
    //row 15
    board.at(14).at(0).second = 1;
    board.at(14).at(3).second = 4;
    board.at(14).at(7).second = 1;
    board.at(14).at(11).second = 4;
    board.at(14).at(14).second = 1;
}

void resetBoard(std::vector < std::vector < std::pair <char, int> > > &board)
{
    for (unsigned int i = 0; i < board.size(); i ++)
    {
        for (unsigned int j = 0; j < board.size(); j++)
        {
            board.at(i).at(j).first = '-';
        }
    }
}

void printBoard(std::vector < std::vector < std::pair <char, int> > > &board)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            std::cout << board.at(i).at(j).first << /*board.at(i).at(j).second <<*/ " ";
        }
        std::cout << std::endl;
    }
}

bool readSowpodsToVector(std::vector <std::string> &sowpodsList)
{
    std::cout << "Please paste the absolute pad to the SOWPODS word list: \n";
    std::string path;
    std::getline(std::cin, path);
    std::replace(path.begin(), path.end(), '\\', '/');
    std::ifstream file(path);
    if (file.good() == false)
    {
        std::cout << "Couldn not read file, please check path and try again.\n";
        return false;
    }
    else
    {
        std::string line;
        while(std::getline(file, line))
        {
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
            sowpodsList.push_back(line);
        }
        return true;
    }
}

void generateTiles(std::string &myTiles)
{
    std::cout << "Please type the desired initial 7 tiles as a string: \n";
    //to lower case
    std::getline(std::cin, myTiles);
    while (myTiles.size() != 7)
    {
        std::cout << "String has to have exactly 7 characters, please try again: ";
        std::getline(std::cin, myTiles);
    }
    std::transform(myTiles.begin(), myTiles.end(), myTiles.begin(), ::tolower);
}

void swap(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void printResults(std::string myTiles, std::pair <std::pair <std::string, int>, int> &optimalMove, double &duration,
                  std::clock_t &start)
{
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    if (optimalMove.first.first == "")
    {
        std::cout << "RACK: " << myTiles << std::endl;
        std::cout << "EXHANGE: " << myTiles.at(0) << myTiles.at(1) << std::endl;
        std::cout << "DURATION: " << duration << std::endl;
    }
    else
    {
        std::cout << "RACK: " << myTiles << std::endl;
        std::cout << "PLACE WORD: " << optimalMove.first.first << " " << optimalMove.first.second <<
                     " " << optimalMove.second << std::endl;
        std::cout << "DURATION: " << duration << std::endl;
    }
}

int getLetterPoints(char &letter)
{
    if ((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u')
            || (letter == 'l') || (letter == 'n') || (letter == 's') || (letter == 't') || (letter == 'r'))
    {
        return 1;
    }
    else if ((letter == 'd') || (letter == 'g'))
    {
        return 2;
    }
    else if ((letter == 'b') || (letter == 'c') || (letter == 'm') || (letter == 'p'))
    {
        return 3;
    }
    else if ((letter == 'f') || (letter == 'h') || (letter == 'v') || (letter == 'w') || (letter == 'y'))
    {
        return 4;
    }
    else if (letter == 'k')
    {
        return 5;
    }
    else if ((letter == 'j') || (letter == 'x'))
    {
        return 8;
    }
    else if ((letter == 'q') || (letter == 'z'))
    {
        return 10;
    }
    else
    {
        return 0;
    }
}

/* Assign special spots
 *
 * 0 = none
 * 1 = triple word
 * 2 = triple letter
 * 3 = double word
 * 4 = double letter
 */
int calculateWordPoints(std::vector < std::vector < std::pair <char, int> > > &board)
{
    int points = 0;
    bool wordIsHorizontal = false;
    bool doubleWord = false;
    bool tripleWord = false;
    if (board.at(7).at(6).first != '-' || board.at(7).at(8).first != '-')
    {
        wordIsHorizontal = true;
    }

    if (wordIsHorizontal == true)
    {
        for (unsigned int i = 0; i < board.size(); ++i)
        {
            if (board.at(7).at(i).first != '-' && board.at(7).at(i).second == 0)
            {
                points += getLetterPoints(board.at(7).at(i).first);
            }
            else if(board.at(7).at(i).first != '-' && board.at(7).at(i).second == 1)
            {
                points += getLetterPoints(board.at(7).at(i).first);
                tripleWord = true;
            }
            else if(board.at(7).at(i).first != '-' && board.at(7).at(i).second == 2)
            {
                points += (getLetterPoints(board.at(7).at(i).first) * 3 );
            }
            else if(board.at(7).at(i).first != '-' && board.at(7).at(i).second == 3)
            {
                points += getLetterPoints(board.at(7).at(i).first);
                doubleWord = true;
            }
            else if(board.at(7).at(i).first != '-' && board.at(7).at(i).second == 4)
            {
                points += (getLetterPoints(board.at(7).at(i).first) * 2 );
            }
        }
    }
    //check for double/triple word
    if (tripleWord == true)
    {
        points = points*3;
    }
    else if (doubleWord == true)
    {
        points = points*2;
    }
    return points;
}

void placeWordInBoard(std::vector < std::vector < std::pair <char, int> > > &board, std::string &word,
                      std::pair <std::pair <std::string, int>, int> &optimalMove)
{
    //try horizontally
    int wordPoints = 0;
    unsigned int j = 0;
    for (unsigned int i = 0; i < word.size(); ++i)
    {
        for (j = 0; j < word.size(); ++j)
        {
            board.at(7).at(7-(word.size()-j-i-1)).first = word.at(j);
        }
        printBoard(board);
        wordPoints = calculateWordPoints(board);
        //save if points > than last word
        if (wordPoints > optimalMove.second)
        {
            optimalMove.first.first = word;
            optimalMove.first.second = (j-word.size());
            optimalMove.second = wordPoints;
        }
        resetBoard(board);
        std::cout << word << " " << wordPoints << std::endl;
    }
}

void wordExistsInSowpodsList(std::string &word, std::vector <std::string> &sowpodsList,
                             std::vector < std::vector < std::pair <char, int> > > &board,
                             std::pair <std::pair <std::string, int>, int> &optimalMove)
{
    for (unsigned int i = 0; i < sowpodsList.size(); i = i+4)
    {
        if (word.find(sowpodsList.at(i)) != std::string::npos)
        {
            //std::cout << "Found: " << sowpodsList.at(i) << std::endl;
            placeWordInBoard(board, sowpodsList.at(i), optimalMove);

            //eliminate after used to increase performance
            sowpodsList.erase(sowpodsList.begin() + i);
        }
    }
}

void permute(std::string s, int i, int n, int &counter, std::vector <std::string> &sowpodsList,
             std::vector < std::vector < std::pair <char, int> > > &board,
             std::pair <std::pair <std::string, int>, int> &optimalMove)
{
    unsigned int j;
    if (i == n)
    {
        counter++;
        (wordExistsInSowpodsList(s, sowpodsList, board, optimalMove));
    }
    else
    {
        for (j = i; j < s.length(); j++)
        {
            swap(s[i],s[j]);
            permute(s, i + 1, n, counter, sowpodsList, board, optimalMove);
            swap(s[i],s[j]);
        }
    }
}

int main()
{
    //variable declarations
    std::clock_t start;
    double duration;
    std::vector < std::vector < std::pair <char, int> > > board;
    std::vector <std::string> sowpodsList;
    std::string myTiles;
    std::pair <std::pair <std::string, int>, int> optimalMove; //word, location (x-axis), word points

    //variable assignments
    optimalMove.first.first = "";
    optimalMove.first.second = 0;
    optimalMove.second = 0;
    int counter = 0;

    if (readSowpodsToVector(sowpodsList) == true)
    {
         buildBoard(board);
         generateTiles(myTiles);
         start = std::clock();
         std::cout << "Please wait..." << std::endl;
         permute(myTiles, 0, myTiles.size()-1, counter, sowpodsList, board, optimalMove);
         printResults(myTiles, optimalMove, duration, start);

    }

    std::cout << "\nFinish" << std::endl;
    return 0;
}
