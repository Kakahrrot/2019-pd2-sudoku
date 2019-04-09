#include "sudoku.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Clock.h"

using namespace std;


void Sudoku::solve_plus() {
    Clock clc;
    int *m = (int *)map;
    int *p = new int[size * size];
    int tmp[size][size];
    int t = 0, flag = 0, start;
    int n = -1, ans = 0;
    //replace  int total = get_position(p)
    int total = 0;
    for(int j = 0; j < size * size; j++)
        if(m[j] == 0)
            p[total++] = j;
    clc.start();
    while(1) {
        if(clc.getTime() > 25) {
            ans ? ans = 2 : ans = 0;
            break;
        }
        if(!flag) {
            n++;
            start = 1;
        } else {
            n--;
            if(m[p[n]] != size) {
                start = m[p[n]] + 1;
                flag = 0;
            } else {
                m[p[n]] = 0;
                if(n == 0) // additional terminating contition
                    break;
                continue;
            }
        }
        int row = p[n] / size, col = p[n] % size;
        for(t = start; n != total && t <= size; t++) {
            //replace check(...);
            int i,j;
            bool check = true;
            for(i = 0; i < size; i++)
                if(map[i][col] == t) {
                    check = false;
                    break;
                }
            if(check) {
                for(j = 0; j < size; j++)
                    if(map[row][j] == t) {
                        check = false;
                        break;
                    }
            }
            if(check) {
                i = row - row % 3;
                j = col - col % 3;
                int (*a)[size] = (int(*)[size])&map[i][j];
                for(i = 0; i < 3; i++) {
                    for(j = 0; j < 3; j++) {
                        if((*a)[j] == t ) {
                            check = false;
                            break;
                        }
                    }
                    a++;
                }
            }
            if(check) {
                m[p[n]] = t;
                break;
            }
        }
        if(n == total) {
            ans++;
            if(ans == 1) {
                for(int i = 0; i < size; i++)
                    for(int j = 0; j < size; j++)
                        tmp[i][j] = map[i][j];
            }
            if(ans == 2)
                break;
            flag = 1;
        } else if(t == size + 1) {
            m[p[n]] = 0;
            if(n == 0)
                break;
            flag = 1;
        }
    }
    switch(ans) {
    case 0:
    case 2:
        cout << ans << "\n";
        break;
    case 1:
        cout << ans << "\n";
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size - 1; j++)
                cout << tmp[i][j] <<" ";
            cout << tmp[i][size - 1] << "\n";
        }
        break;
    }
    delete p;
}

void Sudoku::solve_inverse() {
    int *m = (int *)map;
    int *p = new int[size * size];
    int tmp[size][size];
    int t = 0, flag = 0, start;
    int n = -1, ans = 0;
    int total = get_position(p);
    while(1) {
        if(!flag) {
            n++;
            start = 9;
        } else {
            n--;
            if(m[p[n]] != 1) {
                start = m[p[n]] - 1;
                flag = 0;
            } else {
                m[p[n]] = 0;
                if(n == 0) // additional terminating contition
                    break;
                continue;
            }
        }
        for(t = start; n != total && t >= 1; t--) {
            if( check(p[n]/size, p[n]%size, t) ) {
                m[p[n]] = t;
                break;
            }
        }
        if(n == total) {
            ans++;
            if(ans == 1) {
                for(int i = 0; i < size; i++)
                    for(int j = 0; j < size; j++)
                        tmp[i][j] = map[i][j];
                break;
            }
            if(ans == 2)
                break;
            flag = 1;
        } else if(t == 0) {
            m[p[n]] = 0;
            if(n == 0)
                break;
            flag = 1;
        }
    }
    switch(ans) {
    case 0:
    case 2:
        cout << ans << "\n";
        break;
    case 1:
        cout << ans << "\n";
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size - 1; j++)
                cout << tmp[i][j] <<" ";
            cout << tmp[i][size - 1] << "\n";
        }
        break;
    }
    delete p;
}

void Sudoku::solve(int rotate_time) {
    int *m = (int *)map;
    int *p = new int[size * size];
    int tmp[size][size];
    int t = 0, flag = 0, start;
    int n = -1, ans = 0;
    int total = get_position(p);
    while(1) {
        if(!flag) {
            n++;
            start = 1;
        } else {
            n--;
            if(m[p[n]] != size) {
                start = m[p[n]] + 1;
                flag = 0;
            } else {
                m[p[n]] = 0;
                if(n == 0) // additional terminating contition
                    break;
                continue;
            }
        }
        for(t = start; n != total && t <= size; t++) {
            if( check(p[n]/size, p[n]%size, t) ) {
                m[p[n]] = t;
                break;
            }
        }
        if(n == total) {
            ans++;
            if(ans == 1) {
                if(rotate_time)
                    rotate(rotate_time);
                for(int i = 0; i < size; i++)
                    for(int j = 0; j < size; j++)
                        tmp[i][j] = map[i][j];
                if(rotate_time)
                    rotate(4 - rotate_time);
                //	break;
            }
            if(ans == 2)
                break;
            flag = 1;
        } else if(t == size + 1) {
            m[p[n]] = 0;
            if(n == 0)
                break;
            flag = 1;
        }
    }
    switch(ans) {
    case 0:
    case 2:
        cout << ans << "\n";
        break;
    case 1:
        cout << ans << "\n";
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size - 1; j++)
                cout << tmp[i][j] <<" ";
            cout << tmp[i][size - 1] << "\n";
        }
        break;
    }
    delete p;
}

