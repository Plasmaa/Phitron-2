const makeGrade = (grade) => {
    if (grade < 0 || grade > 100) {
        return "Invalid Grade";
    }
    if (grade >= 90) {
        return "A+";
    }
    if (grade >= 85) {
        return "A";
    }
    if (grade >= 80) {
        return "A-";
    }
    if (grade >= 75) {
        return "B+";
    }
    if (grade >= 70) {
        return "B";
    }
    if (grade >= 65) {
        return "B-";
    }
    if (grade >= 60) {
        return "C+";
    }
    if (grade >= 55) {
        return "C";
    }
    if (grade >= 50) {
        return "C-";
    }
    if (grade >= 45) {
        return "D+";
    }
    if (grade >= 40) {
        return "D";
    }
    if (grade >= 35) {
        return "D-";
    }
    if (grade >= 30) {
        return "E";
    }
    return "F";
}

console.log(makeGrade(95));
console.log(makeGrade(72));
console.log(makeGrade(0));