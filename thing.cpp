#include <iostream>
#include <vector>
 
using namespace std;
 
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}
 
int draw_board(string arr[][3])
{
    system("cls");
 
    cout << "\nTic Tac Toe\n";
 
    cout << endl;
    cout << " -------------\n";
 
    for (int i = 0; i < 3; i++)
    {
        cout << " | ";
 
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j];
            cout << " | ";
        }
        cout << endl;
    }
    
    cout << " -------------\n";
 
    return 0;
}
 
 
int change_square(string arr[][3], string square, int player)
{
    if (isNumber(square))
    {
        int new_square = stoi(square);
 
        string sym;
 
        if (player == 1)
        {
            sym = "X";
        }else if (player == 2)
        {
            sym = "O";
        }
        
        
        if (new_square <= 3)
        {
            if (arr[0][new_square - 1] != "X" && arr[0][new_square - 1] != "O")
            {
                arr[0][new_square - 1] = sym;
                return 0;
            } 
        }else if (new_square <= 6)
        {
            if (arr[1][new_square - 4] != "X" && arr[1][new_square - 4] != "O")
            {
                arr[1][new_square - 4] = sym;
                return 0;
            }
        }else if (new_square <= 9)
        {
            if (arr[2][new_square - 7] != "X" && arr[2][new_square - 7] != "O")
            {
                arr[2][new_square - 7] = sym;
                return 0;
            }
        }else
        {
            return -1;
        }
    }else
    {
        return -1;
    } 
}
 
 
int check_if_win(string arr[][3])
{
    if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
    {
        return 1;
    }else if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
    {
        return 1;
    }else if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
    {
        return 1;
    }else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])
    {
        return 1;
    }else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])
    {
        return 1;
    }else if (arr[0][2] == arr[1][0] && arr[1][0] == arr[2][0])
    {
        return 1;
    }else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
    {
        return 1;
    }else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
    {
        return 1;
    }else if (arr[0][0] != "1" && arr[0][1] != "2" && arr[0][2] != "3" &&
                arr[1][0] != "4" && arr[1][1] != "5" && arr[1][2] != "6" &&
                    arr[2][0] != "7" && arr[2][1] != "8" && arr[2][2] != "9")
    {
        return 0;
    }else
    {
        return -1;
    } 
}
 
 
int main()
{
    system("cls");
 
    string player1;
    string player2;
 
    cout << "Player 1, please input your name: ";
    getline(cin, player1);
    
    cout << "Player 2, please input your name: ";
    getline(cin, player2);
 
    string input;
 
    do
    {
        int current_player = 1;
        string arr[3][3] = {
            {"1", "2", "3"},
            {"4", "5", "6"},
            {"7", "8", "9"},
        };
 
        system("cls");
 
        cout << "\nTic Tac Toe\n";
        cout << endl;
        cout << " -------------\n\n";
        cout << "1. Start a new game.\n0. Quit the game.\n";
        
        getline(cin, input);
 
        if (input == "1")
        {
            while (true)
            {
                string turn;
                int changed;
 
                draw_board(arr);
                
                if (current_player == 1)
                {
                    do
                    {
                        draw_board(arr);
                        cout << endl << player1 << " (X), make your turn!" << endl;
                        getline(cin, turn);
                        changed = change_square(arr, turn, current_player);
                    } while (changed != 0);  
                    draw_board(arr);
                    int win = check_if_win(arr);
                    if (win == -1)
                    {
                        current_player = 2;
                    }else if (win == 0)
                    {
                        cout << "It's a draw!\n\n";
                        system("pause");
                        break;
                    }else if (win == 1)
                    {
                        cout << player1 << " won the game!\n\n";
                        system("pause");
                        break;
                    }
                    current_player = 2;
                }else if (current_player == 2)
                {
                    do
                    {
                        draw_board(arr);
                        cout << endl << player2 << " (O), make your turn!" << endl;
                        getline(cin, turn);
                        changed = change_square(arr, turn, current_player);
                    } while (changed != 0);  
                    draw_board(arr);
                    int win = check_if_win(arr);
 
                    if (win == -1)
                    {
                        current_player = 2;
                    }else if (win == 0)
                    {
                        cout << "It's a draw!\n\n";
                        system("pause");
                        break;
                    }else if (win == 1)
                    {
                        cout << player2 << " won the game!\n\n";
                        system("pause");
                        break;
                    }
                    current_player = 1;
                }
            }
            
        }else
        {
            system("cls");
 
            cout << "\nTic Tac Toe\n";
            cout << endl;
            cout << " -------------\n\n";
            cout << "1. Start a new game.\n0. Quit the game.\n";
        }
        
    } while (input != "0");
}