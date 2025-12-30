
#include <iostream>
#include<string>
using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };

struct stRoundQuestion
{
    short NumOfQuestion = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;

};


struct stFinalGameResults
{
    short NumOfQuestion = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    short NumOfRightAnswers = 0;
    short NumOfWrongAnswers = 0;
};

struct stPartsOfQuestion
{
    float Num1 = 0;
    float Num2 = 0;
    float Result = 0;

};

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

string QuestionLevelName(enQuestionLevel QuestionLevel)
{
    string arrQuestionLevel[4] = { "Easy","Med","Hard","Mix" };
    return  arrQuestionLevel[QuestionLevel - 1];
}

string OpTypeName(enOperationType OperationType)
{
    string arrOpTypeName[5] = { "+","-","*","/","Mix" };
    return arrOpTypeName[OperationType - 1];
}

void PrintFinalGameResult(stFinalGameResults FinalGameResults)
{
    cout << "Number of Question      : " << FinalGameResults.NumOfQuestion << endl;
    cout << "Question Level          : " << QuestionLevelName(FinalGameResults.QuestionLevel) << endl;
    cout << "Operation Type          : " << OpTypeName(FinalGameResults.OperationType) << endl;
    cout << "Number Of Right Answers : " << FinalGameResults.NumOfRightAnswers << endl;
    cout << "Number Of Wrong Answers : " << FinalGameResults.NumOfWrongAnswers << endl;

    cout << "\n__________________________________________________\n";
}

bool IsPlayerWonGame(short RightAnswerTimes, short WrongAnswerTimes)
{

    if (RightAnswerTimes > WrongAnswerTimes)
        return true;
    else
        return false;
}

void ShowFinalResult(bool IsWon)
{
    if (IsWon)
    {
        cout << "\n_____________________________________\n\n";
        cout << "Final Results is Won :-)" << endl;
    }
    else
    {
        cout << "\n_____________________________________\n\n";
        cout << "Final Results is Fail :-(" << endl;

    }
    cout << "\n_____________________________________\n";
}

stFinalGameResults FillGameResults(stRoundQuestion RoundQuestion, short RightAnswerTimes, short WrongAnswerTimes)
{

    stFinalGameResults FinalGameResults;

    FinalGameResults.NumOfQuestion = RoundQuestion.NumOfQuestion;
    FinalGameResults.OperationType = RoundQuestion.OperationType;
    FinalGameResults.QuestionLevel = RoundQuestion.QuestionLevel;
    FinalGameResults.NumOfRightAnswers = RightAnswerTimes;
    FinalGameResults.NumOfWrongAnswers = WrongAnswerTimes;

    return FinalGameResults;
}

void ChangeScreenColor(bool IsCorrect)
{

    if (IsCorrect)
    {
        system("color A0");
    }
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

bool IsCorrectAnswer(float CorrectAnswer, float PlayerAnswer)
{
    if (CorrectAnswer == PlayerAnswer)
        return true;
    else
        return false;
}

void PrintResultAnswer(bool IsCorrect, float CorrectAnswer)
{
    if (IsCorrect)
    {
        cout << "\nRight answer : -)";
    }
    else
    {
        cout << "\nWrong answer : -(\n";
        cout << "The right answer is : " << CorrectAnswer << endl;
    }
}

float ReadAnswer()
{
    float Answer = 0;

    cin >> Answer;

    return  Answer;
}


// النسخة المعدلة والأفضل
stPartsOfQuestion CreatMathEquation(stPartsOfQuestion PartsOfQuestion, enOperationType OperationType)
{
    // الخطوة 1: تحديد نوع العملية الفعلي أولاً
    if (OperationType == enOperationType::Mix)
    {
        // إذا كان "Mix"، اختر نوعًا عشوائيًا وقم بتحديث المتغير
        OperationType = (enOperationType)RandomNumber(1, 4);
    }

    // الخطوة 2: الآن، نفذ العملية الحسابية بناءً على النوع الفعلي
    switch (OperationType)
    {
    case enOperationType::Add:
        PartsOfQuestion.Result = PartsOfQuestion.Num1 + PartsOfQuestion.Num2;
        break;

    case enOperationType::Sub:
        PartsOfQuestion.Result = PartsOfQuestion.Num1 - PartsOfQuestion.Num2;
        break;

    case enOperationType::Mul:
        PartsOfQuestion.Result = PartsOfQuestion.Num1 * PartsOfQuestion.Num2;
        break;

    case enOperationType::Div:
        if (PartsOfQuestion.Num2 == 0)
        {
            PartsOfQuestion.Num2 = 1; // لتجنب القسمة على صفر
        }
        PartsOfQuestion.Result = PartsOfQuestion.Num1 / PartsOfQuestion.Num2;
        break;
    }

    // الخطوة 3: الآن هذا الكود سيتم تنفيذه دائمًا لجميع الحالات
    cout << PartsOfQuestion.Num1 << "\n" << PartsOfQuestion.Num2 << " " << OpTypeName(OperationType);
    cout << "\n\n____________\n";

    return PartsOfQuestion;
}

stPartsOfQuestion PrepareNumbersByLevel(enQuestionLevel QuestionLevel)
{
    stPartsOfQuestion PartsOfQuestion;

    switch (QuestionLevel)
    {

    case enQuestionLevel::Easy:

        PartsOfQuestion.Num1 = RandomNumber(1, 10);
        PartsOfQuestion.Num2 = RandomNumber(1, 10);

        break;

    case  enQuestionLevel::Med:

        PartsOfQuestion.Num1 = RandomNumber(11, 100);
        PartsOfQuestion.Num2 = RandomNumber(11, 100);

        break;

    case enQuestionLevel::Hard:

        PartsOfQuestion.Num1 = RandomNumber(101, 500);
        PartsOfQuestion.Num2 = RandomNumber(101, 500);

        break;

    case enQuestionLevel::MixLevel:

        return PrepareNumbersByLevel((enQuestionLevel)RandomNumber(1, 3));

    }
    return PartsOfQuestion;
}

stPartsOfQuestion GenerateMathQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType)
{

    stPartsOfQuestion PartsOfQuestion = PrepareNumbersByLevel(QuestionLevel);

    PartsOfQuestion = CreatMathEquation(PartsOfQuestion, OperationType);

    return PartsOfQuestion;

}

