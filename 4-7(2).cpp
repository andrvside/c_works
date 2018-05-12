#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

typedef struct good {
    string name; // имя
    long int artical; // артикул
    int count; // количество
    double price; // цена
    unsigned short int sale; // скидка
} good;

// Создание новой БД
void array_new_bd ( int n, good about[])
{
    for (int i = 0; i < n; i++){
        cout << "Наименование: ";
        cin >> about[ i ].name;
        cout << "Артикул: ";
        cin >> about[ i ].artical;
        cout << "Колличество: ";
        cin >> about[ i ].count;
        cout << "Цена: ";
        cin >> about[ i ].price;
        cout << "Скидка: ";
        cin >> about[ i ].sale;
    }
};

// Поиск по артиклю
void array_find_artical ( int l, int n, good about[])
{
    cout << "Введите артикул";
    cin >> l;
    for (int s = 0; s < n; s++) {
        if (about[ s ].artical == l)
        {
            cout << about[ s ].name << " | " << about[ s ].artical << " | " << about[ s ].count << " | " << about[ s ].price << " | " << about[ s ].sale << endl;
            // ДОПИЛИТЬ ПЕРЕЗАПИСЬ ДАННЫХ, ПОСЛЕ ТОГО КАК ДАНЯ ПРИШЛЕТ КНОПКИ
            // УДАЛЕНИЕ ПОЗИЦИЙ
        }
    }
};

// Вывод на экран в фотмате
// Наименование Артикль Количество Цена Скидка
void array_print ( int n, good about[])
{
    for (int j = 0; j < n; j++) {
        cout << about[ j ].name << " | " << about[ j ].artical << " | " << about[ j ].count << " | " << about[ j ].price << " | " << about[ j ].sale << endl;
    }
};

// Вывод товаров со скидкой
void array_sale ( int n, good about[])
{
    for (int r = 0; r < n; r++) {
        if (about[ r ].sale > 0)
        {
            cout << about[ r ].name << " | " << about[ r ].artical << " | " << about[ r ].count << " | " << about[ r ].price << " | " << about[ r ].sale << endl;
        }
    }
};

// Вывод товаров, которых нет в наличии
void array_count ( int n, good about[])
{
    for (int l = 0; l < n; l++) {
        if (about[ l ].count == 0)
        {
            cout << about[ l ].name << " | " << about[ l ].artical << " | " << about[ l ].count << " | " << about[ l ].price << " | " << about[ l ].sale << endl;
        }
    }
};

void print_menu() {
    printf("1. Создать БД\n");
    printf("2. Вывести все позиции\n");
    printf("3. Добавить позицию\n");
    printf("4. Поиск позиции по артикулу\n");
    printf("5. Вывести все позиции со скидкой\n");
    printf("6. Вывести все позиции, которых нет в наличии\n");
    printf("7. Отсортировать все позиции по указанному полю\n");
    printf("8. Сохранить БД\n");
    printf("9. Выход\n");
    printf(">");
}

void print_main_menu() {
    printf("1. Создать БД\n");
    printf("2. Загрузить данные\n");
    printf("3. Выход\n");
    printf(">");
}

int get_variant(int count) {
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Некорректный ввод. Попробуйте еще раз: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }
    return variant;
}

int main() {
    FILE *base;
    setlocale(LC_ALL, "russian");
    int variant; // выбранный пункт меню
    int variant_0; // выбранный пункт меню
    int capacity = 1;
    int col;
    struct good pdr;
    good *pdr1 = new good;
    good about[col];
    good *goods = (good *)malloc(capacity * sizeof(good)); // выделяем память под массив
    
    // ПЕРВОЕ МЕНЮ
    print_main_menu();
    variant_0 = get_variant(3);
    switch (variant_0)
    {
        case 1:
            base = fopen("/Users/andrvdnl/Desktop/base.dat", "wb");
            cout << "Введите колличество позиций: ";
            cin >> col;
            array_new_bd(col, about);
            fclose(base);
            break;
            
        case 2:
            break;
    }

    // ОСНОВНОЕ МЕНЮ
    if (variant_0 != 3) { // чтобы работала кнопка выхода в первом меню
    do {
        print_menu(); // выводим меню на экран
        
        variant = get_variant(9); // получаем номер выбранного пункта меню
        
        switch (variant) {
            case 1:
                base = fopen("/Users/andrvdnl/Desktop/base.dat", "wb");
                cout << "Введите колличество позиций: ";
                cin >> col;
                array_new_bd(col, about);
                fclose(base);
                break;
                
            case 2:
                array_print(col, about);
                break;
                
            case 3:
                break;
                
            case 4:
                break;
                
            case 5:
                break;
                
            case 6:
                break;
                
            case 7:
                break;
                
            case 8:
                break;
        }
        
        if (variant != 9)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 9);
    }
    return 0;
}
