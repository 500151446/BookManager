#include <iostream>
#include <conio.h>

using namespace std;


struct Book
{
	string title;
	string author;
	int yearPublished;
	int numPages;
};


void DisplayBook(Book book, int bookNum)
{
	cout << "\n" << bookNum << ". " << book.title << "\n";
	cout << "Author: " << book.author << "\n";
	cout << "Year Published: " << book.yearPublished << "\n";
	cout << "Number of Pages: " << book.numPages << "\n";
}

int main()
{
	//book array
	const int numBooks = 4;

	Book books[numBooks] =
	{
		{"Runemarks", "Joanne Harris", 0, 500},
		{"Eragon", "Christopher Paolini", 2002, 0},
		{"Harry Potter and the Philosopher's Stone", "Unknown", 1997, 223},
		{"The Eye of the World", "Robert Jordan", 1990, 0}
	};


	//display all books in array
	int bookNum = 1;

	for (Book book : books)
	{
		DisplayBook(book, bookNum);
		bookNum++;
	}

	//get id of book to change
	cout << "\nEnter the ID of the book you would like to update (1-" << numBooks << "): ";
	
	int id;
	cin >> id;
	//check if id is valid
	if (id > 4 || id < 1)
	{
		cout << "\nBook is not in the library";
	}
	else
	{
		
		Book &book = books[id - 1];
		Book newBook;

		cout << id << ". " << book.title << "\n";
		cout << "Enter the Author (" << book.author << "): ";
		cin >> newBook.author;
		cout << "\nEnter the Year Published (" << book.yearPublished << "): ";
		cin >> newBook.yearPublished;
		cout << "\nEnter the Number of Pages (" << book.numPages << "): ";
		cin >> newBook.numPages;

		cout << "\nDo you want to save these changes?  (Y/N): ";

		string response;
		cin >> response;

		if (response == "y" || response == "Y")
		{
			book = newBook;

			DisplayBook(book, id);
		}
		else
		{
			cout << "Changes not saved";
		}
	}
	return 1;

}







