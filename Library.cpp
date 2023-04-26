#include <iostream>
#include <string>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS


#include <time.h>      
#include <locale.h>

using namespace std;

time_t now = time(0);
tm* ltm = localtime(&now);



struct Book
{
private:
	int pages;
public:
	string name;
	string author;
	string genre;
	int ID;
	bool availability = true;

	int set_pages(int pages_arg)
	{
		if (pages_arg > 0)
		{
			pages = pages_arg;
			return pages;
		}
		else
		{
			return 0;
		}
	}
	int get_pages()
	{
		return pages;
	}

	void ShowBookInfo()
	{
		cout << "ID - " << ID << endl;
		cout << "Name - " << name << endl;
		cout << "Writer - " << author << endl;
		cout << "Genre - " << genre << endl;
		cout << "Pages - " << get_pages() << endl;
		cout << "Available - " << boolalpha << availability << endl;
	}
};

struct Membership
{

	int ID;
	int sign_date[3];
	string membership_type;
	int membership_duration;
	int expiration_date[3];
	int payment;
	void showInfoMembership()
	{
		cout << "Membership ID - " << ID << endl;
		cout << "Sign date - " << sign_date[0] << "/" << sign_date[1] << "/" << sign_date[2] << endl;
		cout << "Membership type - " << membership_type << endl;
		cout << "Membership expiration date - " << expiration_date[0] << "/" << expiration_date[1] << "/" << expiration_date[2] << endl;
		cout << "Payment - " << payment << endl;
	}
};


struct Agreement
{
	int id=0;
	int sign_date[3] = { ltm->tm_mday,1 + ltm->tm_mon, 1900 + ltm->tm_year };
	int expiration_date[3] = { ltm->tm_mday, 2 + ltm->tm_mon, 1900 + ltm->tm_year };
	Book book_obj;

	void showAgreement()
	{
		cout << "ID - " << id << endl;
		cout << "Sign date: " << sign_date[0] << '/' << sign_date[1] << '/' << sign_date[2] << endl;
		cout << "Expiration date: " << expiration_date[0] << '/' << expiration_date[1] << '/' << expiration_date[2] << endl;
		book_obj.ShowBookInfo();
	}

};

struct Person
{

	int ID;
	string name;
	string surname;
	string birth_date;
	int passport_id_number;
	Membership membership_obj;
	int size_agreement=0;
	bool membership = false;
	bool agreement = false;
	Agreement* arr_aggrements = new Agreement[size_agreement];


	void showPersonInfo()
	{
		cout << "ID - " << ID << endl;
		cout << "Name - " << name << endl;
		cout << "Surname - " << surname << endl;
		cout << "Birth date - " << birth_date << endl;
		cout << "Passport ID number - " << passport_id_number << endl;
		cout << "Membership status: - " << boolalpha << membership << endl;
	}

	void add_membership(Membership*& arr_memberships, int& size, int& id, string membership_type, int duration, int payment)
	{

		Membership* membership_array = new Membership[size + 1];
		for (int i = 0; i < size; i++)
		{
			membership_array[i] = arr_memberships[i];
		}
		Membership temp_var = { id, {ltm->tm_mday,1 + ltm->tm_mon, 1900 + ltm->tm_year} , membership_type,   duration, { ltm->tm_mday, 1 + duration + ltm->tm_mon, 1900 + ltm->tm_year }, payment };
		membership_array[size] = temp_var;
		if (membership_array[size].expiration_date[1] > 12)
		{
			cout << "Before change - " << membership_array[size].expiration_date[2] << endl;
			membership_array[size].expiration_date[1] %= 12;
			membership_array[size].expiration_date[2]++;
			cout << "After change - " << membership_array[size].expiration_date[2] << endl;
		}
		size++;
		delete[] arr_memberships;
		arr_memberships = membership_array;
		id++;
	}

	void add_agreement(Book& obj, int& id)
	{
		Agreement* newArrAgreements = new Agreement[size_agreement + 1];
		for (int i = 0; i < size_agreement; i++)
		{
			newArrAgreements[i] = arr_aggrements[i];
		}
		newArrAgreements[size_agreement].id = id;
		newArrAgreements[size_agreement].book_obj = obj;
		obj.availability = false;
		size_agreement++;
		delete[] arr_aggrements;
		arr_aggrements = newArrAgreements;
		id++;
	}
};




