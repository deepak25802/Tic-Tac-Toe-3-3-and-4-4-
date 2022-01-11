#include <iostream>
#include <unordered_set>
#include <ctime>
#include <windows.h>
using namespace std;
class game_3
{
private:
	int board[3][3];

public:
	game_3()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = 0;
			}
		}
	}
	friend class players;
	bool check_result()
	{
		for (int i = 0; i < 3; i++)
		{
			if ((board[0][i] != 0) && (board[0][i] == board[1][i] && board[2][i] == board[1][i]))
				return true;
		}
		for (int i = 0; i < 3; i++)
		{
			if ((board[i][0] != 0) && (board[i][0] == board[i][1] && board[i][2] == board[i][1]))
				return true;
		}
		if ((board[0][0] != 0) && board[0][0] == board[1][1] && board[2][2] == board[1][1])
			return true;
		if ((board[1][1] != 0) && (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
			return true;
		return false;
	}

	void printBoard()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		;
		int col = 4;
		FlushConsoleInputBuffer(hConsole);
		SetConsoleTextAttribute(hConsole, col);
		cout << endl;
		cout << "   |   |   " << endl;
		cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
		cout << "   |   |   " << endl;
		cout << "-----------" << endl;
		cout << "   |   |   " << endl;
		cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
		cout << "   |   |   " << endl;
		cout << "-----------" << endl;
		cout << "   |   |   " << endl;
		cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
		cout << "   |   |   " << endl;
		cout << endl;

		SetConsoleTextAttribute(hConsole, 9);
	}
};
class game_4
{
private:
	int board[4][4];
	bool key;

public:
	game_4()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				board[i][j] = 0;
			}
		}
	}
	friend class players;
	bool check_result()
	{
		if (((board[0][2] != 0) && board[2][0] != 0) && board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == board[0][2])
			return true;
		if ((board[0][1] != 0) && board[0][1] == board[1][2] && board[1][2] == board[2][3])
			return true;
		if ((board[1][3] != 0) && board[1][3] == board[2][2] && board[2][2] == board[3][1])
			return true;
		if ((board[1][0] != 0) && board[1][0] == board[2][1] && board[2][1] == board[3][2])
			return true;
		for (int i = 0; i < 4; i++)
		{
			if ((board[0][i] != 0) && (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[3][i] == board[2][i]))
				return true;
		}
		for (int i = 0; i < 4; i++)
		{
			if ((board[i][0] != 0) && (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][3] == board[i][2]))
				return true;
		}
		if ((board[0][0] != 0) && board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[3][3] == board[2][2])
			return true;
		if ((board[0][3] != 0) && (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[3][0] == board[2][1]))
			return true;
		return false;
	}
	void printBoard()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		FlushConsoleInputBuffer(hConsole);
		SetConsoleTextAttribute(hConsole, 4);
		cout << endl;
		cout << "   |   |   |   " << endl;
		cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << board[0][3] << endl;
		cout << "   |   |   |   " << endl;
		cout << "---------------" << endl;
		cout << "   |   |   |   " << endl;
		cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << board[1][3] << endl;
		cout << "   |   |   |   " << endl;
		cout << "---------------" << endl;
		cout << "   |   |   |   " << endl;
		cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << board[2][3] << endl;
		cout << "   |   |   |   " << endl;
		cout << "---------------" << endl;
		cout << "   |   |   |   " << endl;
		cout << " " << board[3][0] << " | " << board[3][1] << " | " << board[3][2] << " | " << board[3][3] << endl;
		cout << "   |   |   |   " << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, 9);
	}
};

