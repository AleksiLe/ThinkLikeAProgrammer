#include <iostream>
using std::cin;
using std::cout;

class studentRecord {
public:
studentRecord();
studentRecord(int newGrade, int newID, std::string newName);
int grade();
void setGrade(int newGrade);
int studentID();
void setStudentID(int newID);
std::string name();
void setName(std::string newName);
std::string letterGrade();
bool isValidGrade(int grade);
private:
    int _grade;
    int _studentID;
    std::string _name;
};

studentRecord::studentRecord()
{
    _grade = 0;
    _studentID = -1;
    _name = "";
}

studentRecord::studentRecord(int newGrade, int newID, std::string newName)
{
    _grade = newGrade;
    _studentID = newID;
    _name = newName;
}

int studentRecord::grade()
{
    return _grade;
}

void studentRecord::setGrade(int newGrade)
{
    if(isValidGrade(newGrade)) _grade = newGrade;
    else cout << "Invalid grade " << newGrade << '\n';
}

int studentRecord::studentID()
{
    return _studentID;
}

void studentRecord::setStudentID(int newID)
{
    _studentID = newID;
}

std::string studentRecord::name()
{
    return _name;
}

void studentRecord::setName(std::string newName)
{
    _name = newName;
}

std::string studentRecord::letterGrade()
{
    if (!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const std::string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
    {
        category++;
    }
    return GRADE_LETTER[category - 1];
}

bool studentRecord::isValidGrade(int grade)
{
    if (grade < 0 || grade > 100) return false;
    return true;
}

int main()
{
    studentRecord student1 = studentRecord(12, 1000, "Mario");
    cout << student1.letterGrade() << '\n';
    student1.setGrade(100);
    cout << student1.letterGrade() << '\n';
    return 0;
}