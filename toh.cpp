#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MAX 64
using namespace std;

int st[3][MAX];
int top[3] = {-1,-1,-1};
int siz;
int no_digs;
char ch[3] = {'A', 'B', 'C'};

void push(int in, int item)
{
    top[in]++;
    st[in][top[in]] = item;
}

int pop(int in)
{
    int item = st[in][top[in]];
    top[in]--;
    return item;
}

void clrscr()
{
    system("@cls||clear");
}

void sleepcp(int milliseconds);

void sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}

void print()
{
    sleepcp(1000);// CHANGE THE VALUE OF SLEEP TIME BY CHANGING THE ARGUEMENT VALUE OF THE FUNCTION
    clrscr();
    for (int i = siz;i >= 0;i--) {
        for (int j = 0;j < 3;j++) {
            if(i <= top[j]){
                int no_rem = no_digs-to_string(st[j][i]).size();
                string first_spaces(no_rem/2, ' ');
                string second_spaces(no_rem/2+no_rem%2+2, ' ');
                cout << first_spaces << st[j][i] << second_spaces;
            }
            else{
                string spaces(no_digs+2, ' ');
                cout << spaces;
            }
        }
        cout << endl;
    }
    string first_spaces((no_digs-1)/2, ' ');
    string second_spaces((no_digs-1)/2+(no_digs-1)%2+2, ' ');
    cout << first_spaces << 'A' << second_spaces+first_spaces << 'B' << second_spaces+first_spaces << 'C' << "\n\n";
}

void move(int n, int source, int dest, int spare)
{

    if (n == 1) {
        push(dest, pop(source));
        print();
        cout << "Move from " << ch[source] << " to " << ch[dest] << " ";
    }
    else {
        move(n - 1, source, spare, dest);
        move(1, source, dest, spare);
        move(n - 1, spare, dest, source);
    }
}

int main()
{
    cout << "Enter the size of the tower: ";
    cin >> siz;
    no_digs = to_string(siz).size();
    for(int i = 0;i < siz;i++) {
        st[0][i] = siz - i;
    }
    top[0] = siz - 1;
    print();
    move(siz, 0, 2, 1);
    print();
    return 0;
}