class players
{
public:
	void two_players(game_3 &x)
	{
		int x1, move, i;
		unordered_set<int> check;
		for (i = 0; i < 9; i++)
		{
			if (i % 2 == 0)
				x1 = 1;
			else
				x1 = 2;
		label:
			cout << "\nEnter your move :- ";
			cin >> move;
			if (check.find(move) != check.end())
			{
				cout << "\n--------------------------------------------------------------------------------------\n";
				cout << "Position Already occupied" << endl;
				cout << "\n--------------------------------------------------------------------------------------\n";
				goto label;
			}
			check.insert(move);
			switch (move)
			{
			case 1:
				x.board[0][0] = x1;
				break;
			case 2:
				x.board[0][1] = x1;
				break;
			case 3:
				x.board[0][2] = x1;
				break;
			case 4:
				x.board[1][0] = x1;
				break;
			case 5:
				x.board[1][1] = x1;
				break;
			case 6:
				x.board[1][2] = x1;
				break;
			case 7:
				x.board[2][0] = x1;
				break;
			case 8:
				x.board[2][1] = x1;
				break;
			case 9:
				x.board[2][2] = x1;
				break;
			}
			cout << "\nPlayer " << x1 << " choosed " << move << " position..\n";
			cout << "\n--------------------------------------------------------------------------------------\n";
			cout << "\nThe board after the move is :-\n\n\n";
			x.printBoard();
			cout << "\n====================================================================================\n";
			cout << "\n\n\n";

			if (x.check_result())
			{
				cout << "Player " << x1 << " WON\n";
				break;
			}
		}
		if (i == 9)
		{
			cout << "The game TIES!!..\n";
		}
	}
	void one_player(game_3 &x)
	{
		int x1;
		int move;
		unordered_set<int> check;
		int i, j;
		char c;
		cout << "Dare to go first ?(Y/N):- ";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			i = 0;
			j = 9;
		}
		else
		{
			i = 1;
			j = 10;
		}
		for (i; i < j; i++)
		{
		label:
			if (i % 2 == 0)
			{
				cout << "\nEnter your move :- ";
				x1 = 1;
				cin >> move;
			}
			else
			{
				srand(time(0));
				move = rand() % 10;
				x1 = 2;
				if (check.find(move) != check.end() || move == 0)
				{
					goto label;
				}
			}
			if (check.find(move) != check.end() || move == 0)
			{
				cout << "\n--------------------------------------------------------------------------------------\n";
				cout << "Position Already occupied" << endl;
				cout << "\n--------------------------------------------------------------------------------------\n";
				goto label;
			}
			check.insert(move);
			switch (move)
			{
			case 1:
				x.board[0][0] = x1;
				break;
			case 2:
				x.board[0][1] = x1;
				break;
			case 3:
				x.board[0][2] = x1;
				break;
			case 4:
				x.board[1][0] = x1;
				break;
			case 5:
				x.board[1][1] = x1;
				break;
			case 6:
				x.board[1][2] = x1;
				break;
			case 7:
				x.board[2][0] = x1;
				break;
			case 8:
				x.board[2][1] = x1;
				break;
			case 9:
				x.board[2][2] = x1;
				break;
			}
			cout << "\nPlayer " << x1 << " choosed " << move << " position..\n";
			cout << "\n--------------------------------------------------------------------------------------\n";
			cout << "\nThe board after the move is :-\n\n\n";
			x.printBoard();
			cout << "\n====================================================================================\n";
			cout << "\n\n\n";
			if (x.check_result())
			{
				cout << "Player " << x1 << "WON\n";
				break;
			}
		}
		if (i == j)
		{
			cout << "The game TIES!!..\n";
		}
	}
	void two_players(game_4 &x)
	{
		int x1, move, i;
		unordered_set<int> check;
		for (i = 0; i < 16; i++)
		{
			if (i % 2 == 0)
				x1 = 1;
			else
				x1 = 2;
		label:
			cout << "\nEnter your move :- ";
			cin >> move;
			if (check.find(move) != check.end())
			{
				cout << "\n--------------------------------------------------------------------------------------\n";
				cout << "Position already occupied" << endl;
				cout << "\n--------------------------------------------------------------------------------------\n";
				goto label;
			}
			check.insert(move);
			switch (move)
			{
			case 1:
				x.board[0][0] = x1;
				break;
			case 2:
				x.board[0][1] = x1;
				break;
			case 3:
				x.board[0][2] = x1;
				break;
			case 4:
				x.board[0][3] = x1;
				break;
			case 5:
				x.board[1][0] = x1;
				break;
			case 6:
				x.board[1][1] = x1;
				break;
			case 7:
				x.board[1][2] = x1;
				break;
			case 8:
				x.board[1][3] = x1;
				break;
			case 9:
				x.board[2][0] = x1;
				break;
			case 10:
				x.board[2][1] = x1;
				break;
			case 11:
				x.board[2][2] = x1;
				break;
			case 12:
				x.board[2][3] = x1;
				break;
			case 13:
				x.board[3][0] = x1;
				break;
			case 14:
				x.board[3][1] = x1;
				break;
			case 15:
				x.board[3][2] = x1;
				break;
			case 16:
				x.board[3][3] = x1;
				break;
			}
			cout << "\nPlayer " << x1 << " choosed " << move << " position..\n";
			cout << "\n--------------------------------------------------------------------------------------\n";
			cout << "\nThe board after the move is :-\n\n";
			x.printBoard();
			cout << "\n====================================================================================\n";
			cout << "\n\n\n";
			if (x.check_result())
			{
				cout << "Player " << x1 << " WON\n";
				break;
			}
		}
		if (i == 16)
		{
			cout << "The game TIES!!..\n";
		}
	}
	void one_player(game_4 &x)
	{
		int x1;
		int move;
		unordered_set<int> check;
		int i, j;
		char c;
		cout << "Dare to go first ?(Y/N):- ";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			i = 0;
			j = 16;
		}
		else
		{
			i = 1;
			j = 17;
		}
		for (i; i < j; i++)
		{
		label:
			if (i % 2 == 0)
			{
				x1 = 1;
				cout << "\nEnter your move :- ";
				cin >> move;
			}
			else
			{
				srand(time(0));
				move = rand() % 16;
				x1 = 2;
				if (check.find(move) != check.end() || move == 0)
				{
					goto label;
				}
			}
			if (check.find(move) != check.end() || move == 0)
			{
				cout << "\n--------------------------------------------------------------------------------------\n";
				cout << "Position Already occupied" << endl;
				cout << "\n--------------------------------------------------------------------------------------\n";
				goto label;
			}
			check.insert(move);
			switch (move)
			{
			case 1:
				x.board[0][0] = x1;
				break;
			case 2:
				x.board[0][1] = x1;
				break;
			case 3:
				x.board[0][2] = x1;
				break;
			case 4:
				x.board[0][3] = x1;
				break;
			case 5:
				x.board[1][0] = x1;
				break;
			case 6:
				x.board[1][1] = x1;
				break;
			case 7:
				x.board[1][2] = x1;
				break;
			case 8:
				x.board[1][3] = x1;
				break;
			case 9:
				x.board[2][0] = x1;
				break;
			case 10:
				x.board[2][1] = x1;
				break;
			case 11:
				x.board[2][2] = x1;
				break;
			case 12:
				x.board[2][3] = x1;
				break;
			case 13:
				x.board[3][0] = x1;
				break;
			case 14:
				x.board[3][1] = x1;
				break;
			case 15:
				x.board[3][2] = x1;
				break;
			case 16:
				x.board[3][3] = x1;
				break;
			}
			cout << "\nPlayer " << x1 << " choosed " << move << " position..\n";
			cout << "\n--------------------------------------------------------------------------------------\n";
			cout << "\nThe board after the move is :-\n\n";
			x.printBoard();
			cout << "\n====================================================================================\n";
			cout << "\n\n\n";
			if (x.check_result())
			{
				cout << "Player " << x1 << "WON\n";
				break;
			}
		}
		if (i == j)
		{
			cout << "The game TIES!!..\n";
		}
	}
};

