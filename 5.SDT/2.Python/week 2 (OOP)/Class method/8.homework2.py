class Exam:
    def __init__(self, student_name, exam_name, total_marks):
        self.student_name = student_name
        self.exam_name = exam_name
        self.total_marks = total_marks
        self.attended = False
        self.marks_obtained = 0

    def attend_to_exam(self, marks):
        if not self.attended:
            self.attended = True
            self.marks_obtained = marks
            return marks
        else:
            return "Already attended"

    def get_percentage(self):
        if self.attended:
            return (self.marks_obtained / self.total_marks) * 100
        else:
            return "Not attended yet"


# create object
exam1 = Exam("John", "Math", 100)
print(exam1.attend_to_exam(80))
print(exam1.get_percentage())

exam2 = Exam("Mike", "Science", 100)
print(exam2.attend_to_exam(90))
print(exam2.get_percentage())
