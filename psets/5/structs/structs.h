
struct skill
{
    char name[10];
    int level;
};

typedef struct
{
    int age;
    char name[10];
}
employee;

typedef struct
{
    int year;
    char model[10];
    char plate[8];
    int odometer;
    double engine_size;
}
vehicle;

// temporary typename 'sllist'
// used to self reference the node
typedef struct sllist
{
    int number;
    struct sllist* next;
}
sllnode;

