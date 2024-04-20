// Student_info.cpp
#include "Student_info.h"

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name; // T / F (A-Z)
}

istream& read(istream& is, Student_info& s) {
    // �л��� �̸�, �߰���� ����, �⸻��� ���� �о� ����
    is >> s.name >> s.midterm >> s.final;
    // ���� ������ ����
    read_hw(is, s.homework);
    return is;
}

// �Է� ��Ʈ������ ���� ������ �о vector<double>�� ����.
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // ���� ������ ����
        hw.clear();

        // �Է��� ���� ����
        double x; // cin���� ����ϱ� 

        // �Һ���: ���ݱ��� count�� ������ �Է¹޾�����
        // �Է¹��� ������ ���� sum
        while (in >> x) {
            hw.push_back(x);
        }

        // ���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
        in.clear();

        return in;
    }
}

void write_analysis(ostream& out, const string& name,
    double analysis(const vector<Student_info>&),
    const vector<Student_info>& did,
    const vector<Student_info>& didnt) {

    out << name << ": median(did) = " << analysis(did)
        << ", median(didnt) = " << analysis(didnt) << endl;
}