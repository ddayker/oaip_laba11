#include "functions.hpp"

/*
 Описать структуру с именем MARSH, содержащую следующие поля:  название начального пункта маршрута; название конечного пункта маршрута;  номер маршрута. Написать программу, выполняющую следующие действия:  ввод с клавиатуры данных в массив, состоящий из восьми элементов типа MARSH; упорядочивать записи по алфавиту; вывод на экран информации о маршрутах, которые начинаются или кончаются в пункте, название которого введено с клавиатуры; если таких маршрутов нет, выдать на дисплей соответствующее сообщение.
 */


FILE* fp;
int a, num=0;

int main()
{

    setlocale (LC_ALL, "rus");
    bool flag = true;
    read();
    
    fp= fopen("my_file.txt","a+b");
    while (flag) {
        switch (menu())
        {
        case 1:
                cout << "Добавление маршрута:" << endl;
                add_marsh();
                num++;
            break;
        case 2:
            print();
            break;
        case 3:
                sort();
                clean();
                rewrite();
                break;
        case 4:
                change();
                clean();
                rewrite();
                break;
        case 5:
                research();
                break;
        case 6:
                delet();
                num--;
                clean();
                rewrite();
                break;
        case 7:
                cout<<"Данные будут сброшены. Продолжить?"<<endl;
                cout<<"Нажмите 0, чтобы продолжить. Нажмите любую другую клавишу для выхода!"<<endl;
                cin>>a;
                switch (a) {
                    case 0:
                        clean();
                            num=0;
                            cout<<"ВСЕ ДАННЫЕ БЫЛИ СБРОШЕНЫ!!!"<<endl;
                        break;
                    default:
                    break;}
                        break;
        case 0:
            flag = false;
                cout <<"ПРОГРАММА ЗАВЕРШЕНА"<< endl;
            break;
        default:
            printf("\nНеизвестная операция!\n");
            break;
        }
        
    }
    fclose(fp);
    return 0;
}