void add_person(Person*& arr_persons, int& size, int& id, string name, string surname, string birth_date, int passport_id_number)
{
	Person* newArrPersons = new Person[size + 1];
	Person temp_val = { id, name, surname, birth_date, passport_id_number };
	for (int i = 0; i < size; i++)
	{
		newArrPersons[i] = arr_persons[i];
	}
	newArrPersons[size] = temp_val;
	size++;
	delete[] arr_persons;
	arr_persons = newArrPersons;
	id++;
}

int find_person(Person* arr_persons, int size, const string const name, const string const surname)
{
	for (int i = 0; i < size; i++)
	{
		if (arr_persons[i].name == name && arr_persons[i].surname == surname)
		{
			return i;
		}
	}
	return -1;
}


void delete_person(Person*& arr_persons, int& size, int index)
{
	Person* newArrPersons = new Person[size - 1];
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != index)
		{
			newArrPersons[j] = arr_persons[i];
			j++;
		}
	}
	size--;
	delete[] arr_persons;
	arr_persons = newArrPersons;
}

void add_book(Book*& arr_books, int& size, int& id, string name, string author, string genre, int pages)
{
	Book* newArrBooks = new Book[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArrBooks[i] = arr_books[i];
	}
	newArrBooks[size].ID = id;
	newArrBooks[size].name = name;
	newArrBooks[size].author = author;
	newArrBooks[size].genre = genre;
	newArrBooks[size].set_pages(pages);
	size++;
	delete[] arr_books;
	arr_books = newArrBooks;
	id++;
}


int find_book(Book* arr_books, int size, const string const name)
{
	for (int i = 0; i < size; i++)
	{
		if (name == arr_books[i].name)
			return i;
	}
	return -1;
}


int add_genre(string*& arr_genre, int& size, const string genre)
{
	for (int i = 0; i < size; i++)
	{
		if (arr_genre[i] == genre)
		{
			return -1;
		}
	}
	string* newArrGenre = new string[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArrGenre[i] = arr_genre[i];
	}
	newArrGenre[size] = genre;
	size++;
	delete[] arr_genre;
	arr_genre = newArrGenre;
	return 1;
}

void delete_genre(string*& arr_genre, int& size, string genre)
{
	string* newArrgenre = new string[size - 1];
	for (int i = 0, j = 0; i < size; i++)
	{
		if (arr_genre[i] != genre)
		{
			newArrgenre[j] = arr_genre[i];
			j++;
		}
	}
	size--;
	delete[] arr_genre;
	arr_genre = newArrgenre;
}

void delete_book(Book*& arr_books, int& size, int index)
{
	Book* newArrBooks = new Book[size - 1];
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != index)
		{
			newArrBooks[j] = arr_books[i];
			j++;
		}
	}
	size--;
	delete[] arr_books;
	arr_books = newArrBooks;
}




void MainMenu()
{
	cout << "\t\t\t\t\tMain Menu" << endl;
	cout << "1. Work with Books" << endl;
	cout << "2. Work with Customers" << endl;
	cout << "3. Work with Memberships" << endl;
	cout << "4. Work with Agreements" << endl;
	cout << "5. Exit" << endl;
}


void BookMenu()
{
	cout << "\t\t\t\t\tBook Menu" << endl;
	cout << "1. Add Book" << endl;
	cout << "2. Find book" << endl;
	cout << "3. Show all books" << endl;
	cout << "4. Show books by genre" << endl;
	cout << "5. Return to main menu" << endl;
}


void CustomerMenu()
{
	cout << "\t\t\t\t\Customer Menu" << endl;
	cout << "1. Add Customer" << endl;
	cout << "2. Find Customer" << endl;
	cout << "3. Show all Customers" << endl;
	cout << "4. Return to main menu" << endl;
}


