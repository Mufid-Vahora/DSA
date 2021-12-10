#include<iostream>
#define max 5
using namespace std;

//structure

struct employee
{
   string name;
   long int id;
   string designation;
   int exp;
   int age;
};
int num;
void showMenu();
//Array of Employees to store the data in the form of the Structure of the Array.
employee emp[max], tempemp[max],sortemp[max],sortemp1[max];

// Function to build the given datatype
void new_structure()
{
	cout << "New Structure of employee \n";
	cout << "Maximum Entries can be "<< max << "\n";

	cout << "Enter the number of Entries required";
	cin >> num;

	if (num > 25) 
	{
		cout << "Maximum number of Entries are 25\n";
		num = 25;
	}
	cout << "Enter the following data:\n";

	for (int i = 0; i < num; i++) {
		cout << "Name ";
		cin >> emp[i].name;

		cout << "Employee ID ";
		cin >> emp[i].id;

		cout << "Designation ";
		cin >> emp[i].designation;

		cout << "Experience ";
		cin >> emp[i].exp;

		cout << "Age ";
		cin >> emp[i].age;
	}

	showMenu();
}

// Function to insert the data into given data type
void insert()
{
	if (num < max) 
    {
		int i = num;
		num++;

		cout << "Enter the information of the Employee\n";
		cout << "Name ";
		cin >> emp[i].name;

		cout << "Employee ID ";
		cin >> emp[i].id;

		cout << "Designation ";
		cin >> emp[i].designation;

		cout << "Experience ";
		cin >> emp[i].exp;

		cout << "Age ";
		cin >> emp[i].age;
	}
	else {
		cout << "Employee Table Full\n";
	}

	showMenu();
}
// Function to delete record at index i
void deleteIndex(int i)
{
	for (int j = i; j < num - 1; j++) 
    {
		emp[j].name = emp[j + 1].name;
		emp[j].id = emp[j + 1].id;
		emp[j].designation = emp[j + 1].designation;
		emp[j].exp = emp[j + 1].exp;
		emp[j].age = emp[j + 1].age;
	}
	return;
}
// Function to delete record
void deleteRecord()
{
	cout << "Enter the Employee ID "
		<< "to Delete Record";

	int id;
	cin >>id;
	for (int i = 0; i < num; i++) 
	{
		if (emp[i].id == id) 
		{
			deleteIndex(i);
			num--;
			break;
		}
	}
	showMenu();
}
void searchRecord()
{
	cout << "Enter the Employee ID to Search Record";

	int id;
	cin >> id;

	for (int i = 0; i < num; i++) 
    {

		// If the data is found
		if (emp[i].id == id) {
			cout << "Name "
				<< emp[i].name << "\n";

			cout << "Employee ID "
				<< emp[i].id << "\n";

			cout << "Designation "
				<< emp[i].designation << "\n";

			cout << "Experience "
				<< emp[i].exp << "\n";

			cout << "Age "
				<< emp[i].age << "\n";
			break;
		}
	}

	showMenu();
}
// Function to show menu
void showMenu()
{
	cout << "Availiable Options:\n";
	cout << "New structure  (1)\n";
	cout << "Insert New Entry (2)\n";
	cout << "Delete Entry	 (3)\n";
	cout << "Search a Record (4)\n";
	cout << "Exit		(5)\n";

	int option;

	// Input Options
	cin >> option;

	// Call function on the bases of the above option
	if (option == 1) 
    {
		new_structure();
	}
	
    else if (option == 2) 
    {
		insert();
	}
	else if (option == 3) 
    {
		deleteRecord();
	}
	else if (option == 4) 
    {
		searchRecord();
	}
	else if (option == 5) 
    {
		return;
	}
	else 
	{
		cout << "Expected Options"
			<< " are 1/2/3/4/5";
		showMenu();
	}
}

int main()
{

	showMenu();
	return 0;
}