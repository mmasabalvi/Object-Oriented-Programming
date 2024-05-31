#include<iostream>
#include <string>
using namespace std;

class Book 
{
private:
    string ISBN;
    string title;
    string author;
    string subject;
    string publisher;
    string barcode;
    string status;

public:
    Book();
    Book(string& ISBN, string& title, string& author, string& subject, string& publisher, string& barcode, string& status);
    void display();
};

class User 
{
protected:
    string ID;
    string password;
    string status;

public:
    User(string& ID, string& password, string& status);
    virtual void display() = 0;
};

class Student : public User 
{
private:
    string borrowedBooks[MAX_BORROWED_BOOKS];
    string enrolledCourses[MAX_COURSE_ENROLLMENTS];
    int borrowedCount;
    int enrolledCount;

public:
    Student(string& ID, string& password, string& status);
    void borrowBook(string& bookID);
    void returnBook(string& bookID);
    void enrollCourse(string& courseID);
    void display() override;
};

class Faculty : public User 
{
public:
    Faculty(string& ID, string& password, string& status);
    void display() override;
};

class Course
{
private:
    string courseID;
    string courseName;
    string enrolledStudents[MAX_USERS];
    int enrolledCount;

public:
    Course();
    Course(string& courseID, string& courseName);
    void enrollStudent(string& studentID);
    void display();
};


class Library 
{
private:
    string name;
    string address;
    Book books[MAX_BOOKS];
    User* users[MAX_USERS];
    Course courses[MAX_COURSES];
    int bookCount;
    int userCount;
    int courseCount;
    int rackCount;

public:
    Library(string& name, string& address);
    void addBook(Book& book);
    void addUser(User* user);
    void addCourse(Course& course);
    void displayLibraryInfo();
    void displayAllBooks();
    void displayAllUsers();
    void displayAllCourses();
    ~Library();
};

const int MAX_BOOKS = 100;
const int MAX_USERS = 100;
const int MAX_COURSES = 100;
const int MAX_BORROWED_BOOKS = 10;
const int MAX_COURSE_ENROLLMENTS = 10;
