
#include<iostream>

using namespace std;

//создаем класс
class Shool
{
public:
    Shool(int sudents, int graduates, int excluded): itsStudents(sudents), itsGraduates(graduates), itsExcluded(excluded) { ClassRoom++; }
    virtual ~Shool() { ClassRoom--; }
    static int GetClassRoom() { return ClassRoom; } // статическая функция которая возворощает значения закрытой статической переменной
    virtual int GetStudents() { return itsStudents;}
    virtual int GetGraduates() { return itsGraduates;}
    virtual int GetExcluded() { return itsExcluded;}
    //virtual void SetStudenrs(int stud) { itsStudents = stud; }

private:
    static int ClassRoom; // классов (зашищенная закрытая переменная)
    int itsStudents; // учеников
    int itsGraduates; // выпускников
    int itsExcluded; // исключенных
};

//инициализируем статическую переменную
int Shool::ClassRoom = 0;

int main()
{
    int (Shool::*pFunc)(); // указатель на функцию
    Shool *ptr = nullptr; // указатель на объект

    ptr = new Shool(20, 15, 5); // создаем новый объект

    //выбор действия
    bool fQuit = false;
    int choic;
    while(fQuit == false)
    {
        cout << "Select an action\n(1) Number of students\n(2) Number of graduates\n(3) Number of excluded\n(4) Qiut\n ";
        cin >> choic;

        switch (choic)
        {
        case 1:
            pFunc = &Shool::GetStudents;
            cout << "Number of students in a class: " << (ptr->*pFunc)() << endl;
            break;
        case 2:
            pFunc = &Shool::GetGraduates;
            cout << "Number of graduates in a class: " << (ptr->*pFunc)() << endl;
            break;
        case 3:
            pFunc = &Shool::GetExcluded;
            cout << "Number of expelled students" << (ptr->*pFunc)() << endl;
            break;
        default:
            fQuit = true;
            break;
        }

        if(fQuit == true)
        {
            break;
        }
        
    }
     
    delete ptr; // удоляем объект

    return 0;
}