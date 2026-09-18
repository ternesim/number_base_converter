#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    double x;
    int P, k;

    printf("Введите вещественное число x: ");
    scanf("%lf", &x);
    printf("Введите основание P (2-36): ");
    scanf("%d", &P);
    printf("Введите количество знаков k (0-10): ");
    scanf("%d", &k);

    printf("Результат перевода: ");

    if (x < 0) {
        printf("-");
        x = -x;
    }

    double integral_double;
    double fractional = modf(x, &integral_double);
    int integral = (int)integral_double;

    char int_part[100];
    int int_len = 0;

    if (integral == 0) {
        int_part[int_len++] = '0';
    } else {
        while (integral > 0) {
            int remainder = integral % P;
            if (remainder < 10) {
                int_part[int_len++] = '0' + remainder;
            } else {
                int_part[int_len++] = 'A' + (remainder - 10);
            }
            integral /= P;
        }
    }

    for (int i = int_len - 1; i >= 0; i--) {
        printf("%c", int_part[i]);
    }

    if (k > 0) {
        printf(".");

        for (int i = 0; i < k; i++) {
            fractional *= P;

            fractional = modf(fractional, &integral_double);
            integral = (int)integral_double;

            if (integral < 10) {
                printf("%c", '0' + integral);
            } else {
                printf("%c", 'A' + (integral - 10));
            }
        }
    }

    printf("\n");
    return 0;
}
