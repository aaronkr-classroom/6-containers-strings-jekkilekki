// median.cpp
#include <algorithm>
#include <stdexcept>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::vector;
using std::domain_error;
using std::sort;

// vector<double>�� �߾Ӱ��� ����.
// �Լ��� ȣ���ϸ� �μ��� ������ ���͸� ��°�� ����
double median(vector<double> vec) {
    // ���� ������ �Է� ������ Ȯ��
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("Median of empty vector");
    }

    // ������ ����
    sort(vec.begin(), vec.end());

    // ���� ������ �߾Ӱ��� ����
    vec_sz mid = size / 2;
    return size % 2 == 0
        ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// �� �Լ��� ����� �������� ����:
double median_analysis(const vector<Student_info>& students) {
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade);

    return median(grades);
}

// s.homework ���Ϳ��� 0�� �ƴ� ��ҵ��� �߾Ӱ��� ���մϴ�.
// 0�� �ƴ� ��Ұ� ���ٸ� ���� ���� ������ 0������ ó��
double optimistic_median(const vector<Student_info>& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}