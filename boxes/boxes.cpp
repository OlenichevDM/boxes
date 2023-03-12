#include <iostream>
#include <string>
using namespace std;

class Box
{
public:
    
    int a, b, c;
    
    Box()
    {
        a = b = c = 0;
    }

    Box(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    string GetInfo()
    {
        return " длина " + to_string(a) + ", ширина " + to_string(b) + ", высота " + to_string(c);
    }

    int getA()
    {
        return a;
    }

    int getB()
    {
        return b;
    }
    
    int getC()
    {
        return c;
    }

    void filling()
    {
        cout << "длина - ";
        cin >> a;
        cout << "ширина - ";
        cin >> b;
        cout << "высота - ";
        cin >> c;
    }

    int area(int a, int b)
    {
        return a * b;
    }

    int area(int a, int b, int c)
    {
        return a * b;
    }

    int flatten()
    {
        return c = 0;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");

    int lenght = 5;
    Box* arr = new Box[lenght];
    cout << "Введите кол-во коробок: ";
    cin >> lenght;
    for (int i = 0; i < lenght; i++)
    {
        arr[i].filling();
        cout << "Box " << i+1 << ":" << arr[i].GetInfo();
        cout << endl << endl;
    }
    
    Box max_box = arr[0];
    int n = 0;
    
    for (int i = 0; i < lenght; i++)
    {
        if (arr[i].getA() > max_box.getA() && arr[i].getB() > max_box.getB() && arr[i].getC() > max_box.getC())
        {
            max_box = arr[i];
            n = i+1;
        }
    }
    
    if (n != 0)
    {
        cout << endl << "Самая большая коробка под номером " << n << ":" << max_box.GetInfo() << endl;
    }
    else
        cout << "Самая большая коробка не найдена :( " << endl;

    cout << endl;

    for (int i = 0; i < lenght; i++)
    {
        int k;
        cout << "Сплющить коробку " << i + 1 << "? (1 - yes, 0 - not) ";
        cin >> k;
        if (k == 1) { arr[i].flatten(); }
    }
    
    cout << endl;

    for (int i = 0; i < lenght; i++)
    {
        cout << "Box " << i+1 << ":" << arr[i].GetInfo() << endl;
    }

    cout << endl;

    for (int i = 0; i < lenght; i++)
    {
        if (arr[i].getC() == 0) { cout << "Площадь коробки " << i + 1 << ": " << arr[i].area(arr[i].getA(), arr[i].getB()) << endl; }
        else { cout << "Площадь коробки " << i + 1 << ": " << arr[i].area(arr[i].getA(), arr[i].getB(), arr[i].getC()) << endl; }
    }


    delete[]arr;

    return 0;
}
