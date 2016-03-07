#ifndef QUESTION_H_
#define QUESTION_H_
#include<QString>
#include <vector>


using namespace std;
class Question //: public MainWindow
{
private:
    vector<QString> *currentQuestion;
    bool *next;
    void setNext();
    bool getNext();
    void setUp(int id);
    void clearQuestions();
public:
    Question();
    QString getQuestion(int i);
};
#endif // QUESTION_H
