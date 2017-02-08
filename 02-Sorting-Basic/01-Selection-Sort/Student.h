//
// Created by Queen on 2017/2/8.
//

#ifndef INC_01_SELECTION_SORT_STUDENT_H
#define INC_01_SELECTION_SORT_STUDENT_H

#include <iostream>
#include <string>


struct Student
{
    std::string name;
    int score;

    bool operator<(const Student &otherStudent) {
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
    }

    friend std::ostream& operator<<(std::ostream &os, const Student &student) {
        os << "Student: " << student.name << " --- " << student.score << std::endl;
        return os;
    }
};

#endif //INC_01_SELECTION_SORT_STUDENT_H
