#include<iostream>
#include<math.h>
using namespace std;
struct Polynomial               //polynomial struct**************
{
    int order;
    double x_value;
    double cofficients[21];
};

Polynomial readpoly()           //function that reades the polynomial funcyion*******************
{
    Polynomial func;
    cout << "Enter polynomial order: ";
    cin >> func.order;
    cout << "Enter polynomial cofficients: ";
    for (int i = 0; i <= func.order; i++)
    {
        cin >> func.cofficients[i];
        cout << "";
    }
    cout << "Enter the value of x: ";
    cin >> func.x_value;
    return func;
}

double evalPoly(Polynomial p)   //function that evaluates the polynomial function************  
{
    double evaluation_result = 0;
    int order_2 = p.order;
    for (int i = 0; i <= p.order; i++)
    {
        evaluation_result = evaluation_result + pow(p.x_value, order_2 - i) * p.cofficients[i];
    }
    return evaluation_result;
}

void printPoly(Polynomial p)   //function to print the polynomial function****************
{
    cout << "f(x) = ";
    for (int i = 0; i <= p.order; i++)
    {
        if (p.cofficients[i] != 0 && i != p.order - 1 && i != p.order && p.cofficients[i + 1] > 0)
        {
            cout << p.cofficients[i] << " x^" << p.order - i << " + ";
        }
        if (p.cofficients[i] != 0 && i != p.order - 1 && i != p.order && p.cofficients[i + 1] < 0)
        {
            cout << p.cofficients[i] << " x^" << p.order - i << " ";
        }
        if (i == p.order - 1 && p.cofficients[i] != 0)
        {
            cout << p.cofficients[i] << " x";
        }
    }
    if (p.cofficients[p.order] != 0 && p.cofficients[p.order] > 0)
    {
        cout << " + " << p.cofficients[p.order];
    }
    if (p.cofficients[p.order] != 0 && p.cofficients[p.order] < 0)
    {
        cout << " " << p.cofficients[p.order];
    }
    cout << endl;
}

Polynomial addPoly(Polynomial p1, Polynomial p2)      //function that adds 2 polynomial functions***********
{
    Polynomial result_poly;
    if (p1.order == p2.order)                 // 2 function are same order
    {
        result_poly.order = p1.order;        //------------------------------------
        for (int i = 0; i <= p1.order; i++)
        {
            result_poly.cofficients[i] = p1.cofficients[i] + p2.cofficients[i];
        }
    }
    if (p1.order > p2.order)               //first function has higher order
    {
        result_poly.order = p1.order;    //-----------------------------------
        for (int i = 0; i < p1.order - p2.order; i++)
        {
            result_poly.cofficients[i] = p1.cofficients[i];
        }
        for (int i = p1.order - p2.order; i <= p1.order; i++)
        {
            result_poly.cofficients[i] = p1.cofficients[i] + p2.cofficients[i - 1];
        }
    }
    if (p1.order < p2.order)             //second function has higher order
    {
        result_poly.order = p2.order;    //---------------------------------------------
        for (int i = 0; i < p2.order - p1.order; i++)
        {
            result_poly.cofficients[i] = p2.cofficients[i];
        }
        for (int i = p2.order - p1.order; i <= p2.order; i++)
        {
            result_poly.cofficients[i] = p2.cofficients[i] + p1.cofficients[i - 1];
        }
    }
    return result_poly;
}


Polynomial SubPoly(Polynomial p1, Polynomial p2)      //function that subtracts 2 polynomial functions*************
{
    Polynomial result_poly;
    if (p1.order == p2.order)                          //2 functions are equal
    {
        result_poly.order = p1.order;   //----------------------------------------
        for (int i = 0; i <= p1.order; i++)
        {
            result_poly.cofficients[i] = p1.cofficients[i] - p2.cofficients[i];
        }
    }
    if (p1.order > p2.order)                           //first function has higher order
    {
        result_poly.order = p1.order;  //--------------------------------------------
        for (int i = 0; i < p1.order - p2.order; i++)
        {
            result_poly.cofficients[i] = p1.cofficients[i];
        }
        for (int i = p1.order - p2.order; i <= p1.order; i++)
        {
            result_poly.cofficients[i] = p1.cofficients[i] - p2.cofficients[i - 1];
        }
    }
    if (p1.order < p2.order)           //second function has higher order
    {
        result_poly.order = p2.order;    //---------------------------------------------
        for (int i = 0; i < p2.order - p1.order; i++)
        {
            result_poly.cofficients[i] = p2.cofficients[i];
        }
        for (int i = p2.order - p1.order; i <= p2.order; i++)
        {
            result_poly.cofficients[i] = p2.cofficients[i] - p1.cofficients[i - 1];
        }
    }
    return result_poly;
}

Polynomial mulPoly(Polynomial p1, Polynomial p2)          //function that multiplies 2 polynomial functions***************
{
    Polynomial result_poly;
    if (p1.order + p2.order > 20)
    {
        result_poly.order = -1;
        return result_poly;
    }
    result_poly.order = p1.order + p2.order;
    for (int i = 0; i <= result_poly.order; i++)
    {
        for (int j = 0; j <= p2.order; j++)
        {
            for (int k = 0; k <= p1.order; k++)
            {
                if (j + k == i)
                {
                    result_poly.cofficients[i] = result_poly.cofficients[i] + (p2.cofficients[j] * p1.cofficients[k]);
                }
            }
        }
    }
    return result_poly;
}
int main()                 //main function****************************
{
    int x;
    Polynomial a, b, out_put;
    a = readpoly();
    printPoly(a);
    cout << "f(x=" << a.x_value << ") = " << evalPoly(a) << endl;
    cout << endl << endl << endl;
    b = readpoly();
    printPoly(b);
    cout << "f(x=" << b.x_value << ") = " << evalPoly(b) << endl;
    cout << endl << endl << endl;
    cout << "Choose operation to be performed (+ , - , *): ";
    char c;
    cin >> c;
    cout << "Enter value of x for the result polynomial: ";
    cin >> x;
    switch (c)
    {
    case'+':out_put = addPoly(a, b); out_put.x_value = x; printPoly(out_put); cout << "f(x=" << out_put.x_value << ") = " << evalPoly(out_put) << endl; break;
    case'-':out_put = SubPoly(a, b); out_put.x_value = x; printPoly(out_put); cout << "f(x=" << out_put.x_value << ") = " << evalPoly(out_put) << endl; break;
    case'*':out_put = mulPoly(a, b); out_put.x_value = x;
        if (out_put.order == -1)
        {
            cout << "error!! try again";
        }
        else
        {
            printPoly(out_put);
            cout << "f(x=" << out_put.x_value << ") = " << evalPoly(out_put) << endl;
        }
        break;
    default:cout << "invalid operation" << endl;
    }
}
