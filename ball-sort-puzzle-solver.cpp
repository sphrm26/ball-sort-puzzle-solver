#include <iostream>
#include <iomanip>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>

using namespace std;
using std::cout;

int conter = 0;

int rows = 5;
int columns = 15;
int stack = 0;
/*
char board[7][30] = {
    {'c', 'g', 'c', 'j', 'i', 'j', 'k', '*', 'i', '*', 'f', 'd', 'm', 'e', '*', '*'},
    {'p', 'j', 'c', 'f', 'm', 'd', 'o', 'e', 'k', 'e', 'h', 'n', 'd', 'g', '*', '*'},
    {'g', 'j', 'c', 'o', 'o', 'h', 'g', 'f', 'n', 'k', 'c', 'p', 'o', 'f', '*', '*'},
    {'h', 'p', 'l', 'i', 'j', 'n', 'h', 'p', 'g', 'e', 'k', 'e', 'd', 'n', '*', '*'},
    {'m', 'k', 'p', 'd', 'm', 'l', 'l', 'n', 'l', 'o', 'i', 'm', 'f', 'i', 'h', 'l'},
};
*/
char board[7][30] = {
    {'g', '*', 'i', 'o', '*', 'c', '*', '*', 'f', '*', 'j', 'k', 'o', '*', '*'},
    {'k', 'n', 'k', 'o', 'j', 'o', 'j', 'g', 'e', 'p', 'd', 'p', 'c', '*', '*'},
    {'g', 'e', 'f', 'e', 'e', 'i', 'f', 'c', 'g', 'n', 'f', 'f', 'j', 'm', '*'},
    {'h', 'e', 'c', 'p', 'o', 'k', 'h', 'k', 'n', 'j', 'p', 'n', 'c', 'm', 'd'},
    {'h', 'i', 'p', 'h', 'h', 'g', 'i', 'i', 'd', 'm', 'n', 'm', 'd', 'm', 'd'},
};

/*
char board[7][30] = {
    {'k', 'n', 'i', 'o', 'j', 'c', '*', 'g', 'f', 'p', '*', '*', 'o', '*', '*'},
    {'k', 'n', 'k', 'o', 'j', 'o', 'j', 'g', 'e', 'p', 'f', '*', 'c', '*', 'm'},
    {'g', 'e', 'f', 'e', 'e', 'i', 'f', 'c', 'g', 'n', 'f', '*', 'j', 'd', 'm'},
    {'h', 'e', 'c', 'p', 'o', 'k', 'h', 'k', 'n', 'j', 'p', '*', 'c', 'd', 'm'},
    {'h', 'i', 'p', 'h', 'h', 'g', 'i', 'i', 'd', 'm', 'n', '*', 'd', 'd', 'm'},
};
*/

bool ret = 0;
int movesRet;

int moves = 0;

class Board
{
public:
    char saveBoard[7][30];
    Board()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                saveBoard[i][j] = '*';
            }
        }
    }
};

