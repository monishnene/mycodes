#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int sample_input(void) 
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a+b+c;
    return 0;
}

int various_inputs(void) 
{
    int a;
    long b;
    char c;
    float d;
    double e;
    cin>>a>>b>>c>>d>>e;
    printf("%d\n%ld\n%c\n%f\n%lf",a,b,c,d,e);
    return 0;
}


int switch_test(void)
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(n)
    {
        case 1:
        {
            cout<<"one";
            break;
        }
        case 2:
        {
            cout<<"two";
            break;
        }
        case 3:
        {
            cout<<"three";
            break;
        }
        case 4:
        {
            cout<<"four";
            break;
        }
        case 5:
        {
            cout<<"five";
            break;
        }
        case 6:
        {
            cout<<"six";
            break;
        }
        case 7:
        {
            cout<<"seven";
            break;
        }
        case 8:
        {
            cout<<"eight";
            break;
        }
        case 9:
        {
            cout<<"nine";
            break;
        }
        default:
        {
            cout<<"Greater than 9";
        }
    }


int switch_bore() 
{
    int n=0,start=0,stop=0;
    cin>>start>>stop;
    for(n=start;n<stop+1;n++)
    {
        if(n!=start)
        {
            cout<<"\n";
        }
        switch(n)
        {
            case 1:
            {
                cout<<"one";
                break;
            }
            case 2:
            {
                cout<<"two";
                break;
            }
            case 3:
            {
                cout<<"three";
                break;
            }
            case 4:
            {
                cout<<"four";
                break;
            }
            case 5:
            {
                cout<<"five";
                break;
            }
            case 6:
            {
                cout<<"six";
                break;
            }
            case 7:
            {
                cout<<"seven";
                break;
            }
            case 8:
            {
                cout<<"eight";
                break;
            }
            case 9:
            {
                cout<<"nine";
                break;
            }
            default:
            {
                if(n%2)
                {
                    cout<<"odd";
                }
                else
                {
                    cout<<"even";
                }
            }
        }

    }
    return 0;
}

int max_of_four(int a, int b, int c, int d)
{
    int n=a;
    n=n>b?n:b;
    n=n>c?n:c;
    n=n>d?n:d;
    return n;
}

void update(int *a,int *b)
{
    int A=*a;
    int B=*b;
    *(a)=A+B;
    *(b)=A-B;
    if(*(a)<0)
    {
        *(a)*=-1;
    }
    if(*(b)<0)
    {
        *(b)*=-1;
    }
}

int double_array() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long j=0,i=0,rows=0,queries=0,columns=0,row=0,column=0;
    cin>>rows;
    cin>>queries;
    long* arrays[rows];
    for(i=0;i<rows;i++)
    {
        cin>>columns;
        arrays[i]=(long*)malloc(columns*sizeof(long*));
        for(j=0;j<columns;j++)
        {
            cin>>*(arrays[i]+j);
        }
    }
    for(i=0;i<queries;i++)
    {
        cin>>row;
        cin>>column;
        printf("%ld\n",*(arrays[row]+column));
    }
    for(i=0;i<rows;i++)
    {
        free(arrays[i]);
    }
    return 0;
}
