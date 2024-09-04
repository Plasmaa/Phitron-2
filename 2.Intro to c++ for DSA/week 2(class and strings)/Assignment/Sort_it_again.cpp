#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int cls;
    char section;
    int id;
    int math_marks;
    int eng_marks;

    int total_marks()
    {
        return math_marks + eng_marks;
    }
};

bool cmp(Student a, Student b)
{
    if (a.eng_marks == b.eng_marks)
    {
        if (a.math_marks == b.math_marks)
        {
            return a.id < b.id;
        }
        return a.math_marks > b.math_marks;
    }
    else 
    {
        return a.eng_marks > b.eng_marks;
    }
}

int main()
{
    int n;
    cin >> n;
    Student students[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> students[i].name >> students[i].cls >> students[i].section >> students[i].id >> students[i].math_marks >> students[i].eng_marks;
    }

    sort(students, students + n, cmp);

    for (int i = 0; i < n; ++i)
    {
        cout << students[i].name << " " << students[i].cls << " " << students[i].section << " " << students[i].id << " " << students[i].math_marks << " " << students[i].eng_marks << endl;
    }

    return 0;
}
