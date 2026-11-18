#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Перевірка: чи є пара символів "SQ" або "QS"
bool IsPair(char a, char b)
{
    return (a == 'S' && b == 'Q') || (a == 'Q' && b == 'S');
}

// Рекурсивний підрахунок пар "SQ" / "QS"
int Count(const char* str)
{
    if (str[0] == '\0' || str[1] == '\0')   // лишилось менше 2 символів
        return 0;

    if (IsPair(str[0], str[1]))
        return 1 + Count(str + 2);          // пара знайдена - пропускаємо обидва символи

    return Count(str + 1);                  // пари немає - зсуваємось на 1
}

// Рекурсивна побудова нового рядка із заміною пар на "***"
void ChangeRec(const char* s, char* t)
{
    if (*s == '\0')
    {
        *t = '\0';
        return;
    }

    if (IsPair(s[0], s[1]))                 // s[1] безпечний, бо s[0] != '\0'
    {
        t[0] = '*';
        t[1] = '*';
        t[2] = '*';
        ChangeRec(s + 2, t + 3);
    }
    else
    {
        *t = *s;
        ChangeRec(s + 1, t + 1);
    }
}

// Рекурсивне копіювання рядка
void CopyStr(const char* from, char* to)
{
    *to = *from;
    if (*from != '\0')
        CopyStr(from + 1, to + 1);
}

// Заміна кожної пари "SQ" або "QS" на "***"
char* Change(char* str)
{
    size_t len = strlen(str);

    char* tmp = new char[len * 3 / 2 + 1];  // 2 символи -> 3, тому запас більший
    ChangeRec(str, tmp);                    // будуємо результат
    CopyStr(tmp, str);                      // копіюємо в параметр (str вміщає до 150 символів)

    return tmp;
}

int main()
{
    char str[151]; // запас, бо після заміни рядок може стати довшим

    cout << "Enter string:" << endl;
    cin.getline(str, 101);
    cout << "String contained " << Count(str) << " pairs of 'SQ' or 'QS'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // звільняємо пам'ять

    return 0;
}