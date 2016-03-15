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

    void clearQuestions();
public:
    Question();
    QString a;
    QString b;
    QString c;
    QString d;
    QString e;
   void checkAnswer(int i);

    QString getQuestion(int i);
    void setUp(int id);
    void setCounter(int ctr);
    int getCounter();
    bool getNext();
};
#endif // QUESTION_H