void MembershipMenu()
{
	cout << "\t\t\t\t\Membership Menu" << endl;
	cout << "1. Create new Membership" << endl;
	cout << "2. Find Membership" << endl;
	cout << "3. Show all Memberships" << endl;
	cout << "4. Return to main menu" << endl;
}

void AgreementMenu()
{
	cout << "\t\t\t\t\Agreement Menu" << endl;
	cout << "1. New Agreement" << endl;
	cout << "2. Find Agreement" << endl;
	cout << "3. Show all Agreements" << endl;
	cout << "4. Return to main menu" << endl;
}

int main()
{


	int choice, book_id = 0, membership_id = 0, person_id = 0, membersip_duration = 0, aggrement_id = 0, size_book = 0, size_person = 0, size_genre = 0, size_membership = 0, index_person, index_book, pages, passport_id, payment, total_earnings = 0;
	bool book_availability, genre_availability;
	Book* arr_books = new Book[size_book];
	string* arr_genre = new string[size_genre];
	Person* arr_persons = new Person[size_person];
	Membership* arr_memberships = new Membership[size_membership];
	string customer_name, customer_surname, birth_date, book_name, genre, membership_type, author, pause;
	while (true)
	{
		system("cls");
		MainMenu();
		cout << "Please make your choice - ";
		cin >> choice;
		if (choice == 5)
		{
			break;
		}
		switch (choice)
		{
		case 1:
			while (true)
			{
				system("cls");
				BookMenu();
				cout << "Please make your choice - ";
				cin >> choice;
				if (choice == 5)
				{
					break;
				}
				switch (choice)
				{
				case 1:
					cin.ignore(1, '\n');
					cout << "Please enter title of the book - ";
					getline(cin, book_name);
					cout << "Please enter the name of the author - ";
					getline(cin, author);
					cout << "Please enter genre of the book - ";
					cin >> genre;
					cout << "PLease insert number of pages - ";
					cin >> pages;
					add_book(arr_books, size_book, book_id, book_name, author, genre, pages);
					add_genre(arr_genre, size_genre, genre);
					cout << "Book succesfully added. Please insert something to return to menu - ";
					cin >> pause;
					break;
				case 2:
					cin.ignore(1, '\n');
					cout << "Please enter title of the book - ";
					getline(cin, book_name);
					index_book = find_book(arr_books, size_book, book_name);
					if (index_book == -1)
					{
						cout << "Sorry could not find such book..." << endl;
						cout << "Please insert something to return to menu - ";
						cin >> pause;
					}
					else
					{

						system("cls");
						arr_books[index_book].ShowBookInfo();
						cout << endl << endl;
						cout << "1. Change book info" << endl;
						cout << "2. Delete book" << endl;
						cout << "3. Return to previous menu" << endl;
						cout << "Please make your choice - ";
						cin >> choice;
						if (choice == 3)
						{
							break;
						}
						switch (choice)
						{
						case 1:
							system("cls");
							cout << "1. Change book title" << endl;
							cout << "2. Change book author" << endl;
							cout << "3. Change book genre" << endl;
							cout << "4. Change number of pages " << endl;
							cout << "5. Change book availability" << endl;
							cout << "Please make your choice - ";
							cin >> choice;
							switch (choice)
							{
							case 1:
								cin.ignore(1, '\n');
								cout << "Please enter new title - ";
								getline(cin, book_name);
								arr_books[index_book].name = book_name;
								cout << "You succesfully changed title of the book. New title is - " << arr_books[index_book].name << endl;
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							case 2:
								cin.ignore(1, '\n');
								cout << "Please enter new Author - ";
								getline(cin, author);
								arr_books[index_book].author = author;
								cout << "You succesfully changed author of the book. New author is - " << arr_books[index_book].author << endl;
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							case 3:
								pause = arr_books[index_book].genre;//Я использовал тут pause чтобы в лишний раз не создать переменную
								cout << "Please enter new genre - ";
								cin >> genre;
								arr_books[index_book].genre = genre;
								genre_availability = false;
								for (int i = 0; i < size_genre; i++)
								{
									if (arr_books[i].genre == pause)
									{
										genre_availability = true;
										break;
									}
								}
								if (genre_availability == false)
								{
									delete_genre(arr_genre, size_genre, pause);
									add_genre(arr_genre, size_genre, genre);
								}
								cout << "You succesfully changed genre of the book. New genre is - " << arr_books[index_book].genre << endl;
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							case 4:
								cout << "Please enter new number of pages - ";
								cin >> pages;
								arr_books[index_book].set_pages(pages);
								cout << "You succesfully changed number of pages of the book. New number is - " << arr_books[index_book].get_pages() << endl;
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							case 5:
								cout << "Please insert 0(zero) if you want to make book unavailable, else for making it available - ";
								cin >> book_availability;
								arr_books[index_book].availability = book_availability;
								cout << "You succesfully changed number the availability of the book. Book is now available - " << boolalpha << arr_books[index_book].availability << endl;
								cout << "Please insert something to return to menu - ";
								break;
							default:
								cout << "Wrong input...\n";
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							}
							break;
						case 2:
							genre_availability = false;
							genre = arr_books[index_book].genre;
							delete_book(arr_books, size_book, index_book);
							for (int i = 0; i < size_genre; i++)
							{
								if (arr_books[i].genre == genre)
								{
									genre_availability = true;
									break;
								}
							}
							if (genre_availability == false)
							{
								delete_genre(arr_genre, size_genre, genre);
							}
							cout << "Book succesfully deleted. Please insert something to return to menu - ";
							cin >> pause;
							break;
						default:
							cout << "Wrong input...\n";
							cout << "Please insert something to return to menu - ";
							cin >> pause;
							break;
						}
					}
					break;
				case 3:
					for (int i = 0; i < size_book; i++)
					{
						arr_books[i].ShowBookInfo();
					}
					cout << "\n\nPlease insert something to return to menu - ";
					cin >> pause;
					break;
				case 4:
					if (size_genre != 0)
					{
						cout << "All genres that we have currently:\n";
						for (int i = 0; i < size_genre; i++)
						{
							cout << i + 1 << ") " << arr_genre[i] << endl;
						}
						cout << endl << endl;
						cout << "Please insert genre that you are looking for - ";
						cin >> genre;
						for (int i = 0; i < size_book; i++)
						{
							if (arr_books[i].genre == genre)
							{
								arr_books[i].ShowBookInfo();
								cout << endl;
							}
						}
					}
					else
					{
						cout << "Sorry currently we dont have any books..." << endl;
					}
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				default:
					cout << "Wrong input...\n";
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				}
			}
			break;
		case 2:
			while (true)
			{
				system("cls");
				CustomerMenu();
				cout << "Please make your choice - ";
				cin >> choice;
				if (choice == 4)
				{
					break;
				}
				switch (choice)
				{
				case 1:
					cout << "Please insert customer name - ";
					cin >> customer_name;
					cout << "Please insert customer surname - ";
					cin >> customer_surname;
					cout << "Please insert customer birtdate(dd/mm/yy) - ";
					cin >> birth_date;
					cout << "Please insert customer ID serial number(Passport ID) - ";
					cin >> passport_id;
					add_person(arr_persons, size_person, person_id, customer_name, customer_surname, birth_date, passport_id);
					cout << "Person succesfully added. Please insert something to return to menu - ";
					cin >> pause;
					break;
				case 2:
					cout << "Please insert customer name - ";
					cin >> customer_name;
					cout << "Please insert customer surname - ";
					cin >> customer_surname;
					index_person = find_person(arr_persons, size_person, customer_name, customer_surname);
					if (index_person == -1)
					{
						cout << "Such person doesnt exist in our database...\n";
					}
					else
					{
						system("cls");
						arr_persons[index_person].showPersonInfo();
						cout << endl << endl;
						cout << "1. Change person info" << endl;
						cout << "2. Delete person" << endl;
						cout << "3. Return to previous menu" << endl;
						cout << "Please make your choice - ";
						cin >> choice;
						if (choice == 3)
						{
							break;
						}
						switch (choice)
						{
						case 1:
							cout << "1. Change customer name" << endl;
							cout << "2. Change customer surname" << endl;
							cout << "3. Change customer birth date" << endl;
							cout << "4. Change customer ID serial number(Passport ID) " << endl;
							cout << "Please make your choice - ";
							cin >> choice;
							switch (choice)
							{
							case 1:
								cout << "Please enter name - ";
								cin >> customer_name;
								arr_persons[index_person].name = customer_name;
								cout << "You succesfully changed name of the customer. Name after change - " << arr_persons[index_person].name << endl;
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							case 2:
								cout << "Please enter surname - ";
								cin >> customer_surname;
								arr_persons[index_person].surname = customer_surname;
								cout << "You succesfully changed surname of the customer. Surname after change - " << arr_persons[index_person].surname << endl;
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							case 3:
								cout << "Please enter new birthdate(dd/mm/yy) - ";
								cin >> birth_date;
								arr_persons[index_person].birth_date = birth_date;
								cout << "You succesfully changed birthdate of the customer. Birthday after change - " << arr_persons[index_person].birth_date << endl;
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							case 4:
								cout << "Please enter new ID serial number(Passport ID) - ";
								cin >> passport_id;
								arr_persons[index_person].passport_id_number = passport_id;
								cout << "You succesfully changed ID serial number of the customer. Updated serial number - " << arr_persons[index_person].passport_id_number << endl;
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							default:
								cout << "Wrong input...\n";
								cout << "Please insert something to return to menu - ";
								cin >> pause;
								break;
							}
							break;
						case 2:
							delete_person(arr_persons, size_person, index_person);
							cout << "Person succesfully deleted.Please insert something to return to menu - ";
							cin >> pause;
							break;
						case 3:
							cout << "Person succesfully deleted.Please insert something to return to menu - ";
							cin >> pause;
							break;
						default:
							cout << "Wrong input...\n";
							cout << "Please insert something to return to menu - ";
							cin >> pause;
							break;
						}
					}
					break;
				case 3:
					for (int i = 0; i < size_person; i++)
					{
						arr_persons[i].showPersonInfo();
						cout << endl;
					}
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				default:
					cout << "Wrong input...\n";
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				}
			}
			break;
		case 3:
			while (true)
			{
				system("cls");
				MembershipMenu();
				cout << "Please make your choice - ";
				cin >> choice;
				if (choice == 4)
				{
					break;
				}
				switch (choice)
				{
				case 1:
					cout << "Please insert customer name - ";
					cin >> customer_name;
					cout << "Please insert customer surname - ";
					cin >> customer_surname;
					index_person = find_person(arr_persons, size_person, customer_name, customer_surname);
					if (index_person == -1)
					{
						cout << "Such person doesnt exist in our database...\n";
					}
					else
					{
						cout << "Memberships types:" << endl;
						cout << "1.Gold(12 months) - 120$" << endl;
						cout << "2.Silver(6 months) - 70$" << endl;
						cout << "3.Bronze(3 months) - 50$" << endl;
						cout << "Please choose membership type - ";
						cin >> choice;
						switch (choice)
						{
						case 1:
							membership_type = "Gold";
							membersip_duration = 12;
							payment = 120;
							total_earnings += 120;
							arr_persons[index_person].add_membership(arr_memberships, size_membership, membership_id, membership_type, membersip_duration, payment);
							arr_persons[index_person].membership_obj = arr_memberships[size_membership - 1];
							arr_persons[index_person].membership = true;
							cout << "Membership Added. Please insert something to return to menu - ";
							cin >> pause;
							break;
						case 2:
							membership_type = "Silver";
							membersip_duration = 6;
							payment = 70;
							total_earnings += 70;
							arr_persons[index_person].add_membership(arr_memberships, size_membership, membership_id, membership_type, membersip_duration, payment);
							arr_persons[index_person].membership_obj = arr_memberships[size_membership - 1];
							arr_persons[index_person].membership = true;
							cout << "Membership Added. Please insert something to return to menu - ";
							cin >> pause;
							break;
						case 3:
							membership_type = "Bronze";
							membersip_duration = 3;
							payment = 50;
							total_earnings += 50;
							arr_persons[index_person].add_membership(arr_memberships, size_membership, membership_id, membership_type, membersip_duration, payment);
							arr_persons[index_person].membership_obj = arr_memberships[size_membership - 1];
							arr_persons[index_person].membership = true;
							cout << "Membership Added. Please insert something to return to menu - ";
							cin >> pause;
							break;
						default:
							cout << "Wrong input...\n";
							cout << "Please insert something to return to menu - ";
							cin >> pause;
							break;
						}
					}
					break;
				case 2:
					cout << "Please insert customer name - ";
					cin >> customer_name;
					cout << "Please insert customer surname - ";
					cin >> customer_surname;
					index_person = find_person(arr_persons, size_person, customer_name, customer_surname);
					if (index_person == -1)
					{
						cout << "Sorry couldnt find such person..." << endl;
					}
					else if (arr_persons[index_person].membership == false)
					{
						cout << "Sorry this person dont have any membership yet...\nPlease subsribe first" << endl;
					}
					else 
					{
						system("cls");
						arr_persons[index_person].membership_obj.showInfoMembership();
						
					}
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				case 3:
					for (int i = 0; i < size_membership; i++)
					{
						arr_memberships[i].showInfoMembership();
						cout << endl;
					}
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				default:
					cout << "Wrong input...\n";
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				}
			}
			break;
		case 4:
			while (true)
			{
				system("cls");
				AgreementMenu();
				cout << "Please make your choice - ";
				cin >> choice;
				if (choice == 4)
				{
					break;
				}
				switch (choice)
				{
				case 1:
					cout << "Please insert customer name - ";
					cin >> customer_name;
					cout << "Please insert customer surname - ";
					cin >> customer_surname;
					index_person = find_person(arr_persons, size_person, customer_name, customer_surname);
					if (index_person == -1)
					{
						cout << "Sorry couldnt find such person..." << endl;
					}
					else if (arr_persons[index_person].membership == false)
					{
						cout << "Sorry this person dont have any membership yet...\nPlease subsribe first" << endl;
					}
					else
					{
						cin.ignore(1, '\n');
						cout << "Please enter title of the book - ";
						getline(cin, book_name);
						index_book = find_book(arr_books, size_book, book_name);
						if (index_book==-1)
						{
							cout << "Sorry couldnt find such book..." << endl;
						}
						else
						{
							if (arr_books[index_book].availability)
							{
								arr_persons[index_person].add_agreement(arr_books[index_book], aggrement_id);
								arr_persons[index_person].agreement = true;
								cout << "New aggrement succesfully added to " << arr_persons[index_person].name << " " << arr_persons[index_person].surname << " agreement list" << endl;
							}
							else
							{
								cout << "Sorry but this book is not available right now... " << endl;
							}
						}
					}
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				case 2:
					cout << "Please insert customer name - ";
					cin >> customer_name;
					cout << "Please insert customer surname - ";
					cin >> customer_surname;
					index_person = find_person(arr_persons, size_person, customer_name, customer_surname);
					if (index_person == -1)
					{
						cout << "Sorry couldnt find such person..." << endl;
					}
					else if (arr_persons[index_person].membership == false || arr_persons[index_person].agreement==false)
					{
						cout << "Sorry this person dont have any membership and agreement yet...\nPlease subsribe first" << endl;
					}
					else
					{
						for (int i = 0; i < arr_persons[index_person].size_agreement; i++)
						{
							arr_persons[index_person].arr_aggrements[i].showAgreement();
							cout << endl;
						}
					}
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				case 3:
					for (int i = 0; i < size_person; i++)
					{
						for (int j = 0; j < arr_persons[i].size_agreement; j++)
						{
							arr_persons[i].arr_aggrements[j].showAgreement();
							cout << endl;
						}
					}
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				default:
					cout << "Wrong input...\n";
					cout << "Please insert something to return to menu - ";
					cin >> pause;
					break;
				}
			}
			break;
		default:
			cout << "Wrong input...\n";
			cout << "Please insert something to return to menu - ";
			cin >> pause;
			break;
		}
	}
	return 0;
}