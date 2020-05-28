#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct person {
    char name[20];
    char pass[20];
    int one; // по студентам
    int two; // по книгам
};

struct books {
    int isbn;
    char fio[20];
    char name[20];
    int all;
    int dostup;
} books_t;



struct students {
    char zach[20];
    char fam[20];
    char name[20];
    char fath[20];
    char fak[20];
    char spec[20];
};

void input(struct person people[],int n) {
    for (int i = 0; i < n; i++) 
        printf("%s %s %d %d\n", people[i].name, people[i].pass, people[i].one, people[i].two);
}
int LogIn(struct person people[], int n, int* klient);

int StudPeople() {
    // ***
    char line[1024]; // В этой строке будут лежать данные о всём файле
    char* token; // это переводвая переменная
    FILE* file2 = fopen("students.csv", "r");
    printf("Открытие файла : ");
    // Проверка открытия файла
    if (file2 == NULL) printf("ошибка\n");
    else printf("выполнено\n");
    // тут всё работает так, что мы можем считывать строки из excel и самое главное по количеству написанного в excel.будь то 100000 строк или 1 строка
    struct students* lib;
    struct students* libvspom;
    int n=0, time1 = 0, time2 = 0;
    lib = (struct books*)malloc((1) * sizeof(struct students));
    libvspom = (struct books*)malloc(1 * sizeof(struct students));
    for (int j = 0; fgets(line, sizeof(line), file2); j++) { // идём по всему списку
        if (j != 0) { // тут мы будем расширять динамическую структуру
            // копируем во второй
            libvspom = (struct books*)malloc((j) * sizeof(struct students));
            for (int i = 0; i < j != NULL; i++) {
                strcpy((libvspom + i)->zach, (lib + i)->zach);
                strcpy((libvspom + i)->fam, (lib + i)->fam);
                strcpy((libvspom + i)->name, (lib + i)->name);
                strcpy((libvspom + i)->fath, (lib + i)->fath);
                strcpy((libvspom + i)->fak, (lib + i)->fak);
                strcpy((libvspom + i)->spec, (lib + i)->spec);
            }
            lib = (struct students*)malloc((j + 1) * sizeof(struct students)); // расширяем нашу главную структуру
            // копируем обратно
            for (int i = 0; i < j != NULL; i++) {
                strcpy((lib + i)->zach, (libvspom + i)->zach);
                strcpy((lib + i)->fam, (libvspom + i)->fam);
                strcpy((lib + i)->name, (libvspom + i)->name);
                strcpy((lib + i)->fath, (libvspom + i)->fath);
                strcpy((lib + i)->fak, (libvspom + i)->fak);
                strcpy((lib + i)->spec, (libvspom + i)->spec);
            }
        }
        n = j + 1;
        token = strtok(line, ";"); // отыскиваем всю информацию между точке с запятыми
        for (int i = 0; token != NULL; i++) { // теперь идём по строке и в token попадает у нас данные из каждой ячейки
            switch (i) { // хитрый способ записи в каждый адресс 
            case(0):
                strcpy((lib + j)->zach, token);
                break;
            case(1):
                strcpy((lib + j)->fam, token);
                break;
            case(2):
                strcpy((lib + j)->name, token);
                break;
            case(3):
                strcpy((lib + j)->fath, token);
                break;
            case(4):
                strcpy((lib + j)->fak, token);
                break;
            case(5):
                strcpy((lib + j)->spec, token);
                break;
            }
        
            token = strtok(NULL, ";");
        }
    }
    // Закрытие файла
    fclose(file2);
    printf("Файл закрыт\n"); // На этом моменте у нас есть структура
    // ***
    
    printf("\n******************************");
    printf("\nВыберите, что вы хотите сделать:\n");
    printf("0 - Завершить работу программы.\n");
    printf("1 - Добавить студента.\n");
    printf("2 - Удалить студента по номеру зачетной книжки.\n");
    printf("3 - Редактировать информацию по студенту.\n");
    printf("4 - Просмотреть информацию по студенту по номеру зачетной книжки.\n");
    printf("5 - Сделать бэкап.\n");
    printf("6 - Восстановить базу из файла бэкапа.\n");
    printf("7 - Поиск по фамилии студента.\n");
    printf("******************************\n");

    int chek = 1, vspom, vspom1, vspom2;
    char ss[20] = "";
    while (chek != 0) {
        vspom = 1;
        printf("\n >> ");  scanf_s("%d", &chek);
        switch (chek) {
        case(0):
            return 0;
            break;
        case(1):
            printf("Введите номер зачётки: "); gets(ss);
            fgets(ss, 20, stdin);
            for (int k = 0; k < 20; k++)
                if (ss[k] == '\n') {
                    ss[k] = '\0';
                    break;
                }
            fflush(stdin); // очищаем поток ввода

            for (int i = 0; i < n; i++)
                libvspom = (struct students*)malloc((n) * sizeof(struct students));
                for (int i = 0; i < n != NULL; i++) {
                    strcpy((libvspom + i)->zach, (lib + i)->zach);
                    strcpy((libvspom + i)->fam, (lib + i)->fam);
                    strcpy((libvspom + i)->name, (lib + i)->name);
                    strcpy((libvspom + i)->fath, (lib + i)->fath);
                    strcpy((libvspom + i)->fak, (lib + i)->fak);
                    strcpy((libvspom + i)->spec, (lib + i)->spec);
                }
                lib = (struct students*)malloc((n + 1) * sizeof(struct students)); // расширяем нашу главную структуру
                // копируем обратно
                for (int i = 0; i < n != NULL; i++) {
                    strcpy((lib + i)->zach, (libvspom + i)->zach);
                    strcpy((lib + i)->fam, (libvspom + i)->fam);
                    strcpy((lib + i)->name, (libvspom + i)->name);
                    strcpy((lib + i)->fath, (libvspom + i)->fath);
                    strcpy((lib + i)->fak, (libvspom + i)->fak);
                    strcpy((lib + i)->spec, (libvspom + i)->spec);
                }
                strcpy((lib + n)->zach, ss);
                    
                printf("Введите фамилию: "); gets((lib + n)->fam);
                printf("Введите имя: "); gets((lib + n)->name);
                printf("Введите очество: "); gets((lib + n)->fath);
                printf("Введите факультет: "); gets((lib + n)->fak);
                printf("Введите специальность: "); gets((lib + n)->spec);
                n++;
                vspom = 1;
                break;
        case(11):
            for (int i = 0; i < n; i++)   
                printf("%s %s %s %s %s %s\n", (lib + i)->zach, (lib + i)->fam, (lib + i)->name, (lib + i)->fath, (lib + i)->fak, (lib + i)->spec);
            break;
        case(2):
            printf("Введите номер зачётки: "); gets(ss);
            fgets(ss, 20, stdin);
            for (int k = 0; k < 20; k++)
                if (ss[k] == '\n') {
                    ss[k] = '\0';
                    break;
                }
            fflush(stdin); // очищаем поток ввода

            for (int i = 0; i < n; i++)
                if (strncmp(ss, (lib + i)->zach, strlen(ss)) == 0) {
                    printf("Будет удалён студент: %s\n", (lib + i)->name);
                    vspom = i;
                    for (int i = 0; i < vspom; i++) {
                        strcpy((libvspom + i)->zach, (lib + i)->zach);
                        strcpy((libvspom + i)->fam, (lib + i)->fam);
                        strcpy((libvspom + i)->name, (lib + i)->name);
                        strcpy((libvspom + i)->fath, (lib + i)->fath);
                        strcpy((libvspom + i)->fak, (lib + i)->fak);
                        strcpy((libvspom + i)->spec, (lib + i)->spec);
                    }
                    for (int i = vspom + 1; i < n; i++) {
                        strcpy((libvspom + i-1)->zach, (lib + i)->zach);
                        strcpy((libvspom + i-1)->fam, (lib + i)->fam);
                        strcpy((libvspom + i-1)->name, (lib + i)->name);
                        strcpy((libvspom + i-1)->fath, (lib + i)->fath);
                        strcpy((libvspom + i-1)->fak, (lib + i)->fak);
                        strcpy((libvspom + i-1)->spec, (lib + i)->spec);
                    }
                    lib = (struct students*)malloc((n - 1) * sizeof(struct students)); // расширяем нашу главную структуру
                    // копируем обратно
                    n--;
                    for (int i = 0; i < n != NULL; i++) {
                        strcpy((lib + i)->zach, (libvspom + i)->zach);
                        strcpy((lib + i)->fam, (libvspom + i)->fam);
                        strcpy((lib + i)->name, (libvspom + i)->name);
                        strcpy((lib + i)->fath, (libvspom + i)->fath);
                        strcpy((lib + i)->fak, (libvspom + i)->fak);
                        strcpy((lib + i)->spec, (libvspom + i)->spec);
                    }
                }
            break;
        case(3):
            printf("Введите номер зачётки: "); gets(ss);
            fgets(ss, 20, stdin);
            for (int k = 0; k < 20; k++)
                if (ss[k] == '\n') {
                    ss[k] = '\0';
                    break;
                }
            fflush(stdin); // очищаем поток ввода
            vspom = 0;
            for (int i = 0; i < n; i++)
                if (strncmp(ss, (lib + i)->zach, strlen(ss)) == 0) {
                    strcpy((lib + i)->zach, ss);
                    printf("Введите фамилию: "); gets((lib + i)->fam);
                    printf("Введите имя: "); gets((lib + i)->name);
                    printf("Введите очество: "); gets((lib + i)->fath);
                    printf("Введите факультет: "); gets((lib + i)->fak);
                    printf("Введите специальность: "); gets((lib + i)->spec);
                    vspom = 1;
                    break;
                }
            if (vspom == 0)
                printf("У нас нет такого студента.\n");
            break;
        case(4):
            printf("Введите номер зачётки: "); gets(ss);
            fgets(ss, 20, stdin);
            for (int k = 0; k < 20; k++)
                if (ss[k] == '\n') {
                    ss[k] = '\0';
                    break;
                }
            fflush(stdin); // очищаем поток ввода
            vspom = 0;
            for (int i = 0; i < n; i++)
                if (strncmp(ss, (lib + i)->zach, strlen(ss)) == 0) {
                    printf("%s %s %s %s %s %s\n", (lib + i)->zach, (lib + i)->fam, (lib + i)->name, (lib + i)->fath, (lib + i)->fak, (lib + i)->spec);
                    vspom = 1;
                    break;
                }
            if (vspom == 0)
                printf("У нас нет такого студента.\n");
            break;
        case(5):
            file2 = fopen("students_time1_time2.csv", "w");
            printf("Открытие файла : ");
            // Проверка открытия файла
            if (file2 == NULL) printf("ошибка\n");
            else printf("выполнено\n");
            for (int i = 0; i < n; i++) {
                fprintf(file2, "%s;%s;%s;%s;%s;%s\n", (lib + i)->zach, (lib + i)->fam, (lib + i)->name, (lib + i)->fath, (lib + i)->fak, (lib + i)->spec);
            }
            fclose(file2);
            break;
        case(6):
            lib = (struct books*)malloc((1) * sizeof(struct students));
            libvspom = (struct books*)malloc(1 * sizeof(struct students));
            for (int j = 0; fgets(line, sizeof(line), file2); j++) { // идём по всему списку
                if (j != 0) { // тут мы будем расширять динамическую структуру
                    // копируем во второй
                    libvspom = (struct books*)malloc((j) * sizeof(struct students));
                    for (int i = 0; i < j != NULL; i++) {
                        strcpy((libvspom + i)->zach, (lib + i)->zach);
                        strcpy((libvspom + i)->fam, (lib + i)->fam);
                        strcpy((libvspom + i)->name, (lib + i)->name);
                        strcpy((libvspom + i)->fath, (lib + i)->fath);
                        strcpy((libvspom + i)->fak, (lib + i)->fak);
                        strcpy((libvspom + i)->spec, (lib + i)->spec);
                    }
                    lib = (struct students*)malloc((j + 1) * sizeof(struct students)); // расширяем нашу главную структуру
                    // копируем обратно
                    for (int i = 0; i < j != NULL; i++) {
                        strcpy((lib + i)->zach, (libvspom + i)->zach);
                        strcpy((lib + i)->fam, (libvspom + i)->fam);
                        strcpy((lib + i)->name, (libvspom + i)->name);
                        strcpy((lib + i)->fath, (libvspom + i)->fath);
                        strcpy((lib + i)->fak, (libvspom + i)->fak);
                        strcpy((lib + i)->spec, (libvspom + i)->spec);
                    }
                }
                n = j + 1;
                token = strtok(line, ";"); // отыскиваем всю информацию между точке с запятыми
                for (int i = 0; token != NULL; i++) { // теперь идём по строке и в token попадает у нас данные из каждой ячейки
                    switch (i) { // хитрый способ записи в каждый адресс 
                    case(0):
                        strcpy((lib + j)->zach, token);
                        break;
                    case(1):
                        strcpy((lib + j)->fam, token);
                        break;
                    case(2):
                        strcpy((lib + j)->name, token);
                        break;
                    case(3):
                        strcpy((lib + j)->fath, token);
                        break;
                    case(4):
                        strcpy((lib + j)->fak, token);
                        break;
                    case(5):
                        strcpy((lib + j)->spec, token);
                        break;
                    }

                    token = strtok(NULL, ";");
                }
            }
            // Закрытие файла
            fclose(file2);
            printf("Файл закрыт\n"); // На этом моменте у нас есть структура
            // ***
            break;
        case(7):
            printf("Введите студента: ");
            gets(ss);
            fgets(ss, 20, stdin);
            for (int k = 0; k < 20; k++)
                if (ss[k] == '\n') {
                    ss[k] = '\0';
                    break;
                }
            fflush(stdin); // очищаем поток ввода
            vspom = 0;
            for (int i = 0; i < n; i++)
                if (strncmp(ss, (lib + i)->fam, strlen(ss)) == 0) {
                    printf("%s %s %s %s %s %s\n", (lib + i)->zach, (lib + i)->fam, (lib + i)->name, (lib + i)->fath, (lib + i)->fak, (lib + i)->spec);                    
                    vspom = 1;
                }
            if (vspom == 0)
                printf("У нас нет такого студента\n");
            break;
        }
    }
    // выводит всех студентов 

}