void charPrinter(char s, bool p)
{
    switch (s)
    {
    case 'a':
        cout << "\x1b[38;5;";
        cout << 239 << 'm' << std::setw(4);

        break;
    case 'b':
        cout << "\x1b[38;5;";
        cout << 88 << 'm' << std::setw(4);

        break;
    case 'c':
        cout << "\x1b[38;5;";
        cout << 130 << 'm' << std::setw(4);

        break;
    case 'd':
        cout << "\x1b[38;5;";
        cout << 196 << 'm' << std::setw(4);

        break;
    case 'e':
        cout << "\x1b[38;5;";
        cout << 202 << 'm' << std::setw(4);

        break;
    case 'f':
        cout << "\x1b[38;5;";
        cout << 11 << 'm' << std::setw(4);

        break;
    case 'g':
        cout << "\x1b[38;5;";
        cout << 46 << 'm' << std::setw(4);

        break;
    case 'h':
        cout << "\x1b[38;5;";
        cout << 22 << 'm' << std::setw(4);

        break;
    case 'i':
        cout << "\x1b[38;5;";
        cout << 30 << 'm' << std::setw(4);

        break;
    case 'j':
        cout << "\x1b[38;5;";
        cout << 51 << 'm' << std::setw(4);

        break;
    case 'k':
        cout << "\x1b[38;5;";
        cout << 21 << 'm' << std::setw(4);

        break;
    case 'l':
        cout << "\x1b[38;5;";
        cout << 17 << 'm' << std::setw(4);

        break;
    case 'm':
        cout << "\x1b[38;5;";
        cout << 53 << 'm' << std::setw(4);

        break;
    case 'n':
        cout << "\x1b[38;5;";
        cout << 161 << 'm' << std::setw(4);

        break;
    case 'o':
        cout << "\x1b[38;5;";
        cout << 216 << 'm' << std::setw(4);

        break;
    case 'p':
        cout << "\x1b[38;5;";
        cout << 7 << 'm' << std::setw(4);

        break;
    case 'q':
        cout << "\x1b[38;5;";
        cout << 82 << 'm' << std::setw(4);

        break;
    case 'r':
        cout << "\x1b[38;5;";
        cout << 196 << 'm' << std::setw(4);

        break;
    case 's':
        cout << "\x1b[38;5;";
        cout << 82 << 'm' << std::setw(4);

        break;
    case 't':
        cout << "\x1b[38;5;";
        cout << 82 << 'm' << std::setw(4);

        break;
    case 'u':
        cout << "\x1b[38;5;";
        cout << 82 << 'm' << std::setw(4);

        break;
    case 'v':
        cout << "\x1b[38;5;";
        cout << 57 << 'm' << std::setw(4);

        break;
    case 'w':
        cout << "\x1b[38;5;";
        cout << 15 << 'm' << std::setw(4);

        break;
    case 'x':
        cout << "\x1b[38;5;";
        cout << 82 << 'm' << std::setw(4);

        break;
    case 'y':
        cout << "\x1b[38;5;";
        cout << 11 << 'm' << std::setw(4);

        break;
    case 'z':
        cout << "\x1b[38;5;";
        cout << 82 << 'm' << std::setw(4);

        break;
    default:
        cout << "\x1b[38;5;";
        cout << 82 << 'm' << std::setw(4);
        cout << " ";
        return;
    }
    if (p)
    {
        cout << char(2);
    }
}

void printBoard()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    // system("cls");
    for (int i = 0; i < rows; i++)
    {
        SetConsoleTextAttribute(h, 0x7);
        cout << "|";
        for (int j = 0; j < columns; j++)
        {
            charPrinter(board[i][j], 1);
            // cout << board[i][j];
            SetConsoleTextAttribute(h, 0x7);
            cout << "|";
        }
        cout << endl;
    }
}
void printSaveBoard(int s, Board saveBoards[5000])
{

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    // system("cls");
    for (int i = 0; i < rows; i++)
    {
        SetConsoleTextAttribute(h, 0x7);
        cout << "|";
        for (int j = 0; j < columns; j++)
        {
            charPrinter(saveBoards[s].saveBoard[i][j], 1);
            SetConsoleTextAttribute(h, 0x7);
            cout << "|";
        }
        cout << endl;
    }
}
void help(int move[1000][2], Board saveBoards[5000])
{
    system("cls");

    cout << "\x1b[38;5;";
    cout << 82 << 'm' << std::setw(4);

    cout << "I win\n";
    printBoard();
    getch();
    system("cls");
    for (int i = 0; i < 1000; i++)
    {
        printSaveBoard(i, saveBoards);
        cout << move[i][0];
        cout << " -> ";
        cout << move[i][1];
        cout << "\n";
        getch();
    }
}

bool checkWin()
{
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows - 1; j++)
        {
            if (board[j][i] != board[j + 1][i])
            {
                return (0);
            }
        }
    }
    return (1);
}

