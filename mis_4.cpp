
#include<iostream>

using namespace std;

//создаем класс
class Shool
{
public:
    Shool(int sudents): itsStudents(sudents) { ClassRoom++; }
    virtual ~Shool() { ClassRoom--; }
    static int GetClassRoom() { return ClassRoom; } // статическая функция которая возворощает значения закрытой статической переменной
    virtual int GetStudents() { return itsStudents;}
    virtual void SetStudenrs() const = 0; // виртуальная функция

private:
    static int ClassRoom; // классов (зашищенная закрытая переменная)
    int itsStudents; // учеников
};

//реализация функции
void Shool::SetStudenrs(int stud)
{

}

//инициализируем статическую переменную
int Shool::ClassRoom = 0;

int main()
{
    const int MaxVale = 3; // кол-во объектов
    Shool *CityShool[MaxVale];

    //создаем новые объекты с запросом значений у пользователя
    for (int i = 0; i < MaxVale; i++)
    {
        CityShool[i] = new Shool(i);
        cout << "Number class room in shool " << CityShool[i]->GetClassRoom() << endl;  

    }
    cout <<"\n";
    for (int i = 0; i < MaxVale; i++)
    {
        cout << "Number class room in shool " << CityShool[i]->GetClassRoom() << endl;
        delete CityShool[i];
        CityShool[i] = nullptr;  

    }
    
    return 0;
}