int BookPeople() {
    // ***
    char line[1024]; // В этой строке будут лежать данные о всём файле
    char* token; // это переводвая переменная
    FILE* file1 = fopen("book.csv", "r");
    printf("Открытие файла : ");
    // Проверка открытия файла
    if (file1 == NULL) printf("ошибка\n");
    else printf("выполнено\n");
    // тут всё работает так, что мы можем считывать строки из excel и самое главное по количеству написанного в excel.будь то 100000 строк или 1 строка
    struct books* lib;
    struct books* libvspom;
    int n,time1=0,time2=0;
    lib = (struct books*)malloc((1) * sizeof(struct books));
    libvspom = (struct books*)malloc(1 * sizeof(struct books));
    for (int j = 0; fgets(line, sizeof(line), file1); j++) { // идём по всему списку
        if (j!=0) { // тут мы будем расширять динамическую структуру
            // копируем во второй
            libvspom = (struct books*)malloc((j) * sizeof(struct books));
            for (int i = 0; i < j != NULL; i++) {
                (libvspom + i)->isbn=(lib + i)->isbn;
                strcpy((libvspom + i)->fio , (lib + i)->fio);
                strcpy((libvspom + i)->name , (lib + i)->name);
                (libvspom + i)->all = (lib + i)->all;
                (libvspom + i)->dostup = (lib + i)->dostup;
            }
            lib = (struct books*)malloc((j+1) * sizeof(struct books)); // расширяем нашу главную структуру
            // копируем обратно
            for (int i = 0; i < j != NULL; i++) {
                (lib + i)->isbn = (libvspom + i)->isbn;
                strcpy((lib + i)->fio, (libvspom + i)->fio);
                strcpy((lib + i)->name, (libvspom + i)->name);
                (lib + i)->all = (libvspom + i)->all;
                (lib + i)->dostup = (libvspom + i)->dostup;
            }
        }
        n = j + 1;
        token = strtok(line, ";"); // отыскиваем всю информацию между точке с запятыми
        for (int i = 0; token != NULL; i++) { // теперь идём по строке и в token попадает у нас данные из каждой ячейки
            switch (i) { // хитрый способ записи в каждый адресс 
            case(0):
                strcpy(token, token);
                (lib + j)->isbn = atoi(token);
                break;
            case(1):
                strcpy((lib + j)->fio , token);
                break;
            case(2):
                strcpy((lib + j)->name , token);
                break;
            case(3):
                strcpy(token, token);
                (lib + j)->all = atoi(token);
                break;
            case(4):
                strcpy(token, token);
                (lib + j)->dostup = atoi(token);
                break;
            }
            token = strtok(NULL, ";");
        }
    }
    // Закрытие файла
    fclose(file1);
    printf("Файл закрыт\n"); // На этом моменте у нас есть структура
    // ***
    printf("\n******************************");
    printf("\nВыберите, что вы хотите сделать:\n");
    printf("0 - Завершить работу программы.\n");
    printf("1 - Добавить новую книгу.\n");
    printf("2 - Удалить книгу по номеру ISBN.\n");
    printf("3 - Просмотр всей информации по книге.\n");
    printf("4 - Вывести информацию по всем книгам в виде таблицы.\n");
    printf("5 - Редактировать информацию по книге.\n");
    printf("6 - Изменить количество книг в библиотеке по номеру ISBN.\n");
    printf("7 - Выдать книгу студенту по номеру ISBN.\n");
    printf("8 - Принять книгу от студента по номеру ISBN.\n");
    printf("9 - Сделать бэкап.\n");
    printf("10 - Восстановить базу из файла бэкапа.\n");
    printf("11 - Поиск по фамилии автора.\n");
    printf("******************************\n");
    int chek=1,vspom,vspom1,vspom2;
    char ss[20] = "";
    while (chek!=0) {
        vspom = 1;

        printf("\n >> ");  scanf_s("%d", &chek);
        switch (chek) {
        case(0):
            return 0;
            break;
        case(1):
            printf("Введите ISBN: ");
            scanf_s("%d", &vspom1);
            for (int i = 0; i < n; i++) 
                if ((lib + i)->isbn== vspom1) {
                    printf("Книга с таким ISBN существует.\n");
                    vspom = 0;
                }
            if (vspom!=0) {
                libvspom = (struct books*)malloc((n) * sizeof(struct books));
                for (int i = 0; i < n != NULL; i++) {
                    (libvspom + i)->isbn = (lib + i)->isbn;
                    strcpy((libvspom + i)->fio, (lib + i)->fio);
                    strcpy((libvspom + i)->name, (lib + i)->name);
                    (libvspom + i)->all = (lib + i)->all;
                    (libvspom + i)->dostup = (lib + i)->dostup;
                }
                lib = (struct books*)malloc((n + 1) * sizeof(struct books)); // расширяем нашу главную структуру
                // копируем обратно
                for (int i = 0; i < n != NULL; i++) {
                    (lib + i)->isbn = (libvspom + i)->isbn;
                    strcpy((lib + i)->fio, (libvspom + i)->fio);
                    strcpy((lib + i)->name, (libvspom + i)->name);
                    (lib + i)->all = (libvspom + i)->all;
                    (lib + i)->dostup = (libvspom + i)->dostup;
                }
                (lib + n)->isbn = vspom1;
                printf("Введите ФИО: "); gets((lib + n)->fio); 
                fgets((lib + n)->fio, 20, stdin);
                for (int k = 0; k < 20; k++) 
                    if ((lib + n)->fio[k]== '\n') {
                        (lib + n)->fio[k] = '\0';
                        break;
                    }
                fflush(stdin); // очищаем поток ввода
                printf("Введите название: "); gets((lib + n)->name);
                printf("Введите колличество: "); scanf_s("%d", &(lib + n)->all); 
                printf("Введите доступные: "); scanf_s("%d", &(lib + n)->dostup);
                n++;
            }
            break;
        case(2):
            printf("Введите ISBN для удаления: ");
            scanf_s("%d", &vspom1);
            for (int i = 0; i < n; i++)
                if ((lib + i)->isbn == vspom1) {
                    printf("Будет удалена книга: %s\n", (lib + i)->name);
                    vspom = i;
                    for (int i = 0; i < vspom; i++) {
                        (libvspom + i)->isbn = (lib + i)->isbn;
                        strcpy((libvspom + i)->fio, (lib + i)->fio);
                        strcpy((libvspom + i)->name, (lib + i)->name);
                        (libvspom + i)->all = (lib + i)->all;
                        (libvspom + i)->dostup = (lib + i)->dostup;
                    }
                    for (int i = vspom+1; i < n; i++) {
                        (libvspom + i-1)->isbn = (lib + i)->isbn;
                        strcpy((libvspom + i-1)->fio, (lib + i)->fio);
                        strcpy((libvspom + i-1)->name, (lib + i)->name);
                        (libvspom + i-1)->all = (lib + i)->all;
                        (libvspom + i-1)->dostup = (lib + i)->dostup;
                    }
                    lib = (struct books*)malloc((n - 1) * sizeof(struct books)); // расширяем нашу главную структуру
                    // копируем обратно
                    n--;
                    for (int i = 0; i < n != NULL; i++) {
                        (lib + i)->isbn = (libvspom + i)->isbn;
                        strcpy((lib + i)->fio, (libvspom + i)->fio);
                        strcpy((lib + i)->name, (libvspom + i)->name);
                        (lib + i)->all = (libvspom + i)->all;
                        (lib + i)->dostup = (libvspom + i)->dostup;
                    }
                }
            break;
        case(3):
            printf("Введите ISBN для просмотра информации по ней: ");
            scanf_s("%d", &vspom1);
            vspom = 0;
            for (int i = 0; i < n; i++)
                if ((lib + i)->isbn == vspom1) {
                    printf("%d %s %s %d %d\n", (lib + i)->isbn, (lib + i)->fio, (lib + i)->name, (lib + i)->all, (lib + i)->dostup);
                    vspom = 1;
                    break;
                }
            if (vspom==0)
                printf("Книги с таким ISBN нет.\n");
            break;
        case(4):
            for (int i = 0; i < n; i++) {
                printf("%d %s %s %d %d\n", (lib + i)->isbn, (lib + i)->fio, (lib + i)->name, (lib + i)->all, (lib + i)->dostup);
            }
            break;
        case(5):
            printf("Введите ISBN для редактирования информации по ней: ");
            scanf_s("%d", &vspom1);
            vspom = 0;
            for (int i = 0; i < n; i++)
                if ((lib + i)->isbn == vspom1) {
                    printf("Введите ISBN: "); scanf_s("%d", &(lib + i)->isbn);
                    printf("Введите ФИО: "); gets((lib + i)->fio);
                    fgets((lib + i)->fio, 20, stdin);
                    for (int k = 0; k < 20; k++)
                        if ((lib + i)->fio[k] == '\n') {
                            (lib + i)->fio[k] = '\0';
                            break;
                        }
                    fflush(stdin); // очищаем поток ввода
                    printf("Введите название: "); gets((lib + i)->name);
                    printf("Введите колличество: "); scanf_s("%d", &(lib + i)->all);
                    printf("Введите доступные: "); scanf_s("%d", &(lib + i)->dostup);
                    vspom = 1;
                    break;
                }
            if (vspom == 0)
                printf("Книги с таким ISBN нет.\n");
            break;
        case(6):
            printf("Введите ISBN для редактирования количества книг в библиотеке по ней: ");
            scanf_s("%d", &vspom1);
            vspom = 0;
            for (int i = 0; i < n; i++)
                if ((lib + i)->isbn == vspom1) {
                    printf("Введите новое колличество: "); scanf_s("%d", &(lib + i)->all);
                    if ((lib + i)->dostup > (lib + i)->all) {
                        (lib + i)->dostup = (lib + i)->all;
                    }
                    vspom = 1;
                    break;
                }
            if (vspom == 0)
                printf("Книги с таким ISBN нет.\n");
            break;
        case(7):
            printf("Введите ISBN для выдачи книги студенту: ");
            scanf_s("%d", &vspom1);
            vspom = 0;
            for (int i = 0; i < n; i++)
                if ((lib + i)->isbn == vspom1) {
                    if ((lib + i)->dostup != 0) 
                        (lib + i)->dostup--;
                    else 
                        printf("Доступных книг нет.\n");
                    vspom = 1;
                    break;
                }
            if (vspom == 0)
                printf("Книги с таким ISBN нет.\n");
            break;
        case(8):
            printf("Введите ISBN для принятия книги от студента: ");
            scanf_s("%d", &vspom1);
            vspom = 0;
            for (int i = 0; i < n; i++)
                if ((lib + i)->isbn == vspom1) {
                    if ((lib + i)->dostup+1 >= (lib + i)->all)
                        printf("Теперьу нас полный комплект этих книг.\n");
                    else
                        (lib + i)->dostup++;
                    vspom = 1;
                    break;
                }
            if (vspom == 0)
                printf("Эта книга не из нашей библиотеки.\n");
            break;
        case(9):
            file1 = fopen("book_time1_time2.csv", "w");
            printf("Открытие файла : ");
            // Проверка открытия файла
            if (file1 == NULL) printf("ошибка\n");
            else printf("выполнено\n");
            for (int i = 0; i < n; i++) {
                fprintf(file1,"%d;%s;%s;%d;%d\n", (lib + i)->isbn, (lib + i)->fio, (lib + i)->name, (lib + i)->all, (lib + i)->dostup);
            }
            fclose(file1);
            break;
        case(10):
            file1 = fopen("book_time1_time2.csv", "r");
            n = 0;
            lib = (struct books*)malloc((1) * sizeof(struct books));
            libvspom = (struct books*)malloc(1 * sizeof(struct books));
            for (int j = 0; fgets(line, sizeof(line), file1); j++) { // идём по всему списку
                if (j != 0) { // тут мы будем расширять динамическую структуру
                    // копируем во второй
                    libvspom = (struct books*)malloc((j) * sizeof(struct books));
                    for (int i = 0; i < j != NULL; i++) {
                        (libvspom + i)->isbn = (lib + i)->isbn;
                        strcpy((libvspom + i)->fio, (lib + i)->fio);
                        strcpy((libvspom + i)->name, (lib + i)->name);
                        (libvspom + i)->all = (lib + i)->all;
                        (libvspom + i)->dostup = (lib + i)->dostup;
                    }
                    lib = (struct books*)malloc((j + 1) * sizeof(struct books)); // расширяем нашу главную структуру
                    // копируем обратно
                    for (int i = 0; i < j != NULL; i++) {
                        (lib + i)->isbn = (libvspom + i)->isbn;
                        strcpy((lib + i)->fio, (libvspom + i)->fio);
                        strcpy((lib + i)->name, (libvspom + i)->name);
                        (lib + i)->all = (libvspom + i)->all;
                        (lib + i)->dostup = (libvspom + i)->dostup;
                    }
                }
                n = j + 1;
                token = strtok(line, ";"); // отыскиваем всю информацию между точке с запятыми
                for (int i = 0; token != NULL; i++) { // теперь идём по строке и в token попадает у нас данные из каждой ячейки
                    switch (i) { // хитрый способ записи в каждый адресс 
                    case(0):
                        strcpy(token, token);
                        (lib + j)->isbn = atoi(token);
                        break;
                    case(1):
                        strcpy((lib + j)->fio, token);
                        break;
                    case(2):
                        strcpy((lib + j)->name, token);
                        break;
                    case(3):
                        strcpy(token, token);
                        (lib + j)->all = atoi(token);
                        break;
                    case(4):
                        strcpy(token, token);
                        (lib + j)->dostup = atoi(token);
                        break;
                    }
                    token = strtok(NULL, ";");
                }
            }
            break;
        case(11):
            printf("Введите автора: ");
            gets(ss);
            fgets(ss, 20, stdin);
            for (int k = 0; k < 20; k++)
                if (ss[k] == '\n') {
                    ss[k] = '\0';
                    break;
                }
            fflush(stdin); // очищаем поток ввода
            vspom = 0;
            for (int i = 0; i < n; i++)
                if (strncmp(ss, (lib + i)->fio, strlen(ss)) == 0) {
                    printf("%d %s %s %d %d\n", (lib + i)->isbn, (lib + i)->fio, (lib + i)->name, (lib + i)->all, (lib + i)->dostup);
                    vspom = 1;
                }
            if (vspom == 0)
                printf("У нас нет такого автора\n");
            break;

        }
    }


}


