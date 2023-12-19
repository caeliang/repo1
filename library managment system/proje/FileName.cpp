#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;
//global

string user, pass;
fstream admins;
fstream students;
fstream list;
fstream temp;
fstream borrowlist;
fstream requestlist;
//functions
bool checkpassuserstudent(string user1, string pass1);
bool checkpassuseradmin(string user1, string pass1);
void signupadmin();
void signinadmin();
void signupstudent();
void signinstudent();
void addbook();
void deletebook();
void booklist();
void donatlist();
void Borrowlist();
void borrowbook();
void Requestlist();
void returnbook();
void donatebook();
void searchid();
void searchtitle();
void searchauthor();
bool checkbookid(int id);
void information();
void checkstudentid(int studentid, int bookid);
bool operation();
bool operation1();
bool enter();
bool checkbooktitle(string title);
bool checkbookauthor(string author);
//structerts
struct adminaddbook
{
	int bookid;
	string title;
	string auhtor;
	string date;
	string borrow;


}add;
struct borrow
{
	string namestudent;
	int studentid;
	string titleofbook;
	int bookid1;
	string dateborrow;
	string Return;
}borrowstudent;
struct donate
{
	int bookid;
	string title;
	string auhtor;
	string date;
}donatestudent;

int main()
{

	cout << endl << endl;
	cout << "\t\t\t     ======================================\n";
	cout << "\t\t\t    ||                                    ||\n";
	cout << "\t\t\t    ||       Welcome To The Library       ||\n";
	cout << "\t\t\t    ||                                    ||\n";
	cout << "\t\t\t     ======================================\n";
	cout << endl << endl;
	cout << "\t\t\t     --------------------------------------\n";

	enter();



}
bool enter()
{

	int statue;
	int in, in1;
	cout << endl << "\t\t\t    1.admin";
	cout << endl << "\t\t\t    2.student";
	cout << endl << "\t\t\t    enrter your statue:";
	cin >> statue;
	cout << "\t\t\t     --------------------------------------\n";
	//statue = 1;
	if (statue == 1)
	{

		cout << "\t\t\t    1.sign in" << endl;
		cout << "\t\t\t    2.sign up" << endl;
		cout << "\t\t\t    3.back" << endl;

		cout << "\t\t\t    enter your choise: ";
		cin >> in;
		if (in == 1)
			signinadmin();

		else if (in == 2)
			signupadmin();

		else if (in == 3)
			return enter();
		else
		{
			cout << "\n\t\t\t     invaild input";
			return enter();
		}
		operation();

	}

	else if (statue == 2)
	{

		cout << "\t\t\t    1.sign in" << endl;
		cout << "\t\t\t    2.sign up" << endl;
		cout << "\t\t\t    3.back" << endl;
		cout << "\t\t\t    enter your choise: ";
		cin >> in;
		if (in == 1)
			signinstudent();

		else if (in == 2)
			signupstudent();
		else if (in == 3)
			enter();
		else
		{
			cout << "invaild input";
			enter();
		}
		operation1();

	}
	else if (statue == 3)
	{
		enter();
	}
	else
	{
		cout << "invaild input";
		enter();
	}
}
void signupadmin()
{

	cout << "\n\t\t\t     ------------ Admin Sign Up ------------" << endl;
	string user, pass;
	cout << endl << endl;

	cout << "\t\t\t     please set your username: ";
	cin.ignore();
	getline(cin, user);
	cout << "\t\t\t     please set your password: ";
	getline(cin, pass);


	ofstream admins("admin.txt", ios::app);
	if (admins.is_open())
	{
		admins << user << setw(15) << pass << endl;
		admins.close();
		cout << "\n\t\t\t     Signup Successful" << endl;
		system("CLS");
		cout << "\t\t\t     ----------- Welcome " << user << " -----------" << endl;
	}
	else
	{
		cout << "\n     Error: File Not Open" << endl;
	}


}
void signinadmin()
{

	string useradmin1, passadmin1;
	cout << "\n\t\t\t     ------------ Admin Login ------------" << endl;
	cout << endl << endl;
	cout << "\t\t\t     please enter your username: ";
	cin.ignore();
	getline(cin, useradmin1);
	cout << "\t\t\t     please enter your password: ";
	getline(cin, passadmin1);


	do
	{
		if (checkpassuseradmin(useradmin1, passadmin1))
		{
			cout << "\n\t\t\t     Login sucessful!" << endl;
			system("CLS");
			cout << "\t\t\t     ----------- Welcome " << useradmin1 << " -----------" << endl;
			cout << endl;

		}
		else
		{
			cout << "\nInvalid username or password. " << endl;
			signinadmin();
		}

	} while (checkpassuseradmin(useradmin1, passadmin1) != true);

}
void signupstudent()
{

	cout << "\n\t\t\t     ------------ Student Sign Sp ------------" << endl;
	string user, pass;
	cout << endl << endl;
	cout << "\t\t\t     please set your username: ";
	cin.ignore();
	getline(cin, user);
	cout << "\t\t\t     please set your password: ";
	getline(cin, pass);

	ofstream students("student.txt", ios::app);
	if (students.is_open())
	{
		students << user << setw(15) << pass << endl;
		students.close();
		cout << "\n\t\t\t     Signup Successful" << endl;
		system("CLS");
		cout << "\t\t\t     ----------- Welcome " << user << " -----------" << endl;
	}
	else
	{
		cout << "\n     Error: File Not Open" << endl;
	}
}
void signinstudent()
{

	cout << "\n\t\t\t     ------------ Student Login ------------" << endl;

	string userstudent1, passstudent1;
	cout << endl << endl;
	cout << "\t\t\t     please enter your username: ";
	cin.ignore();
	getline(cin, userstudent1);
	cout << "\t\t\t     please enter your password: ";
	getline(cin, passstudent1);
	do
	{
		if (checkpassuserstudent(userstudent1, passstudent1))
		{
			cout << "\n\t\t\t     Login sucessful!" << endl;
			system("CLS");
			cout << "\t\t\t     ----------- Welcome " << userstudent1 << " -----------" << endl;
			cout << endl;

		}
		else

		{
			cout << "\nInvalid username or password. " << endl;
			signinstudent();
		}
	} while (checkpassuserstudent(userstudent1, passstudent1) != true);



}
void addbook()
{
	system("CLS");
	cout << "\t\t\t     --------------- Add Book ---------------\n" << endl;

	cout << "\t\t\t     enter book id: ";
	cin >> add.bookid;
	while (checkbookid(add.bookid))
	{
		cout << "\t\t\t     this id is already exist!" << endl;
		cout << "\t\t\t     enter book id: ";
		cin >> add.bookid;
	}

	cin.ignore();
	cout << "\t\t\t     enter book title: ";
	getline(cin, add.title);

	cout << "\t\t\t     enter book author: ";
	getline(cin, add.auhtor);

	cout << "\t\t\t     enter publication date of the book: ";
	getline(cin, add.date);


	fstream list("list.txt", ios::app);
	if (list.is_open())
	{
		list << "ID:" << setw(15) << left << add.bookid << "Title:" << setw(40) << left << add.title << "Author:" << setw(25) << left << add.auhtor << "Publication Date:" << setw(15) << left << add.date << endl;
		list.close();
		cout << "\n\t\t\t     information saved successfully" << endl;
	}
	else
	{
		cout << "\n     Error: File Not Open" << endl;
	}


}
void booklist()
{
	system("CLS");
	cout << "\t\t\t     ---------------Book list---------------\n" << endl;
	string line;
	fstream list("list.txt", ios::in);
	if (list.is_open())
	{
		while (getline(list, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "\n     Error: File Not Open" << endl;
	}
	list.close();

}
void borrowbook()
{
	system("CLS");

	cout << "\t\t\t     ---------------borrow Book---------------\n" << endl;
	cin.ignore();
	cout << "\t\t\t     enter student full name: ";
	getline(cin, borrowstudent.namestudent);

	cout << "\t\t\t     enter student id: ";
	cin >> borrowstudent.studentid;
	cin.ignore();

	int choice;
	cout << "\t\t\t     1.book list" << endl;
	cout << "\t\t\t     2.search" << endl;
	cout << "\t\t\t     enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		booklist();
		break;
	case 2:

	{
		int in1;
		system("CLS");
		cout << "\t\t\t     --------------- search book ---------------\n" << endl;
		cout << "\t\t\t    1.search book by id" << endl;
		cout << "\t\t\t    2.search book by title" << endl;
		cout << "\t\t\t    3.search book by author" << endl;
		cout << "\t\t\t    enter your choise: ";
		cin >> in1;
		if (in1 == 1)
			searchid();
		else if (in1 == 2)
			searchtitle();
		else if (in1 == 3)
			searchauthor();
		else
			cout << "\t\t\t     invaild input" << endl;
	}
	break;
	default:
		cout << "invaild input" << endl;
		break;
	}

	cout << "\t\t\t     enter the id of the book you want to borrow: ";
	cin >> borrowstudent.bookid1;
	cin.ignore();

	cout << "\t\t\t     enter date of borrow: ";
	getline(cin, borrowstudent.dateborrow);

	cout << "\t\t\t     enter the expected return date: ";
	getline(cin, borrowstudent.Return);

	fstream requestlist("requestlist.txt", ios::app);
	if (requestlist.is_open())
	{

		if (checkbookid(borrowstudent.bookid1))
		{
			requestlist << "Book ID:" << borrowstudent.bookid1 << setw(15) << "Student Name:" << borrowstudent.namestudent << setw(15) << "Student ID:" << borrowstudent.studentid << setw(15) << "Borrow Date:" << borrowstudent.dateborrow << setw(15) << "Expected Return Date:" << borrowstudent.Return << endl;

			cout << "\t\t\t     your borrow request saved successfully" << endl;
		}
		else
			cout << "\t\t\t     invalid book id" << endl;
	}
	else
		cout << "\n     Error: File Not Open" << endl;

	requestlist.close();

}
void Borrowlist()
{
	system("CLS");
	cout << "\t\t\t     ---------------Borrow list---------------\n" << endl;
	string line;
	fstream borrowlist("borrowlist.txt", ios::in);
	if (borrowlist.is_open())
	{
		while (getline(borrowlist, line))
		{
			cout << "\t\t\t     " << line << endl;
		}
	}
	else
	{
		cout << "\n     Error: File Not Open" << endl;
	}
	borrowlist.close();

}
void returnbook()
{
	system("CLS");
	borrow borrowstudent;
	int studentid;
	cout << "\t\t\t     --------------- Return Book ---------------\n" << endl;
	cout << "\t\t\t     Enter student ID: ";
	cin >> borrowstudent.studentid;
	cout << "\t\t\t     Enter book ID: ";
	cin >> borrowstudent.bookid1;
	cin.ignore();
	cout << "\t\t\t     Enter returned date: ";
	cin >> borrowstudent.Return;


	if (!(checkbookid(borrowstudent.bookid1)))
	{

		fstream temp5("temp5.txt", ios::app);
		fstream list("list.txt", ios::app);
		if (list.is_open() && temp5.is_open())
		{
			string line;
			while (getline(temp5, line));
			{
				if ((line.find("ID:" + to_string(borrowstudent.bookid1))) != string::npos)
				{
					list << line << endl;
				}
			}

			list.close();
			temp5.close();
			cout << "\n\t\t\t     information saved successfully" << endl;
		}
		else
			cout << "\n     Error: File Not Open" << endl;


		ofstream temp2("temp2.txt");
		fstream borrowlist("borrowlist.txt", ios::app);
		bool found = false;
		if (borrowlist.is_open())
		{
			string line;
			while (getline(borrowlist, line))
			{
				if ((line.find("Student ID:" + to_string(borrowstudent.studentid))) != string::npos)
				{
					found = true;
					continue;
				}
				temp2 << line << endl;
			}
			borrowlist.close();
			temp2.close();
		}

		if (found)
		{
			remove("borrowlist.txt");
			rename("temp2.txt", "borrowlist.txt");
			cout << "\t\t\t     book has been returned successfully." << endl;
		}
		else
		{
			remove("temp2.txt");
			cout << "\t\t\t     book does not exist." << endl;
		}

	}


}
void deletebook()
{
	system("CLS");
	int id;


	cout << "\t\t\t     ---------------Delete Book---------------\n" << endl;
	cout << "\t\t\t     1.Delete book " << endl;
	cout << "\t\t\t     2.back " << endl;
	cout << "\t\t\t     Enter your choice: ";
	cin >> id;
	if (id == 1)
	{
		cout << "\t\t\t     Enter the ID of book to delete: ";
		cin >> id;
		ifstream list("list.txt");
		ofstream temp("temp.txt");

		bool found = false;
		string line;
		while (getline(list, line))
		{
			if (line.find("ID:" + to_string(id)) != string::npos)
			{
				found = true;
				continue;
			}
			temp << line << endl;
		}

		list.close();
		temp.close();

		if (found)
		{
			remove("list.txt");
			rename("temp.txt", "list.txt");
			cout << "\t\t\t     Book with ID " << id << " has been deleted successfully." << endl;
		}
		else
		{
			remove("temp.txt");
			cout << "\t\t\t     Book with ID " << id << " does not exist." << endl;
		}
	}
	else if (id == 2)
		operation;
	else
	{
		cout << "\t\t\t     invaild input ";
		deletebook();
	}


}
void searchid()
{
	system("CLS");
	int id;
	cout << "\t\t\t     ------------- Search Book by ID -------------\n" << endl;
	cout << "\t\t\t     Enter Book ID: ";
	cin >> id;
	if (checkbookid(id))
	{
		cout << "\t\t\t     Book found!" << endl;
		ifstream list("list.txt");
		if (list.is_open())
		{
			string line;
			while (getline(list, line))
			{
				if (line.find("ID:" + to_string(id)) != string::npos)
				{
					cout << "\t\t\t     " << line << endl;
					break;
				}
			}
			list.close();
		}
		else
			cout << "\t\t\t     Unable to open file!" << endl;
	}
	else
		cout << "\t\t\t     Book not found!" << endl;
}
void searchtitle()
{
	system("CLS");
	string Title;
	cout << "\t\t\t     ------------- Search Book by Title -------------\n" << endl;
	cout << "\t\t\t     Enter the title: ";
	cin.ignore();
	getline(cin, Title);

	if (checkbooktitle(Title))
	{
		cout << "\t\t\t     Book found!" << endl;
		ifstream list("list.txt");
		if (list.is_open())
		{
			string line;
			while (getline(list, line))
			{
				if (line.find("Title:" + (Title)) != string::npos)
				{
					cout << "\t\t\t     " << line << endl;
					break;
				}
			}
			list.close();
		}
		else
			cout << "\t\t\t     Unable to open file!" << endl;
	}
	else
		cout << "\t\t\t     Book not found!" << endl;
}
void searchauthor()
{
	system("CLS");
	string author;
	cout << "\t\t\t     ------------- Search Book by Author -------------\n" << endl;
	cout << "\t\t\t     Enter author name: ";
	cin.ignore();
	getline(cin, author);
	if (checkbookauthor(author))
	{
		cout << "\t\t\t     Book found!" << endl;
		ifstream list("list.txt");
		if (list.is_open())
		{
			string line;
			while (getline(list, line))
			{
				if (line.find("Author:" + (author)) != string::npos)
				{
					cout << "\t\t\t     " << line << endl;
				}
			}
			list.close();
		}
		else
			cout << "\t\t\t     Unable to open file!" << endl;
	}
	else
		cout << "\t\t\t     Book not found!" << endl;
}
void donatlist()
{
	system("CLS");
	cout << "\t\t\t     ------------- Donate List -------------\n" << endl;
	string line;
	fstream donatelist("donatelist.txt", ios::in);
	if (donatelist.is_open())
	{
		while (getline(donatelist, line))
		{
			cout << "\t\t\t     " << line << endl;
		}
	}
	else
	{
		cout << "\n\t\t\t     Error: File Not Open" << endl;
	}
	donatelist.close();

	int bookid;

	cout << "\t\t\t     To add book, " << endl;
	cout << "\t\t\t     Enter the id of book: ";
	cin >> bookid;
	if (checkbookid(bookid))
		cout << "This book is already exist";
	else
	{
		ifstream donatelist("donatelist.txt");
		ofstream list("list.txt");
		ofstream temp2("temp2.txt");
		bool found = false;
		string line;
		while (getline(donatelist, line))
		{
			if ((line.find("ID:" + to_string(bookid)) != string::npos))
			{
				list << line << endl;
				found = true;
				continue;
			}
			temp2 << line << endl;

		}

		donatelist.close();
		list.close();

		if (found)
		{
			remove("donatelist.txt");
			rename("temp2.txt", "donatelist.txt");
			cout << "\t\t\t     Book with ID " << bookid << " has been added successfully." << endl;
		}
		else
		{
			remove("temp2.txt");
			cout << "\t\t\t     Book with ID " << bookid << " does not exist." << endl;
		}
	}
}
void donatebook()
{
	system("CLS");
	cout << "\t\t\t     ---------------Donte Book---------------\n" << endl;
	cout << "\t\t\t     Enter book ID: ";
	cin >> donatestudent.bookid;
	cin.ignore();

	cout << "\t\t\t     Enter book title: ";
	getline(cin, donatestudent.title);

	cout << "\t\t\t     Enter book author: ";
	getline(cin, donatestudent.auhtor);

	cout << "\t\t\t     Enter publish date of the book: ";
	getline(cin, donatestudent.date);

	fstream donatelist("donatelist.txt", ios::app);
	if (donatelist.is_open())
	{
		donatelist << "ID:" << setw(15) << left << donatestudent.bookid << "Title:" << setw(40) << left << donatestudent.title << "Author:" << setw(25) << left << donatestudent.auhtor << "Publication Date:" << setw(15) << left << donatestudent.date << endl;
		donatelist.close();
		cout << "\n\t\t\t     information saved successfully" << endl;
	}
	else
		cout << "\n     Error: File Not Open" << endl;

}
void Requestlist()
{
	system("CLS");
	cout << "\t\t\t     ------------- Request List -------------\n" << endl;
	string line;
	ifstream requestlist("requestlist.txt");
	if (requestlist.is_open())
	{
		while (getline(requestlist, line))
			cout << "\t\t\t     " << line << endl;

		requestlist.close();
	}
	else
	{
		cout << "\n\t\t\t     Error: File Not Open" << endl;
	}


	int studentid;
	int bookid;

	cout << "\t\t\t     To lend book, " << endl;
	cout << "\t\t\t     Enter the ID of student: ";
	cin >> studentid;
	cout << "\t\t\t     Enter the ID of book: ";
	cin >> bookid;
	checkstudentid(studentid, bookid);
	cout << "\t\t\t     Book lended successfull";
}
void information()
{
	system("CLS");
	int id;
	cout << "\t\t\t     ------------- Edit Book Information -------------\n" << endl;
	cout << "\t\t\t     Enter the ID of book to edit: ";
	cin >> id;
	if (!checkbookid(id))
	{
		cout << "\t\t\t     There no ID matched!";
	}
	
	fstream list("list.txt", ios::app);
	if (!list.is_open())
		cout << "\n\t\t\t     Error: File Not Open" << endl;
	else 
	{
		string line;
		while (getline(list, line))
		{
			if (line.find("ID:" + to_string(id)) != string::npos)
			{
				cout << "\t\t\t     enter book id: ";
				cin >> add.bookid;
				while (checkbookid(add.bookid))
				{
					cout << "\t\t\t     this id is already exist!" << endl;
					cout << "\t\t\t     enter book id: ";
					cin >> add.bookid;
				}

				cin.ignore();
				cout << "\t\t\t     enter book title: ";
				getline(cin, add.title);

				cout << "\t\t\t     enter book author: ";
				getline(cin, add.auhtor);

				cout << "\t\t\t     enter publication date of the book: ";
				getline(cin, add.date);

				if (list.is_open())
				{
					list << "ID:" << setw(15) << left << add.bookid << "Title:" << setw(40) << left << add.title << "Author:" << setw(25) << left << add.auhtor << "Publication Date:" << setw(15) << left << add.date << endl;
					list.close();
					cout << "\n\t\t\t     information saved successfully" << endl;
				}
				else
				{
					cout << "\n     Error: File Not Open" << endl;
				}
			}

		}
		list.close();
	}
	


}

/////////////////////////// CHECK /////////////////////////////////////////////////////////////////////////////
bool checkpassuserstudent(string user1, string pass1)
{
	bool flag = false;
	ifstream students;
	students.open("student.txt");
	if (students.is_open())
	{
		for (user, pass; !flag && (students >> user >> pass); )
			flag = user == user1 && pass == pass1;

	}
	else
		cout << "Unable to open file!\n";
	return flag;
}
bool checkpassuseradmin(string user1, string pass1)
{
	bool flag = false;
	ifstream admins;
	admins.open("admin.txt");
	if (admins.is_open())
	{
		for (user, pass; !flag && (admins >> user >> pass); )
			flag = user == user1 && pass == pass1;

	}
	else
		cout << "Unable to open file!\n";
	return flag;
}
bool checkbookid(int id)
{
	ifstream list("list.txt");
	if (list.is_open())
	{
		string line;
		while (getline(list, line))
		{
			if (line.find("ID:" + to_string(id)) != string::npos)
			{
				list.close();
				return true;
			}
		}
		list.close();
	}
	else
		cout << "\t\t\t     Error: File not open!";
	return false;
}
void checkstudentid(int studentid, int bookid)
{
	ofstream temp("temp.txt");
	ifstream requestlist("requestlist.txt");
	fstream borrowlist("borrowlist.txt", ios::app);
	bool found = false;

	if (requestlist.is_open() && borrowlist.is_open() && temp.is_open())
	{
		string line;
		while (getline(requestlist, line))
		{
			if (line.find("Student ID:" + to_string(studentid)) != string::npos)
			{
				found = true;
				borrowlist << line << endl;
				cout << "\t\t\t     Book has been borrowed successfully." << endl;
			}
			else
			{
				temp << line << endl;
			}
		}
		requestlist.close();
		borrowlist.close();
	}
	else
	{
		cout << "\n\t\t\t     Error: Failed to open requestlist.txt" << endl;
		return;
	}

	temp.close();

	if (found)
	{
		remove("requestlist.txt");
		rename("temp.txt", "requestlist.txt");
	}
	else
	{
		remove("temp.txt");
		cout << "\t\t\t     Book not found or student ID does not match." << endl;
	}

	found = false;

	ofstream temp2("temp2.txt");
	ofstream temp5("temp5.txt");
	ifstream list("list.txt");

	if (list.is_open() && temp2.is_open() && temp5.is_open())
	{
		string line;
		while (getline(list, line))
		{
			if (line.find("ID:" + to_string(bookid)) != string::npos)
			{
				found = true;
				temp5 << line;
				cout << "\t\t\t     Book with ID " << bookid << " has been deleted successfully." << endl;
				continue;
			}
			else
				temp2 << line << endl;

		}
		list.close();
	}
	else
	{
		cout << "\n\t\t\t     Error: Failed to open list.txt" << endl;
		return;
	}

	temp2.close();
	temp5.close();

	if (found)
	{
		remove("list.txt");
		rename("temp2.txt", "list.txt");
	}
	else
	{
		remove("temp2.txt");
		cout << "\t\t\t     Book with ID " << bookid << " does not exist." << endl;
	}

	//system("CLS");
}
bool checkbooktitle(string title)
{
	ifstream list("list.txt");
	if (list.is_open())
	{
		string line;
		while (getline(list, line))
		{
			if (line.find("Title:" + title) != string::npos)
			{
				list.close();
				return true;
			}
		}
		list.close();
	}
	return false;
}
bool checkbookauthor(string author)
{
	ifstream list("list.txt");
	if (list.is_open())
	{
		string line;
		while (getline(list, line))
		{
			if (line.find("Author:" + author) != string::npos)
			{
				list.close();
				return true;
			}
		}
		list.close();
	}
	return false;


}////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool operation()
{
	int in;

	cout << "\n\n\t\t\t     --------------- Operations ---------------\n" << endl;
	cout << "\t\t\t    1.add book" << endl;
	cout << "\t\t\t    2.view book list" << endl;
	cout << "\t\t\t    3.search book" << endl;
	cout << "\t\t\t    4.edit book information" << endl;
	cout << "\t\t\t    5.request list" << endl;
	cout << "\t\t\t    6.doante list" << endl;
	cout << "\t\t\t    7.borrow list" << endl;
	cout << "\t\t\t    8.delete book" << endl;
	cout << "\t\t\t    9.Back" << endl;
	cout << "\t\t\t    10.exit" << endl;
	cout << "\t\t\t    enter your choise: ";
	cin >> in;


	switch (in)
	{
	case 1:
		addbook();
		break;
	case 2:
		booklist();
		break;
	case 3:

	{
		int in1;
		cout << "\t\t\t     --------------- Search Book ---------------\n" << endl;
		cout << "\t\t\t    1.Search book by ID" << endl;
		cout << "\t\t\t    2.Search book by title" << endl;
		cout << "\t\t\t    3.Search book by author" << endl;
		cout << "\t\t\t    enter your choise: ";
		cin >> in1;
		if (in1 == 1)
			searchid();
		else if (in1 == 2)
			searchtitle();
		else if (in1 == 3)
			searchauthor();
		else
			cout << "invaild input!";
	}
	break;
	case 4:
		information();
		break;
	case 5:
		Requestlist();
		break;
	case 6:
		donatlist();
		break;
	case 7:
		Borrowlist();
		break;
	case 8:
		deletebook();
		break;
	case 9:
		system("CLS");
		enter();
		break;
	case 10:
		exit(0);
		break;
	default:
	{
		cout << "\t\t\t     invaild input!";
		operation();
	}
	break;

	}
	operation();


}
bool operation1()
{
	int in;
	cout << "\n\n\t\t\t     -------------- Operations --------------\n" << endl;
	cout << "\t\t\t    1.View book list" << endl;
	cout << "\t\t\t    2.Search book" << endl;
	cout << "\t\t\t    3.Borrow book" << endl;
	cout << "\t\t\t    4.Return book" << endl;
	cout << "\t\t\t    5.Donate a book" << endl;
	cout << "\t\t\t    6.Back" << endl;
	cout << "\t\t\t    7.Exit" << endl;

	cout << "\t\t\t    Enter your choise: ";
	cin >> in;

	switch (in)
	{
	case 1:
		booklist();
		break;
	case 2:
	{
		int in1;
		cout << "\t\t\t     --------------- Search Book ---------------\n" << endl;
		cout << "\t\t\t    1.Search Book by ID" << endl;
		cout << "\t\t\t    2.Search Book by Title" << endl;
		cout << "\t\t\t    3.Search Book by Author" << endl;
		cout << "\t\t\t    4.Back" << endl;
		cout << "\t\t\t    Enter your choise: ";
		cin >> in1;
		if (in1 == 1)
			searchid();
		else if (in1 == 2)
			searchtitle();
		else if (in1 == 3)
			searchauthor();
		else if (in1 == 4)
			operation();
		else
			cout << "invaild input!";
	}
	break;
	case 3:
		borrowbook();
		break;
	case 4:
		returnbook();
		break;
	case 5:
		donatebook();
		break;
	case 6:
		system("CLS");
		enter();
		break;
	case 7:
		exit(0);
		break;
	default:
	{
		cout << "\t\t\t     invaild input!";
		return operation1();
	}
	break;
	}
	return operation1();

}