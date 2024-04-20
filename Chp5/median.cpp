// median.cpp
#include <algorithm>
#include <stdexcept>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::vector;
using std::domain_error;
using std::sort;

// vector<double>의 중앙값을 구함.
// 함수를 호출하면 인수로 제공된 백터를 통째로 복사
double median(vector<double> vec) {
    // 과제 점수의 입력 유무를 확인
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("Median of empty vector");
    }

    // 점수를 정렬
    sort(vec.begin(), vec.end());

    // 과제 점수의 중앙값을 구함
    vec_sz mid = size / 2;
    return size % 2 == 0
        ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// 이 함수는 제대로 동작하지 않음:
double median_analysis(const vector<Student_info>& students) {
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade);

    return median(grades);
}

// s.homework 벡터에서 0이 아닌 요소들의 중앙값을 구합니다.
// 0이 아닌 요소가 없다면 종합 과제 점수를 0점으로 처리
double optimistic_median(const vector<Student_info>& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}