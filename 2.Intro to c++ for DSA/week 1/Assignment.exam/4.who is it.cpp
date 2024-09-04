#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    int id;
    string name;
    char section;
    int totalMarks;

    Student(int id, string name, char section, int totalMarks)
    {
        this->id = id;
        this->name = name;
        this->section = section;
        this->totalMarks = totalMarks;
    }

    Student(){}
};

int main()
{
    int T;
    cin >> T;

    Student highestStudents[T];

    for (int t = 0; t < T; ++t)
    {
        Student s[3];

        for (int i = 0; i < 3; ++i)
        {
            cin >> s[i].id >> s[i].name >> s[i].section >> s[i].totalMarks;
        }

        Student highest = s[0];
        for (int i = 1; i < 3; ++i)
        {
            if (s[i].totalMarks > highest.totalMarks ||
                    (s[i].totalMarks == highest.totalMarks && s[i].id < highest.id))
            {
                highest = s[i];
            }
        }

        highestStudents[t] = highest;
    }
    for (int i = 0; i < T; ++i)
    {
        cout << highestStudents[i].id << " " << highestStudents[i].name << " " << highestStudents[i].section << " " << highestStudents[i].totalMarks << endl;
    }

    return 0;
}
