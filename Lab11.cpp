#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
//To run enter: make run clean
bool fail_lecture(const vector<int>& attendance_records, int* count_out = nullptr) {
    int absent_count = 0;
    for (size_t i = 1; i < attendance_records.size(); ++i) {   // FAULT: should be i = 0
        absent_count += attendance_records[i] == 0;
    }
    if (count_out) *count_out = absent_count;
    return absent_count >= 3;
}
 

bool fail_lecture_correct(const vector<int>& a, int* count_out = nullptr) {
    int absent_count = 0;
    for (size_t i = 0; i < a.size(); ++i) absent_count += a[i] == 0;
    if (count_out) *count_out = absent_count;
    return absent_count >= 3;
}
 
void run(const string& name, const vector<int>& rec) {
    int actual_cnt, expected_cnt;
    bool actual = fail_lecture(rec, &actual_cnt);
    bool expected = fail_lecture_correct(rec, &expected_cnt);
    cout << name << "\n  record: ";
    for (int x : rec) cout << x << ' ';
    cout << "\n  absent_count  expected=" << expected_cnt << " actual=" << actual_cnt
         << (expected_cnt == actual_cnt ? "  (state OK)" : "  (ERROR STATE)")
         << "\n  output        expected=" << boolalpha << expected << " actual=" << actual
         << (expected == actual ? "  (no failure)" : "  (FAILURE)") << "\n\n";
}
 
int main() {
    run("Test A (Q3): executes fault, no error state", {1,1,1,1,1,1,1,1,1,1});
    run("Test A2 (Q3): executes fault, no error state, absences elsewhere", {1,0,1,0,1,1,1,1,1,1});
    run("Test B (Q4): error state, no failure", {0,0,0,0,1,1,1,1,1,1});
    run("Test C (Q5): failure", {0,0,1,1,1,1,1,1,1,0});
    run("Test D (Q5): failure (minimal)", {0,0,0,1,1,1,1,1,1,1});
    return 0;
}