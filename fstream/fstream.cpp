#include "stdafx.h"
#include <fstream>												//ofstream-write to file, ifstream-read from file
#include <string>
#include <iostream>

using namespace std;

int main()
{
	//WRITE TO FILE
	{
		ofstream of("abc.txt");									//create a new file if the file does not exists
		of << "Hello World!" << endl;

		ofstream of2("abc.txt", ofstream::app);					//move the output pointer to EOF for append
		of << "Hello World!" << endl;

		ofstream of3("abc.txt", ofstream::in | ofstream::out);  //want to write middle of file
		of.seekp(10, ios::beg);									//move output pointer to 10 chars after begin
		of << "Hello World!" << endl;
		of.seekp(-5, ios::end);									//move output pointer to 5 chars before end
		of << "Hello World!" << endl;
		of.seekp(-5, ios::cur);									//move output pointer to 5 chars before current

		if(of.is_open())
			of.close();
	}

	//READ TO FILE
	{
		ifstream inf;
		inf.open("read.txt");
		if (inf.fail()) {
			cerr << "Error Opening File" << endl;
			exit(EXIT_FAILURE);
		}

		int count = 0;
		string line;

		//METHOD1: untill reach EOF
		while (!inf.eof()) {
			inf >> line;
			count++;
			cout << line << count << endl;
		}
		
		//METHOD2: iterate untill there is line
		while (getline(inf, line)) {
			cout << line << endl;
		}
		if(inf.is_open())
			inf.close();
	}


	//IFSTREAM STATUS
	{
		ifstream inf("abc.txt");
		int i;
		inf >> i;												//read one word but it will fail since it's not int type

		inf.good();												//Everything is okay       (goodbit == 1)
		inf.bad();											    //Non-recoverable error    (badbit == 1)
		inf.fail();												//Failed stream operation  (failbit == 1; badbit == 1)
		inf.eof();												//End of file              (eofbit == 1 )
		inf.clear();											//Clear all status bits
		inf.clear(ios::badbit);									//Clear and set as badbit == 1
		inf.clear(inf.rdstate() & ~ios::failbit);				//Clear only the failbit

		if (inf) {												//if(!inf.fail())
			cout << "read sucessfully" << endl;
		}
		if (inf >> i) {
			cout << "read sucessfully" << endl;
		}
	}


	string n;
	cin >> n;
	return 0;
}

