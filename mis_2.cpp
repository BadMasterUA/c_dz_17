#include<iostream>

using namespace std;

//создаем класс
class Shool
{
public:
    Shool(int c_room): itsClassRoom(c_room) { Students++; }
    virtual ~Shool() { Students--; }
    virtual int GetClassRoom() { return itsClassRoom; }
    static int GetStudents() { return Students;}

private:
    int itsClassRoom; // классов
    static int Students; // учеников
};

//инициализируем статическую переменную
int Shool::Students = 0;

int main()
{
    return 0;
}