void test(&number_1,&number_2){
	number_1 =300;
	number_2 =400;
	writeDebugStream("value of number_1 = %d and value of number_2 = %d", number_1,number_2);
	writeDebugStream("address of number_1 = %d and address of number_2 = %d", &number_1,&number_2);
}
task main()
{
	int number_1 =100;
	int number_2 =200;
	writeDebugStream("value of number_1 = %d and value of number_2 = %d", number_1,number_2);
	writeDebugStream("address of number_1 = %d and address of number_2 = %d", &number_1,&number_2);
	voidtest()
}

