#include <iostream>
#include <algorithm>
#include <Windows.h>

const int MAX_N = 1000;

void sort(int a[], int n) {
    // Вбудована сортування за допомогою std::sort
    std::sort(a, a + n);
}

int min_minutes(int n, int a[]) {
    // Сортуємо тарілки в порядку зростання кількості горішків
    sort(a, n);

    // Ініціалізуємо мінімальну кількість хвилин
    int min_minutes = INT_MAX;

    // Проходимо по всім можливим значенням x
    for (int x = 1; x <= a[n - 1]; ++x) {
        // Розраховуємо кількість хвилин для поточного x
        int minutes = 0;
        for (int i = 0; i < n; ++i) {
            minutes += (a[i] - 1) / x;
        }
        minutes += x;

        // Оновлюємо мінімальну кількість хвилин без використання std::min
        if (minutes < min_minutes) {
            min_minutes = minutes;
        }
    }

    return min_minutes;
}

int main() {
    // Налаштування кодування консолі
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;
    std::cout << "Введіть кількість тарілок: ";
    std::cin >> n;

    int a[MAX_N];
    std::cout << "Введіть кількість горішків у кожній тарілці через пробіл: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int result = min_minutes(n, a);
    std::cout << "Мінімальна кількість хвилин: " << result << std::endl;

    return 0;
}