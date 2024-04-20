// grade.cpp
#include <algorithm>
#include <list>
#include <vector>
#include <stdexcept>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

bool did_all_hw(const Student_info& s) {
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

// �л��� ���� ���θ� �����ϴ� ���� �Լ�
bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
    return !fgrade(s);
}

// �߰����� ����, �⸻���� ����, ���� ���� ��������
// �л��� ���� ������ ����
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

// �߰����� ����, �⸻���� ����, ���� ������ ���ͷ�
// �л��� ���� ������ ����.
// �� �Լ��� �μ��� �����ϱ� �ʰ� median �Լ��� �ش� �۾��� ����.
double grade(double mt, double ft, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("No homework!");

    return grade(mt, ft, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

double grade_aux(const Student_info& s) {
    try {
        return grade(s);
    }
    catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

// �� ��° ����:
// �ε��� ��� �ݺ��ڸ� ��������� ������
// ���� ���ϰ� �����
list<Student_info> extract_fails(list<Student_info>& students) {
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter); // ������ = �ݺ����� ��
            iter = students.erase(iter); // �ݺ����� �޸� ��ġ ����
        }
        else {
            ++iter;
        }
    }
    return fail;
}

// 6�� extract_fails
vector<Student_info> extract_fails(vector<Student_info>& students) {
    vector<Student_info>::iterator iter =
        stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    
    students.erase(iter, students.end());
    return fail;
}