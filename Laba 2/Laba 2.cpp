//1)
long fibonacci(int iter) {
    int cpos = 1;
    long result = 1;
    long ppos = 1;

    while (cpos < iter) {
        long tempVault = ppos;
        ppos = result;
        result += tempVault;
        cpos++;
    }

    return result;
}
//) С рекурсией
long fibonacciRec(int pos) {
    if (pos <= 1) { return 1; }

    return fibonacciRec(pos - 1) + fibonacciRec(pos - 2);
}
//3) Фрактал Минковского(K = 2)
#include <iostream>
#include <windows.h>

using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
const int moveX = 10, moveY = 10;

void moveRight(float& x, float& y, int& reachX, int& reachY)
{
    reachX += moveX;
    for (x; x < reachX; x += 0.05)
        SetPixel(hdc, x, y, RGB(17, 255, 73));
}

void moveDown(float& x, float& y, int& reachX, int& reachY)
{
    reachY += moveY;
    for (y; y < reachY; y += 0.05)
        SetPixel(hdc, x, y, RGB(255, 17, 17));
}

void moveLeft(float& x, float& y, int& reachX, int& reachY)
{
    reachX -= moveX;
    for (x; x > reachX; x -= 0.05)
        SetPixel(hdc, x, y, RGB(25, 17, 255));
}


void moveUp(float& x, float& y, int& reachX, int& reachY)
{
    reachY -= moveY;
    for (y; y > reachY; y -= 0.05)
        SetPixel(hdc, x, y, RGB(232, 255, 17));
}



void moveRight_1(float& x, float& y, int& reachX, int& reachY)
{
    moveRight(x, y, reachX, reachY);
    moveDown(x, y, reachX, reachY);
    moveRight(x, y, reachX, reachY);
    moveUp(x, y, reachX, reachY);
    moveUp(x, y, reachX, reachY);
    moveRight(x, y, reachX, reachY);
    moveDown(x, y, reachX, reachY);
    moveRight(x, y, reachX, reachY);
}