int Sudoku::optimize() {
    int row, col, pos, a[2][4] = {0};
    int total;
    int *m = (int*)map;
    for(total = 0, pos = 0; m[pos] != 0; total++, pos++);
    row = pos / 9;
    col = pos % 9;
    for(int i = 1; i <= size; i++)
        if(check(row, col, i))
            a[0][0]++;
    a[1][0] = total;
    for(total = 0,pos = size - 1; m[pos] != 0; total++, pos+=size);
    row = pos / 9;
    col = pos % 9;
    for(int i = 1; i <= size; i++)
        if(check(row, col, i))
            a[0][1]++;
    a[1][1] = total;
    for(total = 0, pos = size * size - 1; m[pos] != 0; total++, pos--);
    row = pos / 9;
    col = pos % 9;
    for(int i = 1; i <= size; i++)
        if(check(row, col, i))
            a[0][2]++;
    a[1][2] = total;
    for(total = 0, pos = size * (size- 1); m[pos] != 0; total++, pos-=size);
    row = pos / 9;
    col = pos % 9;
    for(int i = 1; i <= size; i++)
        if(check(row, col, i))
            a[0][3]++;
    a[1][3] = total;
    pos = 0;//in case that it doesn't go into the if statement
    int t = a[1][0];
    for(int i = 0; i < 4; i++)
        if(a[1][i] > t) {
            pos = i;
            t = a[1][i];
        }
    for(int i = 0; i < 4; i++)
        if(a[1][i] == a[1][pos] && a[0][i] < a[0][pos])
            pos = i;
    if(pos!=0)
        rotate(4 - pos);
    return pos;
}

int Sudoku::get_position(int *p) { //set zero
    int *m = (int*)map;
    int i = 0;
    for(int j = 0; j < size * size; j++)
        if(m[j] == 0)
            p[i++] = j;
    return  i;
}

int Sudoku::get_position() { //first zero
    int *m = (int*)map;
    int i;
    for(i = 0; i < size * size; i++)
        if(m[i] == 0)
            return i;
}

void Sudoku::flip(int x) {
    rotate(x + 4);
}

void Sudoku::rotate(int x) {
    int t[size][size];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            switch(x) {
            case 1:
                t[j][size - 1 - i] = map[i][j];
                break;
            case 2:
                t[size - 1 - i][size - 1 - j] = map[i][j];
                break;
            case 3:
                t[size - 1 - j][i] = map[i][j];
                break;
            case 4://up-down flip
                t[size - 1 - i][j] = map[i][j];
                break;
            case 5://left-right flip
                t[i][size -1 -j] = map[i][j];
                break;
            }
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            map[i][j] = t[i][j];
}

void Sudoku::swapCol(int x, int y) {
    x *= 3;
    y *= 3;
    for(int i = 0; i < size; i++) {
        map[i][x] ^= map[i][y] ^= map[i][x] ^= map[i][y];
        map[i][x+1] ^= map[i][y+1] ^= map[i][x+1] ^= map[i][y+1];
        map[i][x+2] ^= map[i][y+2] ^= map[i][x+2] ^= map[i][y+2];
    }
}

void Sudoku::swapRow(int x, int y) {
    x *= 3;
    y *= 3;
    for(int i = 0; i < size; i++) {
        map[x][i] ^= map[y][i] ^= map[x][i] ^= map[y][i];
        map[x+1][i] ^= map[y+1][i] ^= map[x+1][i] ^= map[y+1][i];
        map[x+2][i] ^= map[y+2][i] ^= map[x+2][i] ^= map[y+2][i];
    }
}

void Sudoku::swapNum(int x, int y) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++) {
            if(map[i][j] == x)
                map[i][j] = y;
            else if (map[i][j] == y)
                map[i][j] = x;
        }
}

void Sudoku:: setmap(int map[][size]) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            this -> map[i][j] = map[i][j];
}

bool Sudoku::check(int row, int col, int n) {
    int i,j;
    for(i = 0; i < size; i++)
        if(map[i][col] == n)
            return false;
    for(j = 0; j < size; j++)
        if(map[row][j] == n)
            return false;
    i = row - row % 3;
    j = col - col % 3;
    int (*t)[size] = (int(*)[size])&map[i][j];
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if((*t)[j] == n )
                return false;
        }
        t++;
    }
    return true;
}

Sudoku Sudoku::generate() {
    Sudoku s;
    //s.print_map();
    srandom(time(NULL));
    int	num1 = random() % 5;//# of grips inserted
    //	cout << num1 << endl;
    int row, col;
    while(num1 > 0) {
        row = random() % size;
        col = random() % size;
        while(!s.map[row][col]) {
            //select the num to insert
            int num2 = random() % size + 1;
            if(s.check(row, col, num2)) {
                s.map[row][col] = num2;
                num1--;
            }
        }
    }
    return s;
}

Sudoku::Sudoku() {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            map[i][j] = 0;
    //print_map();
}

void Sudoku::print_map() {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++)
            cout << map[i][j] <<" ";
        cout << map[i][size - 1] << "\n";
    }
}

