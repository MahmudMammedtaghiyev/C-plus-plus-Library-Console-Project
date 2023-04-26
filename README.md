This project was writte by me in 16.05.2022 as my first project in C++
## Code Documentation

The code defines four different structs: `Book`, `Membership`, `Agreement`, and `Person`. Each of them has different data members and member functions.

### Book

This struct represents a book, which has the following data members:

- `name` (string): the name of the book.
- `author` (string): the author of the book.
- `genre` (string): the genre of the book.
- `ID` (int): the ID of the book.
- `availability` (bool): a flag indicating whether the book is currently available or not.
- `pages` (int): the number of pages in the book (private data member).

It has the following member functions:

- `set_pages(int pages_arg)`: sets the number of pages in the book. If `pages_arg` is greater than 0, it sets the `pages` data member to `pages_arg` and returns it. Otherwise, it returns 0.
- `get_pages()`: returns the number of pages in the book.
- `ShowBookInfo()`: prints information about the book, including its ID, name, author, genre, number of pages, and availability status.

### Membership

This struct represents a library membership, which has the following data members:

- `ID` (int): the ID of the membership.
- `sign_date` (int array): an array representing the date the membership was signed, with the first element being the day, the second element being the month, and the third element being the year.
- `membership_type` (string): the type of the membership.
- `membership_duration` (int): the duration of the membership in months.
- `expiration_date` (int array): an array representing the expiration date of the membership, with the same format as `sign_date`.
- `payment` (int): the payment made for the membership.

It has the following member function:

- `showInfoMembership()`: prints information about the membership, including its ID, sign date, type, expiration date, and payment.

### Agreement

This struct represents an agreement between a person and the library to borrow a book, which has the following data members:

- `id` (int): the ID of the agreement.
- `sign_date` (int array): an array representing the date the agreement was signed, with the same format as in `Membership`.
- `expiration_date` (int array): an array representing the expiration date of the agreement, with the same format as in `Membership`.
- `book_obj` (Book): a `Book` object representing the book being borrowed.

It has the following member function:

- `showAgreement()`: prints information about the agreement, including its ID, sign date, expiration date, and information about the borrowed book using `ShowBookInfo()` member function from `Book`.

### Person

This struct represents a person who has a library membership and can borrow books, which has the following data members:

- `ID` (int): the ID of the person.
- `name` (string): the name of the person.
- `surname` (string): the surname of the person.
- `birth_date` (string): the birth date of the person.
- `passport_id_number` (int): the passport ID number of the person.
- `membership_obj` (Membership): a `Membership` object representing the person's library membership.
- `size_agreement` (int): the size of the dynamic array `arr_agreements` that stores the person's agreements.
- `membership` (bool): a flag indicating whether the person has a library membership or not.
- `agreement` (bool): a flag indicating whether the person has


Documentation for each function:

The add_person function takes in a reference to an array of Persons, as well as other parameters for a new person's data. It dynamically creates a new array with size increased by one, copies the old array's data into the new array, adds the new person's data to the end of the new array, and then deallocates the old array. It also increments the ID of the new person.

The find_person function takes in an array of Persons and other parameters for a name and surname. It iterates through the array and returns the index of the first person with a matching name and surname, or -1 if no match is found.

The delete_person function takes in a reference to an array of Persons, the array's size, and an index to remove. It dynamically creates a new array with size decreased by one, copies all data except the indexed person from the old array to the new array, and then deallocates the old array. It also decrements the size of the new array.

The add_book function takes in a reference to an array of Books, as well as other parameters for a new book's data. It dynamically creates a new array with size increased by one, copies the old array's data into the new array, adds the new book's data to the end of the new array, and then deallocates the old array. It also increments the ID of the new book.

The find_book function takes in an array of Books and a parameter for a book's name. It iterates through the array and returns the index of the first book with a matching name, or -1 if no match is found.

The add_genre function takes in a reference to an array of strings (genres), as well as other parameters for a new genre. It iterates through the array to check if the new genre already exists, and returns -1 if it does. Otherwise, it dynamically creates a new array with size increased by one, copies the old array's data into the new array, adds the new genre to the end of the new array, and then deallocates the old array. It also returns 1 to indicate success.

Function `void delete_genre(string*& arr_genre, int& size, string genre)`
- This function takes a reference to a pointer of an array of strings `arr_genre`, an integer reference `size` indicating the size of the array, and a string `genre`.
- The function creates a new array of strings `newArrgenre` with the size one less than the original array `arr_genre` and copies all the elements except the one that matches `genre` from the original array to the new array.
- The function then decreases the size of the array and deletes the old array, and assigns the new array to the original array pointer.

Function `void delete_book(Book*& arr_books, int& size, int index)`
- This function takes a reference to a pointer of an array of `Book` structures `arr_books`, an integer reference `size` indicating the size of the array, and an integer `index`.
- The function creates a new array of `Book` structures `newArrBooks` with the size one less than the original array `arr_books` and copies all the elements except the one at `index` from the original array to the new array.
- The function then decreases the size of the array and deletes the old array, and assigns the new array to the original array pointer.

Function `void MainMenu()`
- This function displays the main menu of the library management system, including options for working with books, customers, memberships, agreements, and exiting the program.

Function `void BookMenu()`
- This function displays the book menu of the library management system, including options for adding a book, finding a book, showing all books, showing books by genre, and returning to the main menu.

Function `void CustomerMenu()`
- This function displays the customer menu of the library management system, including options for adding a customer, finding a customer, showing all customers, and returning to the main menu.

Function `void MembershipMenu()`
- This function displays the membership menu of the library management system, including options for creating a new membership, finding a membership, showing all memberships, and returning to the main menu.

Function `void AgreementMenu()`
- This function displays the agreement menu of the library management system, including options for creating a new agreement, finding an agreement, showing all agreements, and returning to the main menu.
