#include <stdio.h>
#include <string.h>

struct vehicle
{
    int year;
    char model[10];
    char plate[8];
    int odometer;
    double engine_size;
};
typedef struct vehicle car_t;

int main(void)
{
    car_t new_car;
    do
    {
        printf("Enter the cars model: ");
        fgets(new_car.model, 10, stdin);
    }
    while (strcmp(&new_car.model[0], "\n") == 0);

    printf("Car model is : %s\n", new_car.model);
    printf("Enter the cars year: ");
    
    scanf("%i", &new_car.year);
    printf("Car year is : %i\n", new_car.year);
}
