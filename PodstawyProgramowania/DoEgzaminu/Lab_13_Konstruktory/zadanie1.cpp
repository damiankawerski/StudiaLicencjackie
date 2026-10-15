#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Results {
private:
    int index;
    int test1;
    int test2;
    int second_take;
public:
    Results(int id, int e1, int e2, int re) : index(id), test1(e1), test2(e2), second_take(re) {}

    Results() : index(0), test1(0), test2(0), second_take(0) {}

    float calulate_grade() {
        retakeExam();
        int totalPoints = test1 + test2;
        if(totalPoints <= 50) return 2;
        float grade = 3;
        for(int i = 60, j = 100 ; i <= j ; i+=10) {
            if(totalPoints >= i && totalPoints <= j) {
                grade += 0.5;
            }
        }
        return grade;
    }

    void retakeExam() {
        if(test1 > test2 && (second_take > test1 || second_take > test2)) {
             test2 = second_take;
        }
        else if(test2 > test1 && (second_take > test1 || second_take > test2)) {
            test1 = second_take;
        }
    }
};



float averageGrade(Results* arr, int size) {
    srand(time(0));
    float sum = 0.0f;
    for(int i = 0 ; i < size ; i++) {
        int id = i;
        int test1 = rand() % 51;
        int test2 = rand() % 51;
        int second_take = rand() % 51;

        arr[i] = Results(id, test1, test2, second_take);
        sum += arr[i].calulate_grade();
    }
return sum / (float)size;
}

int main() {
    int n = 100000;
    Results students[n];
    float grade = averageGrade(students, n);
    cout << "średnia ocen to: " << grade << endl;
    return 0;
}