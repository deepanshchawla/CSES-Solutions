#include<iostream>

using namespace std;

enum cellTYpe
{
	NORMAL = 0,
	HURDLE = 1,
	SOURCE = 2,
	DESTINATION = 3
};
enum dir
{
	NONE = 0,
	NORTH = 1,
	EAST,
	SOUTH,
	WEST
};

static const int ROW = 10;
static const int COL = 10;

static const int T = ROW*COL;

struct point
{
	int row;
	int col;
};

static point source;

static point destination;


static int grid[ROW][COL];

int usergrid[ROW][COL];

static int moveCalls = 0;

int Travel(int usergrid[ROW][COL]);

void init()
{
	moveCalls = 0; 
	for (int a = 0; a < ROW; a++)
	{
		for (int b = 0; b < COL; b++)
		{
			if (usergrid[a][b] == SOURCE)
			{
				source.col = b;
				source.row = a;
			}
			else if (usergrid[a][b] == DESTINATION)
			{
				destination.col = b;
				destination.row = a;				
			}			
		}
	}

}

bool move(dir eDir)
{
	moveCalls++;

	point next=source;
	
	if (eDir == NORTH)
	{
		next.row = source.row - 1;
	}
	else if (eDir == SOUTH)
	{
		next.row = source.row + 1;
	}
	else if (eDir == EAST)
	{
		next.col = source.col + 1;
	}
	else if (eDir == WEST)
	{
		next.col = source.col - 1;
	}
	int r = next.row;
	int c = next.col;
	if (r >= 0 && r < ROW && c >= 0 && c < COL && grid[r][c] != HURDLE)
	{
		grid[source.row][source.col] = NORMAL;
		grid[next.row][next.col] = SOURCE;
		source.row = next.row;
		source.col = next.col;
		return true;
	}
	else
	{
		return false;
	}
}

void reset()
{
	moveCalls = 0;
}
int main()
{
	/*FILE* pF = 0;
	FILE* pFOut = 0;
	freopen_s(&pF,"MoveAlongInput.txt", "r",stdin);
	freopen_s(&pFOut, "MoveAlongOutput.txt", "w", stdout);*/
	int C = 0;	
	cin >> C;
	for (int c = 1; c <= C; c++)
	{
		int Score = 100;
		for (int a = 0; a < ROW; a++)
			for (int b = 0; b < COL; b++)
			{
				cin >> grid[a][b];
				usergrid[a][b] = grid[a][b];
			}

		init();

		int userMoveCalls = Travel(usergrid);		
		
		int expectedMoveCalls = 0; 
		
		
		//cout << userMoveCalls <<endl;		
		
		cin >> expectedMoveCalls;
		
		

		if (userMoveCalls != expectedMoveCalls)
			Score = Score - 50;
		
		
		if (expectedMoveCalls != 0 && grid[destination.row][destination.col] != SOURCE)
			Score = Score - 50;
		
		
		cout << Score << endl;
		
		reset();
	}
	return 0;
}
//#endif


int Travel(int usergrid[ROW][COL]){
	
}