void back(int now, int back)
{
    char save;

    for (int i = 0; i < rows; i++)
    {
        if (board[i][now] != '*')
        {
            save = board[i][now];
            board[i][now] = '*';
            break;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        if (board[i + 1][back] != '*')
        {
            board[i][back] = save;
            break;
        }
    }
}

/*
char board[3][5] = {
    {'*', 'b', 'c', '*', '*'},
    {'c', 'a', 'b', '*', '*'},
    {'c', 'b', 'a', 'a', '*'}};

moves 1

move
1 -> 4
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
 ->
*/
/*
moves : تعداد حرکت ها
move[][] : کل حرکت ها
board[][] : صفحه اصلی بازی
rows : تعداد ردیف ها
columns : تعداد ستون ها
i : شماره ستون مهره برداشته شده
j : شماره ردیف مهره برداشته شده
k : شماره ستون محل جاگذاری
l : شماره ردیف محل جاگذاری
*/
bool checkRepeat()
{
    return (0);
}

void savingBoard(char saveBoard[7][30])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            saveBoard[i][j] = board[i][j];
        }
    }
}

// ستون از یک نوع که کامل نشده رو با خالی جا به جا نکن
bool chekSame(int i, int j, int l)
{
    for (int n = j; n < rows - 1; n++)
    {
        if (board[n][i] != board[n + 1][i])
        {
            return (0);
        }
    }
    if (l == rows - 1)
    {
        return (1);
    }
    return (0);
}

