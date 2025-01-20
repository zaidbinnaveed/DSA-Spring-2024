#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
    string studentName;
    string examDate;
    int score;

public:
    Exam(string name = "", string date = "", int sc = 0) {
        studentName = name;
        examDate = date;
        score = sc;
    }

    ~Exam() {}

    Exam(const Exam& other) {
        studentName = other.studentName;
        examDate = other.examDate;
        score = other.score;
    }

    Exam& operator=(const Exam& other) {
        if (this != &other) {
            studentName = other.studentName;
            examDate = other.examDate;
            score = other.score;
        }
        return *this;
    }

    void setStudentName(const string& name) {
        studentName = name;
    }

    void setExamDate(const string& date) {
        examDate = date;
    }

    void setScore(int sc) {
        score = sc;
    }

    void displayExamDetails() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }
};
