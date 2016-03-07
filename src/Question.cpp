
#include "Question.h"

Question::Question()
{

}
void Question::setNext(){

}
bool Question::getNext(){

}
QString Question::getQuestion(int i){
    return currentQuestion->at(i);
}
void Question::clearQuestions(){
    currentQuestion->clear();
}
void Question::setUp(int id){
      switch(id){

        case 2:{
           QString a="In what children's game are participants chased by someone designated,Tag,Simon Says,Charades,Hopscotch,0";
           QString b="On a radio, stations are changed by using what control?,Tuning,Volume,Bass,Treble,0";
           QString c="Which material is most dense?,Silver,Styrofoam,Butter,Gold,3";
           QString d="Which state in the United States is largest by area?,Alaska,California,Texas,Hawaii,0";
           currentQuestion->push_back(a);
           currentQuestion->push_back(b);
           currentQuestion->push_back(c);
           currentQuestion->push_back(d);
        }
        break;
        case 3:{

          QString a="Which two countries currently account for more than a third of Earth's population?,China and Russia,India and China, India and Pakistan,China and Brazil,1";
          QString b="Go-Gurt, yogurt in a tube, is manufactured by what brand?,Dannon,Breyer's,Yoplait,TCBY,2";
          QString c="Acadia National Park is located in what U.S. state?, Maine, Michigan,Arkansas,Louisiana";
          QString d="The National Hockey League's trophy for league's leading goal scorer is named for what player?,Wayne Gretzky,Maurice Richard,Gordie Howe,Mario Lemieux,1";
          currentQuestion->push_back(a);
          currentQuestion->push_back(b);
          currentQuestion->push_back(c);
          currentQuestion->push_back(d);
        }
        break;
        case 4:{
          QString h= "Take of my skin and i wont cry but you will";
          currentQuestion->push_back(h);
        }break;
        case 5:{
          QString g= "Poor people have it\nRich People need it\nif you eat it you die";
          currentQuestion->push_back(g);
        }break;
        case 6:{
           QString f= "I am tall when I am young but short when I am old";
           currentQuestion->push_back(f);
        }break;
        case 7:{
          QString e= "I have a a neck but my head is nor there";
          currentQuestion->push_back(e);
        }break;
        case 8:{
          QString d= "a.) What Room can no one Enter?,b.) If you look at My face you will never see the number 13";
          currentQuestion->push_back(d);
        }break;
        case 9:{
            QString c="A snail you may ?";
            currentQuestion->push_back(c);
        }break;
        case 10:{
            QString b= "What is Sushi wrapped in?";
            currentQuestion->push_back(b);
        }break;
        case 11:{
          QString g="You unlocked room a  now decrypt the the message and\nyou will have the password to reset the teleporter";
          currentQuestion->push_back(g);
        }break;
        case 12:{
          QString a="What does the code 'cout<<(0==0);' print?,0,1, Compiler error: Lvalue required";
          QString b="According to the ANSI C++ standard, what does the getch() do?,Reads in a character,Checks the keyboard buffer,Nothing (getch() is not an ANSI C++ function)";
          QString c="If the program completes executing successfully, what value should the function main() return?, 0,1,void";
          QString d="C is to C++ as 1 is to,What the heck?,2,10";
          QString e="Which of the following sorts is quickest when sorting the following set: 1 2 3 5 4,Quick Sort,Bubble Sort,Merge Sort";
          currentQuestion->push_back(a);
          currentQuestion->push_back(b);
          currentQuestion->push_back(c);
          currentQuestion->push_back(d);
          currentQuestion->push_back(e);
      }
        break;
      }
}
