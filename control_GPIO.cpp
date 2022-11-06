//HW9
//This program sets a pin high or low based on user input and read the pushbutton
//this program takes three command , gpio # either input or output and hi or low
//ex ./control_GPIOC 60 hi 46 or 60 low 46/ this sets pin60 to either low or high which is the led and read the input of 46 which is push button

#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

//path of the gpio to write and read from the files
#define PATH "/sys/class/gpio"	// Define path to gpio directory

int main(int argc, char* argv[])
{
	// same thing copied to make sure they are enough arguments otherwise show how to use the code
	if(argc != 4)
	{
		cout << "To use is: control_GPIO , gpio_number,  state , gpio_number" << endl;
		cout << "gpio_number: GPIO number to control ex. 60 and 46" << endl;
		cout << "state: hi or low , for LED" << endl;
		return 2;
	}

	//ro read the inputs , 1 is 60 is led int , 2 is hi/low , 3 is 46 button int
	int gpio1 = atoi(argv[1]);
	string state(argv[2]);
	int gpio2 = atoi(argv[3]);
	
	//string value for hi or low
	string out;
    if(state == "hi")
    {
        out = "1";
    }
    else if(state == "low")
    {
        out = "0";
    }
    
	//copied from hw and string cpp .c
    ostringstream s1;
	s1 << PATH << "/gpio" << gpio1 << "/value"; //cat to number
	string filePath1 = string(s1.str()); //turns stream to string

	ostringstream s2;
	s2 << PATH << "/gpio" << gpio2 << "/value";
	string filePath2 = string(s2.str());
	
	
	cout << "Path1: " << filePath1 << endl;
	cout << "Path2: " << filePath2 << endl;
	
	
	//opening the gpio60 led to write hi or low
	cout << "ChangingGPIO60 to: " << gpio1 << " state to " << state << endl; // using state as 1 or 0ofstream fs1;
	//this opens and writes to it and closes it like a cabinet
	ofstream fs1;
	fs1.open(filePath1.c_str());
	fs1 << out;
	fs1.close();
	
	//reading the input of gpio46 the button whether its pressed or not and closing it
	cout << "GPIO46 Button is: " << gpio2 << endl;
	ifstream fs2;
	fs2.open(filePath2.c_str());
	string in;//makes a new value call in and prints it and if not it prints out as in not pressed or pressed
	getline(fs2,in);
    fs2.close();
    cout << endl << "GPIO46 is: " << gpio2 << " is " << in << "." << endl;
 
}
    