enOperationType ReadOperationType()
{
    short OpType = 0;

    do
    {
        cout << "Enter Operation Type : [1]Add , [2]Sub , [3]Mul , [4]Div , [5]Mix : ? ";
        cin >> OpType;

    } while (OpType > 5 || OpType < 1);


    return (enOperationType)OpType;
}

enQuestionLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;

    do
    {
        cout << "Enter Question Level : [1]Easy , [2]Med , [3]Hard , [4]Mix ? ";
        cin >> QuestionLevel;

    } while (QuestionLevel > 4 || QuestionLevel < 1);

    return (enQuestionLevel)QuestionLevel;
}

short ReadNumberOfQuestion()
{
    short NumOfQuestions = 0;

    do
    {

        cout << "How many Questions do you want ?";
        cin >> NumOfQuestions;

    } while (NumOfQuestions <= 0);

    return NumOfQuestions;
}


stFinalGameResults PlayMathGame(short NumOfQuestion)
{
    stRoundQuestion RoundQuestion;
    short Answer = 0;
    bool IsCorrect = true;

    short RightAnswerTimes = 0, WrongAnswerTimes = 0;

    RoundQuestion.QuestionLevel = ReadQuestionLevel();
    RoundQuestion.OperationType = ReadOperationType();

    for (short GameRound = 1;GameRound <= NumOfQuestion;GameRound++)
    {
        RoundQuestion.NumOfQuestion = GameRound;

        cout << "\n\nQuestion[" << GameRound << "/" << NumOfQuestion << "]\n\n";

        stPartsOfQuestion  PartsOfQuestion = GenerateMathQuestion(RoundQuestion.QuestionLevel, RoundQuestion.OperationType);

        float CorrectAnswer = PartsOfQuestion.Result;

        IsCorrect = IsCorrectAnswer(CorrectAnswer, ReadAnswer());
        PrintResultAnswer(IsCorrect, CorrectAnswer);
        ChangeScreenColor(IsCorrect);


        //Win And Fail Counter
        if (IsCorrect)
            RightAnswerTimes++;
        else
            WrongAnswerTimes++;


    }

    bool IsWon = IsPlayerWonGame(RightAnswerTimes, WrongAnswerTimes);
    ShowFinalResult(IsWon);

    return  FillGameResults(RoundQuestion, RightAnswerTimes, WrongAnswerTimes);
}



void RestScreen()
{
    system("cls");
    system("color 0F");

}

void StartGame()
{
    char PlayAgain = 'y';
    do
    {
        RestScreen();
        stFinalGameResults FinalGameResults = PlayMathGame(ReadNumberOfQuestion());
        PrintFinalGameResult(FinalGameResults);

        cout << "\nDo you want to play again ? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'y' || PlayAgain == 'Y');


}


int main()
{

    srand((unsigned)time(NULL));


    StartGame();







    return 0;
}

