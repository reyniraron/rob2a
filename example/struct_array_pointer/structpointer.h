/*
All constants should be difined in the headerfile
*/
#define COL 6
#define ROW 5

typedef struct Cords{
	int row;
	int col;
	bool tf;
}Cords;
/*
This is an struct for positioning X;Y,Z
good for using an array with structs in stead of 2d array you can use
single dimention array.
defining a struct is done in the header file.
*/
typedef struct Pos{
	int x;
	int y;
	int z;
}Pos;

typedef struct Mystruct{
	int length;
	int with;
	string mystring;
}Mystruct;