int main()
{
	int choice, c;
label:
	system("cls");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, 13);
	cout << "\t\t\t**************************************\n";
	cout << "\t\t\t\tTIC TAC TOE BOARD GAME\n";
	cout << "\t\t\t**************************************\n";
	SetConsoleTextAttribute(hConsole, 9);
	cout << "\nDare to play on 4x4 board or are you satisfied with 3x3 board?\n";
	cout << "\nEnter 1 for 3x3 board\nEnter 2 for 4x4 board\n";
	cout << "\nEnter the choice to hop on.. :- ";
	cin >> choice;
	if (choice == 1)
	{
		class game_3 ob1;
		class players ob2;
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\n\nDo you want to play 2 players game or play against computer ?" << endl;
		cout << "\nEnter 1 to start 2 players game..\n";
		cout << "\nEnter 2 to start playing against computer..\n";
		cout << "\nEnter the choice to let the fun begin: ";
		cin >> c;
		SetConsoleTextAttribute(hConsole, 9);
		if (c == 1)
		{
			ob2.two_players(ob1);
		}
		else
		{
			ob2.one_player(ob1);
		}
	}
	else if (choice == 2)
	{
		class game_4 ob3;
		class players ob4;
		cout << "\n\nDo you want to play 2 players game or play against computer ?" << endl;
		cout << "\nEnter 1 to start 2 players game..\n";
		cout << "\nEnter 2 to start playing against computer..\n";
		cout << "\nEnter the choice to let the fun begin: ";
		cin >> c;
		SetConsoleTextAttribute(hConsole, 9);
		if (c == 1)
		{
			ob4.two_players(ob3);
		}
		else
		{
			ob4.one_player(ob3);
		}
	}
	else
	{
		cout << "Wrong choice , my friend..\n\n";
		cout << "Enter the new choice..\n\n";
		goto label;
	}
	cout << "Want to Play again? (Y/N) : ";
	char ch;
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
		goto label;
	else
	{
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\n====================================================================================\n";
		cout << "\t\t\t\tGood Bye!!\n\t\t\t\tHave a nice day";
		cout << "\n====================================================================================\n";
	}
	return 0;
}