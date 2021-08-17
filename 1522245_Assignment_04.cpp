#include<iostream>
using namespace std;
class DFA
{
    struct Node
    {
        char tableValue;
        char states;
    };
    Node transition[4][4];
    void initializeTableValue()
    {
        transition[0][0].tableValue='-';
        transition[0][1].tableValue='0';
        transition[0][2].tableValue='-';
        transition[0][3].tableValue='1';
        transition[1][0].tableValue='0';
        transition[1][1].tableValue='-';
        transition[1][2].tableValue='1';
        transition[1][3].tableValue='-';
        transition[2][0].tableValue='-';
        transition[2][1].tableValue='1';
        transition[2][2].tableValue='-';
        transition[2][3].tableValue='0';
        transition[3][0].tableValue='1';
        transition[3][1].tableValue='-';
        transition[3][2].tableValue='0';
        transition[3][3].tableValue='-';
    }
    void initializeStates()
    {
        transition[0][0].states='a';
        transition[0][1].states='b';
        transition[0][2].states='c';
        transition[0][3].states='d';
        transition[1][0].states='a';
        transition[1][1].states='b';
        transition[1][2].states='c';
        transition[1][3].states='d';
        transition[2][0].states='a';
        transition[2][1].states='b';
        transition[2][2].states='c';
        transition[2][3].states='d';
        transition[3][0].states='a';
        transition[3][1].states='b';
        transition[3][2].states='c';
        transition[3][3].states='d';
    }
public:
    DFA()
    {
        initializeTableValue();
        initializeStates();
    }
    void dfaOperation(string s)
    {
        int n=0;
        while(s[n]!=NULL)
        {
            n++;
        }
        int j=0,id=0;
        char finalState='a';
        bool edie=false;
        char currentValue='\0';
        while(j!=n)
        {
            for(int i=0; i<4; i++)
            {
                if(s[j]==transition[id][i].tableValue)
                {
                    currentValue=transition[id][i].states;
                    id=i;
                    break;
                }
                else if(s[j]!='0'&&s[j]!='1')
                {
                    edie=true;
                    break;
                }
            }
            if(edie)
            {
                break;
            }
            j++;
        }
        if(currentValue==finalState&&edie==false)
        {
            cout<<"yes\n";
        }
        else if(edie)
        {
            cout<<"Invalid input\n";
        }
        else
        {
            cout<<"No\n";
        }
    }

};
int main()
{
    string s;
    char p='\0';
    DFA evenOdd;
    while(p!='n')
    {
        cout<<"Input a binary string : \n";
        cin>>s;
        evenOdd.dfaOperation(s);
        cout<<"Do you want to continue (y/n): ";
        cin>>p;
    }
    cout<<"Thank you for using our DFA\n";
    return 0;
}
