#include "functions.hpp"

/*
 Описать структуру с именем MARSH, содержащую следующие поля:  название начального пункта маршрута; название конечного пункта маршрута;  номер маршрута. Написать программу, выполняющую следующие действия:  ввод с клавиатуры данных в массив, состоящий из восьми элементов типа MARSH; упорядочивать записи по алфавиту; вывод на экран информации о маршрутах, которые начинаются или кончаются в пункте, название которого введено с клавиатуры; если таких маршрутов нет, выдать на дисплей соответствующее сообщение.
 */

struct MARSH
{
    char startpoint[15];
    char finishpoint[15];
    char number[10];
};

struct MARSH p_marsh[8];
extern FILE* fp;
extern int num;

extern void read(){
    int v=0;
    fp= fopen("my_file.txt","rb");
       if(!(fp = fopen("my_file.txt","rb")))
       {
         printf("Невозможно открыть файл!\n");
           while (v>2 || v<1){
         printf("1 - Создать новый файл\n");
         printf("2 - Выход\n");
           scanf("%d",&v);
           switch (v) {
               case 1:
                   fp= fopen("my_file.txt","w+b");
                   fclose(fp);
                   puts("ФАЙЛ СОЗДАН");
                   break;
               case 2: puts("ПРОГРАММА ЗАВЕРШЕНА"); exit(1);
               default: puts("Неверное действие, введите 1 или 2.");
               break;}
           }
       }
       else {fread(p_marsh, sizeof(p_marsh),1,fp);
           num =(int)(ftell(fp))/40;
           fclose(fp);
       }
}

int menu()
{
    int choice;
    printf( "Выберите операцию:\n");
    printf( "1) Добавление нового маршрута в файл\n");
    printf( "2) Вывод информации о всех читателях\n");
    printf( "3) Сортировка по алфавиту\n");
    printf( "4) Изменение информации о маршруте\n");
    printf( "5) Поиск маршрута\n");
    printf( "6) Удаление информации о маршруте\n");
    printf( "7) Сброс данных и отчистка файла\n");
    printf( "0) Выход.\n");
    scanf("%d", &choice);
    return choice;
}

void add_marsh()
{
    
    if (num<8){
    printf("Читатель №%d\n",num+1);
    cout << "Введите данные маргрута:" << endl;
    cout << "Начальная точка: ";
        getchar();
    cin.getline((p_marsh+ num)->startpoint, 15);
    cout << "Конечная точка: ";
    cin.getline((p_marsh+ num)->finishpoint, 15);
    cout << "Номер маршрута: ";
        cin>> (p_marsh+ num)->number;
        
    cout << endl;
    fwrite((p_marsh+num), sizeof(*p_marsh),1,fp);
    return;
    }
    else cout << "\nМАССИВ ПЕРЕПОЛНЕН!\n"<< endl;
}


void print()
{
    if (num == 0)
    {
        cout << "ДАННЫХ НЕТ! Введите данные.\n" << endl;
        return;
    }
    
    printf("\n ---------------------------------------------------------\n");
    printf(" |№| Начальная точка  |  Конечная точка  | Номер маршрута|\n");
    printf(" |-+------------------+------------------+---------------|\n");

    for (int i = 0; i < num; i++)
    {
        printf(" |%d|%16s  |%16s  |%13s  |\n", i + 1, (p_marsh + i)->startpoint, (p_marsh + i)->finishpoint, (p_marsh + i)->number);
    }
    printf(" ---------------------------------------------------------\n");

}

void delet()
{
    int choice=-1;
    while (choice > num  || choice <= 0){
        cout << "Введите поярдковый(по списку) номер маршрута, которого хотите удалить: ";
            cin >> choice;
        if(choice > num || choice <= 0)cout << "Такого читателя не существует"<< endl;
        }
        choice--;
        for (int i = choice; i <= num; i++) {
            p_marsh[i] = p_marsh[i + 1];
        }
        cout << "Опрерация завершена!" << endl;
    }

void clean(){
    fclose(fp);
    fp= fopen("my_file.txt","w+b");
}

void rewrite(){
    int i = 0;
    while (i < num) {
        fwrite((p_marsh+i), sizeof(*p_marsh),1,fp);
        i++;
    }
}



