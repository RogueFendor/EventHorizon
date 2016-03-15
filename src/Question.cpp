
#include "Question.h"
#include<QString>
#include<QStringList>

Question::Question()
{
   counter =0;
}

void Question::setCounter(int ctr){
    counter = ctr;
}
int Question::getCounter(){
    return counter;
}
void Question::setNext(bool n){
       next = n;
}
bool Question::getNext(){
  return next;
}
QString Question::getQuestion(int i){
   switch(i){
   case 1:
       return a;
   break;
   case 2:
       return b;
   break;
   case 3:
       return c;
   break;
   case 4:
       return d;
   break;
   case 5:
       return e;
   break;
   }
}
void Question::clearQuestions(){

}
void Question::checkAnswer(int i){

   // QStringList *list = getQuestion(getCounter()+1).split(",");

}
void Question::setUp(int id){
      switch(id){

        case 2:{
           a="In what childrens game are participants chased by someone designated,Tag,Simon Says,Charades,Hopscotch,0";
           b="On a radio, stations are changed by using what control?,Tuning,Volume,Bass,Treble,0";
           c="Which material is most dense?,Silver,Styrofoam,Butter,Gold,3";
           d="Which state in the United States is largest by area?,Alaska,California,Texas,Hawaii,0";
        }
        break;
        case 3:{

          a="Which two countries currently account for more than a third of Earths population?,China and Russia,India and China, India and Pakistan,China and Brazil,1";
          b="Go-Gurt, yogurt in a tube, is manufactured by what brand?,Dannon,Breyers,Yoplait,TCBY,2";
          c="Acadia National Park is located in what U.S. state?, Maine, Michigan,Arkansas,Louisiana";
          d="The National Hockey Leagues trophy for leagues leading goal scorer is named for what player?,Wayne Gretzky,Maurice Richard,Gordie Howe,Mario Lemieux,1";




        }
        break;
        case 4:{
          a= "Take of my skin and i wont cry but you will";
        }
        break;
        case 5:{
          a= "Go to Room LB and Bring me this:\n Poor people have it\nRich People need it\nif you eat it you die";
        }
          break;
        case 6:{
           a= "I am tall when I am young but short when I am old";
        }
          break;
        case 7:{
          a= "I have a a neck but my head is nor there";
        }
          break;
        case 8:{
           a= "a.) What Room can no one Enter?,b.) If you look at My face you will never see the number 13";
        }
          break;
        case 9:{
            a ="A snail you may ?";
        }break;
        case 10:{
            a= "What is Sushi wrapped in?";

        }
          break;
        case 11:{
           a="You unlocked room a  now decrypt the the message and\nyou will have the password to reset the teleporter";
        }
          break;
        case 12:{
           a="What does the code cout<<(0==0); print?,0,1, Compiler error: Lvalue required";
           b="According to the ANSI C++ standard, what does the getch() do?,Reads in a character,Checks the keyboard buffer,Nothing (getch() is not an ANSI C++ function)";
           c="If the program completes executing successfully, what value should the function main() return?, 0,1,void";
           d="C is to C++ as 1 is to,What the heck?,2,10";
           e="Which of the following sorts is quickest when sorting the following set: 1 2 3 5 4,Quick Sort,Bubble Sort,Merge Sort";

         }
        break;
      }
}
