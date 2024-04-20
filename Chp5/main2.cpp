// main.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <algorithm>
#include <fstream> // 에런 (파일을 사용하기 위해)
#include <ios>
#include <iomanip>
#include <iostream> // cin/cout을 사용하기 위해
#include <stdexcept>
#include <string>
#include <vector>

#include "average.h"
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using namespace std;

int main() {
    // 파일스트림 만들고 "txt" 파일을 읽기
    ifstream student_file("grades.txt"); // 에런

    // vector<Student_info> students;
    Student_info student;
    string::size_type maxlen = 0;

    // 6장: 모든 과제를 제출한 학생과 그렇지 않은 학생
    vector<Student_info> did, didnt;

    // 학생 이름과 모든 점수를 읽어 저장하고
    // 가장 긴 이금을 찾음.
    while (read(student_file, student)) { // 에런
        // cin을 사용하면 직접 사용자 입력만 받을 수 있다
        // student_file은 ifstream이어서 파일 입력 받을 수 있다

        maxlen = max(maxlen, student.name.size());
        // Aaron: max(0, 5) = 5

        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // 6장: 두 집단에 데이터가 있는지 각각 확인하여 분석할 필요가 있는지 확인
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }

    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    // 6장: 분석 실행
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", 
        optimistic_median_analysis, did, didnt);


    // 학생 정보를 알파벳순으로 정렬
    /* 
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0;
        i != students.size(); ++i) {
        // 이름과 오른쪽 공백을 포함하여 maxlen + 1개의
        // 문자를 출력
        cout << students[i].name
            << string(maxlen + 1 - students[i].name.size(), ' ');

        // 종합 점수를 계산해 생성
        try {
            double final_grade = grade(students[i]);
            // 결과를 출력
            streamsize prec = cout.precision(); // 지금 cout precision
            cout << "Final grade: " << setprecision(3)
                << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();
        }
    } // for 끝
    */

    return 0;
} // main 끝
