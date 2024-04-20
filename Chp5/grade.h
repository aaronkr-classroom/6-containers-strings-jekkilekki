#pragma once
// grade.h

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <list>
#include <vector>
#include "Student_info.h"

bool did_all_hw(const Student_info&);
bool fgrade(const Student_info&);
bool pgrade(const Student_info&);

double grade(double, double, double);
double grade(double, double, vector<double>&);
double grade(const Student_info&);
double grade_aux(const Student_info&);
list<Student_info> extract_fails(list<Student_info>&);
vector<Student_info> extract_fails(vector<Student_info>&); // 6장

#endif