#ifndef QUESTION_H_
#define QUESTION_H_
#include<QString>
#include <vector>


using namespace std;
class Question //: public MainWindow
{
private:
    bool next;
    void setNext(bool n);
    int counter =1;
    int numOfQuestion;

    void clearQuestions();
public:
    QString a;
    QString b;
    QString c;
    QString d;
    QString e;
    QString currentQuestion;
    Question();

    QString getQuestion(int i);
    void setUp(int id);
    void setCounter(int ctr);
    void setCurrentQuestion(QString qS);
    bool verifyAnswer(QString n);
    QString getCurrentQuestion();
    int getCounter();
    void setNumOfQuestions(int x);
    int getNumOfQuestions();
    bool getNext();
};
#endif // QUESTION_H