bool checkFull(int i)
{
    for (int j = 0; j < rows - 1; j++)
    {
        if (board[j][i] != board[j + 1][i])
        {
            return (0);
        }
    }
    return (1);
}
bool checkingSameBoard(Board saveBoards[5000])
{
    if (moves == 0)
    {
        return (0);
    }
    for (int s = conter - 1; s > 0; s--)
    {
        bool same = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (saveBoards[s].saveBoard[i][j] != board[i][j])
                {
                    same = 0;
                    break;
                }
            }
        }
        if (same)
        {
            movesRet = (moves - s) + 1;
            ret = 1;
            return (1);
        }
    }
    return (0);
}
bool checkSameFull(int i, int j, int k, int l)
{
    for (int s = j; s < rows - 2; s++)
    {
        if (!(board[s][i] == board[s + 1][i]))
        {
            return 0;
        }
    }
    if (l == rows - 1)
    {
        return 1;
    }
}
bool checkUnUseFulMove(int i, int j, int l, int k)
{
    int sotunNow = 0, sotunNext = 0;
    for (int s = j + 1; s < rows; s++)
    {
        if (board[s][i] == board[j][i])
        {
            sotunNow++;
        }
        else
        {
            break;
        }
    }
    for (int s = l + 1; s < rows; s++)
    {
        if (board[s][k] == board[j][i])
        {
            sotunNext++;
        }
        else
        {
            break;
        }
    }

    if (sotunNow == 0)
    {
        return (0);
    }

    if ((l + 1) >= sotunNow + 1)
    {
        return (0);
    }

    return (1);
}
void printHelpColor()
{
    for (int i = 97; i < 113; i++)
    {
        charPrinter(char(i), 1);
    }
    cout << endl;
    for (int i = 97; i < 113; i++)
    {
        charPrinter(char(i), 0);
        cout << char(i);
    }
    cout << endl;
    getch();
}
void choose(int move[1000][2], Board saveBoards[5000])
{
    conter++;
    if (checkWin())
    {
        help(move, saveBoards);
    }

    // if (checkingSameBoard(saveBoards, 1))
    // {
    //     return;
    // }

    checkingSameBoard(saveBoards);
    if (ret)
    {
        movesRet--;
        if (movesRet < -1)
        {
            ret = 0;
            movesRet = 0;
        }
        return;
    }

    for (int i = 0; i < columns; i++)
    {
        if (moves == 0 && 0)
        {
            i = rand() % columns;
        }
        for (int j = 0; j < rows; j++)
        {
            if (board[j - 1][i] != '*' && j != 0)
            {
                break;
            }
            if (board[j][i] == '*')
            {
                continue;
            }
            if ((board[j][i] != '*') && (board[j - 1][i] == '*' || j == 0))
            {
                if (j == 0)
                {
                    if (checkFull(i))
                    {
                        break;
                    }
                }
                for (int k = 0; k < columns; k++)
                {
                    for (int l = 0; l < rows; l++)
                    {
                        if (board[l][k] == '*')
                        {
                            if (checkRepeat())
                            {
                                break;
                            }
                            if ((board[l + 1][k] == board[j][i] || l == rows - 1) && !(i == k && j == l + 1))
                            {
                                if (checkUnUseFulMove(i, j, l, k))
                                {
                                    break;
                                }
                                if (checkSameFull(i, j, k, l))
                                {
                                    break;
                                }
                                if (!((i + 1 == move[moves - 1][1]) && (k + 1 == move[moves - 1][0])))
                                {
                                    if (chekSame(i, j, l))
                                    {
                                        break;
                                    }
                                    if (board[j - 1][i] != '*' && j != 0)
                                    {
                                        break;
                                    }

                                    if (board[j][i] == board[l][k])
                                    {
                                        break;
                                    }
                                    savingBoard(saveBoards[conter].saveBoard);

                                    board[l][k] = board[j][i];
                                    board[j][i] = '*';
                                    move[moves][0] = i + 1;
                                    move[moves][1] = k + 1;
                                    moves++;

                                    cout << board[l][k] << endl;
                                    cout << move[moves - 1][0] << " -> " << move[moves - 1][1] << "\n\n";

                                    system("cls");
                                    cout << board[j][i] << "  " << board[l][k] << endl;
                                    printBoard();
                                    cout << conter << "\n";
                                    cout << move[moves - 1][0] << " -> " << move[moves - 1][1] << "\n";
                                    cout << "l:" << l << "\n";
                                    cout << "j:" << j << "\n";
                                    cout << "k:" << k << "\n";
                                    cout << "i:" << i << "\n";
                                    cout << "moves: " << moves << "\n";

                                    // usleep(0.001 * 1000000);
                                    // if (moves > 30)
                                    // getch();

                                    choose(move, saveBoards);

                                    // cout << "ret\n";
                                    // usleep(0.25 * 1000000);

                                    moves--;
                                    back(move[moves][1] - 1, move[moves][0] - 1);
                                    move[moves][0] = 0;
                                    move[moves][1] = 0;
                                    // checkingSameBoard(saveBoards, 1);

                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    system("cls");
    /*
        cout << "tedad har rang: ";
        cin >> rows;
        cout << "tedad zarf ha: ";
        cin >> columns;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                board[i][j] = '*';
            }
        }
    */

    int i = 0;
    int j = 0;
    printHelpColor();
    printBoard();
    char input;
    /*
    for (int m = 0; m < (rows * (columns)); m++)
    {
        input = getch();
        if (input == '1')
        {
            if (i == 0 && j == 0)
            {
                m--;
                continue;
            }
            if (i == 0)
            {
                i = rows - 1;
                j--;
            }
            else
            {
                i--;
            }
            board[i][j] = '*';
            m -= 2;
            system("cls");
            printHelpColor();
            printBoard();
            continue;
        }
        board[i][j] = input;
        system("cls");
        printHelpColor();
        printBoard();
        i++;
        if (i == rows)
        {
            j++;
            i = 0;
        }
    }
    for (int i = rows - 2; i < rows; i++)
    {
        for (int j = columns - 2; j < columns; j++)
        {
            board[i][j] = '*';
        }
    }
    */

    printBoard();
    getch();

    Board saveBoards[5000];
    int move[1000][2];
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            move[i][j] = 0;
        }
    }
    choose(move, saveBoards);
    conter = 0;
    choose(move, saveBoards);
}