#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    string path;
    cout << " Введите название файла (с форматом .txt) :";
    cin >> path;
    cin.ignore();


    int ch;
    do {

        cout << " Меню: \n"
            << " 1 - Поиск заданной строки (по итогам показывать статистику поиска строки по всему файлу) всех вхождений\n"
            << " 2 - Замена строки на новую строку(по итогам показать статистику по замене строки) всех вхождений\n"
            << " 3 - Отображение файла на экран\n"
            << " 4 - Переворот содержимого файла\n"
            << " 0 - Выход\n Ваш выбор : ";
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
        {

            ifstream fin;
            fin.open(path);

            if (!fin.is_open())
            {
                cout << " Error! \n";
            }
            else
            {
                string strfound;
                cout << " Введите строку для поиска :";
                getline(cin, strfound);


                int kol = 0;

                string str;
                while (getline(fin, str))
                {
                    int index = 0;
                    while (str.find(strfound, index) < str.length())
                    {
                        index = str.find(strfound, index);
                        kol++;
                        index++;
                    }

                }
                cout << " Количество вхождений : " << kol << "\n";
            }
            fin.close();

            break;
        }

        case 2:
        {


            ifstream fin;
            fin.open(path);

            if (!fin.is_open())
            {
                cout << " Error! \n";
            }
            else
            {
                string found;
                cout << " Введите строку для поиска :";
                getline(cin, found);


                string insert;
                cout << " Введите строку для замены :";
                getline(cin, insert);

                int kol1 = 0;
                string str;
                while (getline(fin, str))
                {
                    int index = 0;
                    while (str.find(found, index) < str.length())
                    {
                        index = str.find(found, index);
                        str.replace(str.find(found), found.length(), insert);
                        index++;
                        kol1++;
                    }

                }
                cout << " Количество замен : " << kol1 << "\n";
            }
            fin.close();
            break;
        }

        case 3:
        {
            ifstream fin;
            fin.open(path);

            if (!fin.is_open())
            {
                cout << " Error! \n";
            }
            else
            {
                string str;
                while (getline(fin, str))
                {
                    cout << str << "\n";
                }

            }
            fin.close();

            break;
        }

        case 4:
        {
            ifstream fin;
            fin.open(path);

            if (!fin.is_open())
            {
                cout << " Error! \n";
            }
            else
            {
                string str;
                while (getline(fin, str))
                {
                    reverse(str.begin(), str.end());
                    cout << str << "\n";
                }

            }
            fin.close();

            break;
        }

        }

    } while (ch != 0);
    cout << " До встречи ! \n";

}

