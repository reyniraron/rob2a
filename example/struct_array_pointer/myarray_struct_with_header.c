#include <structpointer.h>
/*
this is an array of type struct Pos , it keeps pointers to the structs
*/
Mystruct my_array[10];
string my_string[7]={"the string","the string1","the string2","the string3","the string4","the string5","the string6"};
Mystruct *set_myarray(){
	for(int i =0;i<7;i++){
		int _x = rand()%10;
		int _y = rand()%10;
		my_array[i].length=_x;
		my_array[i].width=_y;
		my_array[i].mystring=my_string[i];
	}
	return &my_array;//retuns a pointer to the array
}
task main()
{
	Mystruct *pointer_to_myarray = set_myarray();//a pointer to the first dataset in array
	for(int j =0;j<7;j++){
		writeDebugStream("value of length is =%d \n",pointer_to_myarray->length);
		writeDebugStream("value of with is =%d \n",pointer_to_myarray->width);
		writeDebugStream("value of string is =%s \n",pointer_to_myarray->mystring);
		pointer_to_myarray++;	//make the pointer point to the next dataset value
		}
}