int main() {
    setlocale(LC_ALL, "Rus");
   // Переменная, в которую будет сохранен указатель
   // на управляющую таблицу открываемого потока данных
    FILE* file = fopen("users.csv", "r");
    printf("Открытие файла : ");
    // Проверка открытия файла
    if (file == NULL) printf("ошибка\n");
    else printf("выполнено\n");

    char line[1024]; // В этой строке будут лежать данные о всём файле
    char* token; // это переводвая переменная
    struct person people[10]; // структура данных пользователей 
    for (int j = 0; fgets(line, sizeof(line), file); j++) { // идём по всему списку
        token = strtok(line, ";"); // отыскиваем всю информацию между точке с запятыми
        for (int i = 0; token != NULL; i++) { // теперь идём по строке и в token попадает у нас данные из каждой ячейки
            switch (i) { // хитрый способ записи в каждый адресс 
            case(0):
                strcpy(people[j].name , token);
                break;
            case(1):
                strcpy(people[j].pass, token);
                break;
            case(2):
                strcpy(token, token);
                people[j].one = atoi(token);
                break;
            case(3):
                strcpy(token, token);
                people[j].two = atoi(token);
                break;
            }
            token = strtok(NULL, ";");
        }
    }
    // Закрытие файла
    fclose(file);
    printf("\nФайл закрыт\n");


    //input(people, sizeof(people) / sizeof(people[0])); //теперь выведем всю информацию про пользователей. в параметре сама структура и кол-во объектов структуре.
    
   

    
    // теперь у нас доступны структуры и мы можем работать с ними

    /*
    admin qe 1 1
    user1 eg 1 0
    user2 er 0 1
    */


    int klient; // id клиента, который будет работатьс меню.
    while (LogIn(people, sizeof(people) / sizeof(people[0]), &klient) == 0) { printf("Не верно!!!\n"); } // Задание 1 ввод логина и пароля
    printf("Поздравляю, %s. Вы авторизировались.\n", people[klient].name);
    printf("Вот небольшаяинформация о Ваших правах: ");
    if (people[klient].two == 1)
        printf("Вы можете редактировать книги.  ");
    else
        printf("Вы не можете редактировать книги.  ");
    if (people[klient].one == 1)
        printf("Вы можете редактировать студентов.\n");
    else
        printf("Вы не можете редактировать студентов.\n");
    
    int chek;
    if (people[klient].two == 1&& people[klient].one == 1) { // права бога
        while (1) {
        printf("\nВы админ в системе.\n1 - редактировать студентов. 2 - редактировать книги.\nВыберите, что вы хотите сделать: ");
        scanf_s("%d",&chek);
            if (chek==1) {
                printf("Вы выбрали меню редактирования студентов.\n");
                StudPeople();
            }
            else if(chek==2) {
                printf("Вы выбрали меню редактирования книг.\n");
                BookPeople();
            }
        }
    } else if (people[klient].two == 0 && people[klient].one == 1) { // доступ для редактирования студентов задание 3
        printf("\nВам доступно редактирование книг.\n");
        BookPeople();
    } else if (people[klient].two == 1 && people[klient].one == 0) { // доступ для редактирования книг. задание 2
        printf("\nВам доступно редактирование студентов.\n");
        StudPeople();
    }


    return 0;
}

int LogIn(struct person people[], int n, int* klient) {
    char str[10], str1[10];
    system("cls");
    printf("Введите логин: ");
    gets(str);
    printf("Введите пароль: ");
    gets(str1);
    for (int i = 0; i < n; i++)
        if (strncmp(str, people[i].name, strlen(str)) == 0)
            if (strcmp(str1, people[i].pass, strlen(str1)) == 0) {
                *klient = i;
                return 1;
            }
    return 0;
}