void moveDown_1(float& x, float& y, int& reachX, int& reachY)
{
    moveDown(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
    moveDown(x, y, reachX, reachY);
    moveRight(x, y, reachX, reachY);
    moveRight(x, y, reachX, reachY);
    moveDown(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
    moveDown(x, y, reachX, reachY);
}

void moveLeft_1(float& x, float& y, int& reachX, int& reachY)
{
    moveLeft(x, y, reachX, reachY);
    moveUp(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
    moveDown(x, y, reachX, reachY);
    moveDown(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
    moveUp(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
}

void moveUp_1(float& x, float& y, int& reachX, int& reachY)
{
    moveUp(x, y, reachX, reachY);
    moveRight(x, y, reachX, reachY);
    moveUp(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
    moveUp(x, y, reachX, reachY);
    moveRight(x, y, reachX, reachY);
    moveUp(x, y, reachX, reachY);
}

void moveRight_2(float& x, float& y, int& reachX, int& reachY)
{
    moveRight_1(x, y, reachX, reachY);
    moveDown_1(x, y, reachX, reachY);
    moveRight_1(x, y, reachX, reachY);
    moveUp_1(x, y, reachX, reachY);
    moveUp_1(x, y, reachX, reachY);
    moveRight_1(x, y, reachX, reachY);
    moveDown_1(x, y, reachX, reachY);
    moveRight_1(x, y, reachX, reachY);
}


void moveDown_2(float& x, float& y, int& reachX, int& reachY)
{
    moveDown_1(x, y, reachX, reachY);
    moveLeft_1(x, y, reachX, reachY);
    moveDown_1(x, y, reachX, reachY);
    moveRight_1(x, y, reachX, reachY);
    moveRight_1(x, y, reachX, reachY);
    moveDown_1(x, y, reachX, reachY);
    moveLeft_1(x, y, reachX, reachY);
    moveDown_1(x, y, reachX, reachY);
}

void moveLeft_2(float& x, float& y, int& reachX, int& reachY)
{
    moveLeft_1(x, y, reachX, reachY);
    moveUp_1(x, y, reachX, reachY);
    moveLeft_1(x, y, reachX, reachY);
    moveDown_1(x, y, reachX, reachY);
    moveDown_1(x, y, reachX, reachY);
    moveLeft_1(x, y, reachX, reachY);
    moveUp_1(x, y, reachX, reachY);
    moveLeft_1(x, y, reachX, reachY);
}

void moveUp_2(float& x, float& y, int& reachX, int& reachY)
{
    moveUp_1(x, y, reachX, reachY);
    moveRight_1(x, y, reachX, reachY);
    moveUp_1(x, y, reachX, reachY);
    moveLeft_1(x, y, reachX, reachY);
    moveLeft_1(x, y, reachX, reachY);
    moveUp_1(x, y, reachX, reachY);
    moveRight_1(x, y, reachX, reachY);
    moveUp_1(x, y, reachX, reachY);
}

void main()
{
    float x = 300, y = 100;
    int reachX = 300, reachY = 100;
    moveRight_2(x, y, reachX, reachY);
    moveDown_2(x, y, reachX, reachY);
    moveLeft_2(x, y, reachX, reachY);
    moveUp_2(x, y, reachX, reachY);
    cin.ignore();
}

//Кривая Коха(K = 2)
#include <iostream>
#include <windows.h>

using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
const int moveX = 10, moveY = 10;

void moveRigth(float& x, float& y, int& reachX, int& reachY)
{
    reachX += moveX;
    for (x; x < reachX; x += 0.05)
        SetPixel(hdc, x, y, RGB(17, 0, 255));
}

void moveLeft(float& x, float& y, int& reachX, int& reachY)
{
    reachX -= moveX;
    for (x; x > reachX; x -= 0.05)
        SetPixel(hdc, x, y, RGB(0, 145, 255));
}

void moveRigthUp(float& x, float& y, int& reachX, int& reachY)
{
    reachX += moveX;
    reachY -= moveY;
    for (x, y; x < reachX; x += 0.05, y -= 0.05)
        SetPixel(hdc, x, y, RGB(0, 255, 255));
}

void moveRigthDown(float& x, float& y, int& reachX, int& reachY)
{
    reachX += moveX;
    reachY += moveY;
    for (x, y; x < reachX; x += 0.05, y += 0.05)
        SetPixel(hdc, x, y, RGB(0, 255, 128));
}

void moveLeftUp(float& x, float& y, int& reachX, int& reachY)
{
    reachX -= moveX;
    reachY -= moveY;
    for (x, y; x > reachX; x -= 0.05, y -= 0.05)
        SetPixel(hdc, x, y, RGB(9, 255, 0));
}

void moveLeftDown(float& x, float& y, int& reachX, int& reachY)
{
    reachX -= moveX;
    reachY += moveY;
    for (x, y; x > reachX; x -= 0.05, y += 0.05)
        SetPixel(hdc, x, y, RGB(239, 255, 0));
}

void moveRigth_1(float& x, float& y, int& reachX, int& reachY)
{
    moveRigth(x, y, reachX, reachY);
    moveRigthUp(x, y, reachX, reachY);
    moveRigthDown(x, y, reachX, reachY);
    moveRigth(x, y, reachX, reachY);
}

void moveRigthUp_1(float& x, float& y, int& reachX, int& reachY)
{
    moveRigthUp(x, y, reachX, reachY);
    moveLeftUp(x, y, reachX, reachY);
    moveRigth(x, y, reachX, reachY);
    moveRigthUp(x, y, reachX, reachY);
}

void moveRigthDown_1(float& x, float& y, int& reachX, int& reachY)
{
    moveRigthDown(x, y, reachX, reachY);
    moveRigth(x, y, reachX, reachY);
    moveLeftDown(x, y, reachX, reachY);
    moveRigthDown(x, y, reachX, reachY);
}

void moveLeftUp_1(float& x, float& y, int& reachX, int& reachY)
{
    moveLeftUp(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
    moveRigthUp(x, y, reachX, reachY);
    moveLeftUp(x, y, reachX, reachY);
}

void moveLeftDown_1(float& x, float& y, int& reachX, int& reachY)
{
    moveLeftDown(x, y, reachX, reachY);
    moveRigthDown(x, y, reachX, reachY);
    moveLeft(x, y, reachX, reachY);
    moveLeftDown(x, y, reachX, reachY);
}

void moveRigth_2(float& x, float& y, int& reachX, int& reachY)
{
    moveRigth_1(x, y, reachX, reachY);
    moveRigthUp_1(x, y, reachX, reachY);
    moveRigthDown_1(x, y, reachX, reachY);
    moveRigth_1(x, y, reachX, reachY);
}

void moveRigthUp_2(float& x, float& y, int& reachX, int& reachY)
{
    moveRigthUp_1(x, y, reachX, reachY);
    moveLeftUp_1(x, y, reachX, reachY);
    moveRigth_1(x, y, reachX, reachY);
    moveRigthUp_1(x, y, reachX, reachY);
}

void moveRigthDown_2(float& x, float& y, int& reachX, int& reachY)
{
    moveRigthDown_1(x, y, reachX, reachY);
    moveRigth_1(x, y, reachX, reachY);
    moveLeftDown_1(x, y, reachX, reachY);
    moveRigthDown_1(x, y, reachX, reachY);
}

void main()
{
    float x = 300, y = 100;
    int reachX = 300, reachY = 100;
    moveRigth_2(x, y, reachX, reachY);
    moveRigthUp_2(x, y, reachX, reachY);
    moveRigthDown_2(x, y, reachX, reachY);
    moveRigth_2(x, y, reachX, reachY);
    cin.ignore();
}
