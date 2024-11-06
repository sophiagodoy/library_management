# Library Management System

This project is a library management system implemented in C++, which allows for registering, consulting, borrowing, returning, and removing books. The program works through an interactive menu, where the user can select different options to manage the book collection.

## Features

The system includes the following features:

1. **Register Book**: Allows the registration of a new book by providing information such as:
   - Title
   - Author
   - Number of pages
   - Year of publication
   - Unique identification code
   - Available copies (up to 10)

2. **Consult Book**: Allows consulting registered books in three ways:
   - List all books.
   - Search by identification code.
   - Search by title.

3. **Borrow Book**: Registers the borrowing of a book by associating the name of the person who borrowed it. A book can only be borrowed if there are available copies.

4. **Return Book**: Allows returning a book, removing the borrower's name and increasing the number of available copies.

5. **Remove Book**: Removes a book from the system based on its identification code.
