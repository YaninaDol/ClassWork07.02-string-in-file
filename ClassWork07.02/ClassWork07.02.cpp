#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    string path;
    cout << " ������� �������� ����� (� �������� .txt) :";
    cin >> path;
    cin.ignore();


    int ch;
    do {

        cout << " ����: \n"
            << " 1 - ����� �������� ������ (�� ������ ���������� ���������� ������ ������ �� ����� �����) ���� ���������\n"
            << " 2 - ������ ������ �� ����� ������(�� ������ �������� ���������� �� ������ ������) ���� ���������\n"
            << " 3 - ����������� ����� �� �����\n"
            << " 4 - ��������� ����������� �����\n"
            << " 0 - �����\n ��� ����� : ";
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
                cout << " ������� ������ ��� ������ :";
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
                cout << " ���������� ��������� : " << kol << "\n";
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
                cout << " ������� ������ ��� ������ :";
                getline(cin, found);


                string insert;
                cout << " ������� ������ ��� ������ :";
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
                cout << " ���������� ����� : " << kol1 << "\n";
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
    cout << " �� ������� ! \n";

}

