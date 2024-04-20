#pragma once
// Student_info.h

#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
}; // �����ݷ��� ���� �ʵ��� ����

bool compare(const Student_info&, const Student_info&);
istream& read(istream&, Student_info&);
istream& read_hw(istream&, vector<double>&);

void write_analysis(ostream&, const string&,
    double analysis(const vector<Student_info>&),
    const vector<Student_info>&,
    const vector<Student_info>&);

#endif