#include "LMS.h"
#include <iostream>

Book::Book(){}

Book::Book(string& ISBN, string& title, string& author, string& subject, string& publisher, string& barcode, string& status)
{
    this->ISBN = ISBN;
    this->title = title;
    this->author = author;
    this->subject = subject;
    this->publisher = publisher;
    this->barcode = barcode;
    this->status = status;
}

void Book::display()
{
    cout << "ISBN: " << ISBN << ", Title: " << title << ", Author: " << author << ", Subject: " << subject << ", Publisher: " << publisher << ", Barcode: " << barcode << ", Status: " << status << endl;
}


User::User(string& ID,string& password, string& status) 
{
    this->ID = ID;
    this->password = password;
    this->status = status;
}

Student::Student(string& ID, string& password, string& status) 
    : User(ID, password, status)
{
    borrowedCount = 0;
    enrolledCount = 0;
}

void Student::borrowBook(string& bookID) 
{
    if (borrowedCount < MAX_BORROWED_BOOKS) 
    {
        borrowedBooks[borrowedCount++] = bookID;
    }
}

void Student::returnBook(string& bookID)
{
    for (int i = 0; i < borrowedCount; i++) 
    {
        if (borrowedBooks[i] == bookID) 
        {
            for (int j = i; j < borrowedCount - 1; j++) 
            {
                borrowedBooks[j] = borrowedBooks[j + 1];
            }

            borrowedBooks[--borrowedCount] = "";
            break;
        }
    }
}

void Student::enrollCourse(string& courseID) 
{
    if (enrolledCount < MAX_COURSE_ENROLLMENTS) 
    {
        enrolledCourses[enrolledCount++] = courseID;
    }
}

void Student::display()
{
    cout << "Student ID: " << ID << ", Status: " << status << std::endl;
    cout << "Borrowed Books: ";

    for (int i = 0; i < borrowedCount; i++)
    {
        cout << borrowedBooks[i];

        if (i < borrowedCount - 1) 
        {
            cout << ", ";
        }
    }


    cout << endl;
    cout << "Enrolled Courses: ";

    for (int i = 0; i < enrolledCount; i++)
    {
        cout << enrolledCourses[i];

        if (i < enrolledCount - 1) 
        {
            cout << ", ";
        }
       
    }

    cout << endl;
}


Faculty::Faculty(string& ID, string& password, string& status)
    : User(ID, password, status) {}


void Faculty::display()
{
   cout << "Faculty ID: " << ID << ", Status: " << status << endl;
}


Course::Course(){}

Course::Course(string& courseID, string& courseName)
{
    this->courseID = courseID;
    this->courseName = courseName;
    this->enrolledCount = 0;
}


void Course::enrollStudent(string& studentID) 
{
    if (enrolledCount < MAX_USERS) 
    {
        enrolledStudents[enrolledCount++] = studentID;
    }
}

void Course::display() 
{
    cout << "Course ID: " << courseID << ", Course Name: " << courseName << endl;

    cout << "Enrolled Students: ";

    for (int i = 0; i < enrolledCount; i++)
    {
        cout << enrolledStudents[i];

        if (i < enrolledCount - 1)
        {
            cout << ", ";
        } 
    }
    cout << std::endl;
}


Library::Library(string& name, string& address)
{
    this->name = name;
    this->address = address;
    this->bookCount = 0;
    this->userCount = 0;
    this->courseCount = 0;
    this->rackCount = 0;

}

Library::~Library()
{
    for (int i = 0; i < userCount; i++)
    {
        delete users[i];
    }
}

void Library::addBook(Book& book)
{
    if (bookCount < MAX_BOOKS) 
    {
        books[bookCount++] = book;
    }
}

void Library::addUser(User* user) 
{
    if (userCount < MAX_USERS)
    {
        users[userCount++] = user;
    }
}

void Library::addCourse(Course& course) 
{
    if (courseCount < MAX_COURSES) 
    {
        courses[courseCount++] = course;
    }
}


void Library::displayLibraryInfo() 
{
    cout << "Library Name: " << name << ", Address: " << address << endl;
}

void Library::displayAllBooks()
{
    for (int i = 0; i < bookCount; i++) 
    {
        books[i].display();
    }
}

void Library::displayAllUsers()
{
    for (int i = 0; i < userCount; i++) 
    {
        users[i]->display();
    }
}

void Library::displayAllCourses()
{
    for (int i = 0; i < courseCount; i++) 
    {
        courses[i].display();
    }
}

int main() 
{
    string name = "HU.BEG Library";
    string address = "FAST NUCES Isb";
    Library lib(name, address);

    cout << "BOOK - 1:" << " ";
    string ISBN = "123-456-789";
    string bookTitle = "Calculus";
    string bookAuthor = "Thomas";
    string bookSubject = "Maths";
    string bookPublisher = "ABC Publications";
    string bookBarcode = "123456";
    string bookStatus = "available";
    Book book1(ISBN, bookTitle, bookAuthor, bookSubject, bookPublisher, bookBarcode, bookStatus);

    lib.addBook(book1);
   
    string studentID = "I220800";
    string studentPassword = "123";
    string studentStatus = "active";
    Student* student1 = new Student(studentID, studentPassword, studentStatus);

    string facultyID = "HOD@CS";
    string facultyPassword = "456";
    string facultyStatus = "active";
    Faculty* faculty1 = new Faculty(facultyID, facultyPassword, facultyStatus);

    lib.addUser(student1);
    lib.addUser(faculty1);

    string courseID1 = "EL-2003";
    string courseName1 = "COAL Lab";
    Course course1(courseID1, courseName1);

    lib.addCourse(course1);

    lib.displayLibraryInfo();
    lib.displayAllBooks();
    lib.displayAllUsers();
    lib.displayAllCourses();

    return 0;
}
