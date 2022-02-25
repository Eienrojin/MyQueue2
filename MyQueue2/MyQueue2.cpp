#include <iostream>

using namespace std;

struct MyQueue
{
    double info;
    MyQueue* next;
} *beginQ, *endQ;

void Create(MyQueue** b, MyQueue** e, double in);
void View(MyQueue* p);
void Delete(MyQueue** p);
void Sort(MyQueue** p);
double calculateAverage(MyQueue* p);
void replaceEvenToAvrg(MyQueue* p, double average);
MyQueue* Add(MyQueue* p, double in);

int main()
{
    int n, answer;
    double in;
    double average = 0;

    while (true)
    {
        cout << "1. Create"
            << "\n2. Add"
            << "\n3. View"
            << "\n4. Delete"
            << "\n5. Calculate average"
            << "\n6. Replace even to average"
            << "\n10. Exit"
            << endl;

        cin >> answer;

        switch (answer)
        {
        default:
            break;
        case 1: case 2:

            if (answer == 1 && beginQ != NULL)
            {
                cout << "You must clear the queue before create a new one" << endl;
                break;
            }

            cout << "Enter a number of elements" << endl;
            cin >> n;

            for (int i = 1; i <= n; i++)
            {
                in = 20 - rand() % 30;
                beginQ = Add(beginQ, in);
            }

            if (answer == 1)
                cout << "Create" << endl;
            else
                cout << "Add " << n << endl;
            break;

        case 3:
            if (!beginQ)
            {
                cout << "Queue is empty!" << endl;
                break;
            }

            cout << "--------Queue---------" << endl;

            View(beginQ);

            break;

        case 4:
            Delete(&beginQ);

            cout << "Memory has cleared" << endl;
            break;

        case 5:

            if (!beginQ)
            {
                cout << "Queue is empty!" << endl;
                break;
            }
            average = calculateAverage(beginQ);
            break;

        case 6:
            if (!beginQ)
            {
                cout << "Queue is empty!" << endl;
                break;
            }
            replaceEvenToAvrg(beginQ, average);

            break;

        case 10:
            if (beginQ != NULL)
                Delete(&beginQ);

            return 0;
        }

        system("pause");
        system("cls");
    }
}

void Create(MyQueue** b, MyQueue** e, double in)
{
    MyQueue* t = new MyQueue;

    t->info = in;
    t->next = NULL;

    if (*b == NULL)
    {
        *b = *e = t;
    }
    else
    {
        (*e)->next = t;
        *e = t;
    }
}

MyQueue* Add(MyQueue* p, double in)
{
    MyQueue* t = new MyQueue;

    t->info = in;
    t->next = p;

    return t;
}

void View(MyQueue* p)
{
    MyQueue* t = p;

    while (t != NULL)
    {
        cout << " " << t->info << endl;
        t = t->next;
    }
}

void Delete(MyQueue** p)
{
    MyQueue* t;

    while (*p != NULL)
    {
         t = *p;
        *p = (*p)->next;
        delete t;
    }
}

double calculateAverage(MyQueue* p)
{
    MyQueue* t = NULL, * t1;

    t1 = p;
    double count = 0;
    double sum = 0;

    do {
        sum += t1->info;
        count++;
        t1 = t1->next;
    } while (t1->next != NULL);

    t = t1;
    count++;
    sum += t->info;

    cout << "Average = " << sum / count << endl;

    return sum / count;
}

void replaceEvenToAvrg(MyQueue* p, double average)
{
    MyQueue* t = NULL, * t1;

    t1 = p;

    do {
        if (fmod(t1->info, 2) == 0.0)
        {
            t1->info = average;
        }
        t1 = t1->next;
    } while (t1->next != NULL);

    t = t1;

    if (fmod(t->info, 2) == 0.0)
        t->info = average;
}