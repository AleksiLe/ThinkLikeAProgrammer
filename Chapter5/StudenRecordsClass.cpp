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

class studentCollection {
    private:
        struct studentNode {
            studentRecord studentData;
            studentNode *next;
        };
    public:
        studentCollection();
        ~studentCollection();
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int studentID);
        void removeRecord(int studentID);
        void deleteList();
        void printOut();
    private:
        typedef studentNode* studentList;
        studentList _listHead;
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

studentCollection::studentCollection()
{
    _listHead = NULL;
}

studentCollection::~studentCollection()
{
    deleteList();
}

void studentCollection::addRecord(studentRecord newStudent)
{
    studentNode *newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int studentID)
{
    studentNode *loopPtr = _listHead;
    while(loopPtr != NULL && loopPtr->studentData.studentID() != studentID) // Skips the second evaluation if first is false (c++ short-circuit evaluation)
    {
        loopPtr = loopPtr->next;
    }
    {
        loopPtr = loopPtr->next;
    }
    if(loopPtr == NULL)
    {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } else
    {
        return loopPtr->studentData;
    }
}

void studentCollection::removeRecord(int studentID)
{
    studentNode *loopPtr = _listHead;
    studentNode *prevPtr = NULL;
    while(loopPtr != NULL && loopPtr->studentData.studentID() != studentID)
    {
        prevPtr = loopPtr;
        loopPtr = loopPtr->next;
    }
    if(loopPtr == NULL) return;
    if(prevPtr == NULL) _listHead = _listHead->next;
    else prevPtr->next = loopPtr->next;
    delete loopPtr;
}

void studentCollection::deleteList()
{
    studentNode *loopPtr = _listHead;
    while(loopPtr != NULL)
    {
        studentNode *temp = loopPtr;
        loopPtr = loopPtr->next;
        delete temp;
    }
    _listHead = NULL;
}

void studentCollection::printOut()
{
    studentNode *loopPtr = _listHead;
    while(loopPtr != NULL)
    {
        cout << "Name:  " << loopPtr->studentData.name() << " Id: " << loopPtr->studentData.studentID() << '\n';
        loopPtr = loopPtr->next;
    }
}

int main() 
{
    studentRecord std1 = studentRecord(100,1, "Luigi");
    studentRecord std2 = studentRecord(80, 2, "Mario");
    studentRecord std3 = studentRecord(50, 3, "Browser");
    studentCollection stdCollection = studentCollection();
    stdCollection.addRecord(std1);
    stdCollection.addRecord(std2);
    stdCollection.addRecord(std3);
    stdCollection.printOut();
}