void sort()
{
    if (num == 0)
    {
        cout << "Введите данные!" << endl;
        return;
    }
    
    for (int i = 0; i < num - 1; i++)
        for (int j = i + 1; j < num; j++) {
            if (strcmp(p_marsh[i].startpoint, p_marsh[j].startpoint)>0)
                swap(p_marsh[i].startpoint, p_marsh[j].startpoint);
        }
    cout << "\nСортировка завершена!\n" << endl;
    
}



void change()
{
    if (num == 0)
    {
        cout << "Введите данные!" << endl;
        return;
    }
    int choice, numb=-1;
    while (numb> num  || numb <= 0){
    cout << "Маршрут(по порядку), для которого необходимо изменить информацию: ";
        cin >> numb;
    }
    numb--;
    
    while (1) {
        cout << "Выберите параметр, который хотите изменить:" << endl;
        cout << "1) Начальная точка" << endl;
        cout << "2) Конечная точка" << endl;
        cout << "3) Номер маршрута;" << endl;
        cout << "4) Выход." << endl;
        cin >> choice;
        if (choice == 4)
        {
            cout << "Операция завершена!" << endl;
            return;
        }
       
        char str[15];
        switch (choice)
        {
        case 3:
                 while (true){
                 cout << "Введите новый номер маршрута: ";
                 getchar();
                 cin>> str;
                     int flag =0;
                  for (int i = 0; i < num; i++) {
                      if (strcmp((p_marsh + i)->number, str) == 0){
                          cout << "Этот номер уже занят!" <<endl;flag++;}
                   }
                     if(flag==0)break;
                 }
            strcpy((p_marsh + numb)->number, str);
            break;
        case 1:
            cout << "Начальная точка:" << endl;
            getchar();
            gets(str);
            strcpy((p_marsh + numb)->startpoint, str);
            break;
        case 2:
                cout << "Конечная точка:" << endl;
                getchar();
                gets(str);
                strcpy((p_marsh + numb)->finishpoint, str);
                break;
        default:
            cout << "Неверная операция!" << endl;
            break;
        }

    }}
    


void print1(int num)
{
        cout << "------------------------------"<< endl;
        cout << "Начальная точка: "<< (p_marsh + num)->startpoint << endl;
        cout << "Конечная точка: " << (p_marsh + num)->finishpoint << endl;
        cout << "Номер маршрута " << (p_marsh + num)->number << endl;
        cout << "------------------------------"<< endl;
        cout << endl;

}

void research()
{
    if (num == 0)
    {
        cout << "Введите данные!" << endl;
        return;
    }
    int choice;
    while (1) {
        cout << "Выберите параметр, по которому будет осуществлён поиск:" << endl;
        cout << "1) Начальная точка" << endl;
        cout << "2) Конечная точка" << endl;
        cout << "3) Номер маршрута;" << endl;
        cout << "4) Выход." << endl;
        cin >> choice;
        char str[60];
        int flag = 0;
        switch (choice)
        {
        case 3:
            cout << "Введите номер : ";
            getchar();
            flag = 0;
            gets(str);

            for (int i = 0; i < num; i++) {
                if (strcmp((p_marsh + i)->number, str) == 0) {
                    cout << "\nПараметр найден, это " << " Маршрут №" << i + 1 << endl;
                    print1(i);
                    flag++;
                }
            }
            if (flag == 0)
            {
                cout << "Маршрут с такими параметрами не найден!" << endl;
            }
            break;
        
        case 1:
                cout << "Введите начальную точку : ";
                getchar();
                flag = 0;
                gets(str);

                for (int i = 0; i < num; i++) {
                    if (strcmp((p_marsh + i)->startpoint, str) == 0) {
                        cout << "\nПараметр найден, это " << " Маршрут №" << i + 1 << endl;
                        print1(i);
                        flag++;
                    }
                }
                if (flag == 0)
                {
                    cout << "Маршрут с такими параметрами не найден!" << endl;
                }
               
            break;
                
        case 2:
                cout << "Введите конечную точку : ";
                getchar();
                flag = 0;
                gets(str);

                for (int i = 0; i < num; i++) {
                    if (strcmp((p_marsh + i)->finishpoint, str) == 0) {
                        cout << "\nПараметр найден, это " << " Маршрут №" << i + 1 << endl;
                        print1(i);
                        flag++;
                    }
                }
                if (flag == 0)
                {
                    cout << "Маршрут с такими параметрами не найден!" << endl;
                }
            break;
        case 4:
            cout << "Поиск окончен!" << endl;
            return;
            break;
        default:
            cout << "Неверное действие!" << endl;
            break;
        }
    }
}

