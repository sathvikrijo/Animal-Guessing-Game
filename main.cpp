#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Node
{
    string ans;
    struct Node* left;
    struct Node* right;
};
Node *newnode, *root , *start;

void question(Node* root, Node* prev);
void Deserialize(Node*& root, fstream& file);
void updatetree(Node* fin, Node*& prefin);
void finalquestion(Node* root, Node* prev);
void dot(int n);
void gameReady();
void replay();

void gameReady()
{
    system("color 8F");
    cout<<"Description:\n\tThis is C++ simple based on the concept of Artificial Intelligence. The intelligence of this game \nwill be increased as we play it again more number of times.";
    cout<<"\n\n\nRULES:\n\t1.  Think of an any animal, bird, reptile or something...\n\t2.  The AI will guess your animal, reply with \"yes\" or \"no\" only.";
    cout<<"\n\t[NOTE:] You can also reply with \"Yes\", \"YES\", \"y\", \"Y\", \"No\", \"NO\", \"n\", \"N\"";
    cout<<"\n\n\tKIND REQUEST TO ALL, PLEASE DON'T EVER REPLY WRONGLY AND TRY TO SEE WHAT HAPPENS WHEN COMPUTER FAILS,\nYOUR EACH ANSWER WILL TEACH THE COMPUTER, DON'T TEACH IT WRONG\n\n\n\n\t\t\t\t\t\t***THANK YOU***\n\n\n";
    cout<<"\t\t\t\t\tBUILT BY St.Joseph's Cseians"<<endl<<"\t\t\t\t\t\t#Viola\n\t\t\t\t\t\t#Hemashree\n\t\t\t\t\t\t#Lakshmi\n\t\t\t\t\t\t#Yogeswaran\n\t\t\t\t\t\t#Sanjay Prashadh\n\t\t\t\t\t\t#Sathvik\n"<<endl;
    system("pause");
}
void Serialize (Node*& root, fstream& file)
{
    if(root == NULL)
        file<<"#"<<endl;
    else
    {
        file<<root->ans<<endl;
        //cout<<root->ans<<endl;
        Serialize(root->left,file);
        Serialize(root->right,file);
    }
}

void Deserialize (Node*& root,fstream& file)
{
            string str;
            if(!file.eof())
            {
                getline(file,str);
                cin.clear();
            }
            else
                return;
            //cout<<str<<endl;
            if(str!="#")
            {
                root = new Node;
                root->ans = str;
                Deserialize(root->left,file);
                Deserialize(root->right,file);
            }
            else
            {
                root = NULL;
            }
}

void preorder(Node *root)
{
    if(root == NULL)
        return;
    else
    {
        cout<<root->ans<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void updatetree(Node* fin, Node*& prefin)
{
    string ans,qn;
    system("color DF");
    //cout<<prefin->ans<<endl<<fin->ans<<endl;
    cout<<"\n\n\t\t\t\t\t****I ACCEPT MY DEFEAT****"<<endl;
    cout<<"What's your animal?"<<"\t";
    cin>>ans;
    cout<<"Now, type a characteristic question for your animal which return your animal "<<ans<<" for yes, and return "<<fin->ans<<" for no"<<endl;
    cin.ignore();
    getline(cin,qn);

    Node *ansnode, *qnnode;
    ansnode = new Node;
    ansnode->ans = ans;
    ansnode->left = NULL;
    ansnode->right = NULL;

    qnnode = new Node;
    qnnode->ans = qn;
    qnnode->left = ansnode;
    qnnode->right = fin;

    if(prefin->left == fin)
    {
        prefin->left = qnnode;
    }

    else if(prefin->right == fin)
    {
        prefin->right = qnnode;
    }
    cout<<"Updated successfully"<<endl;
    system("color 0A");
    replay();
}

void delay(int n)
{
    for(int i=0;i<=n;i++);
}

void replay()
{
        cout<<"\n\nDo you want to play again?";
        cin>>reply;
        if(reply=="yes" || reply=="YES" || reply=="Yes" || reply=="y" || reply=="Y")
        {
            cout<<"Rebooting the system";
            dot(5);
            system("CLS");
            question(start,prev);
        }
        else if(reply=="no" || reply=="NO" || reply=="No" || reply=="n" || reply=="N")
        {
            system("color 09");
            cout<<"Thanks for playing with me, i think we had a good time. See you soon. Bye bye"<<endl;
            for(int i=0;i<20;i++)
            {
                if(i==10)
                    cout<<"\t\t\t\t\tBUILT BY St.Joseph's Cseians"<<endl<<"\t\t\t\t\t\t#Viola\n\t\t\t\t\t\t#Hemashree\n\t\t\t\t\t\t#Lakshmi\n\t\t\t\t\t\t#Yogeswaran\n\t\t\t\t\t\t#Sanjay Prashadh\n\t\t\t\t\t\t#Sathvik\n"<<endl;
                else
                    cout<<endl;
            }
        }
}
void finalquestion(Node* root, Node* prev)
{
    string reply;
    //system("color 4F");
    cout<<"Is your animal '"<<root->ans<<"' ?"<<"\t";
    system("color 4F");
    cin>>reply;
    if(reply=="yes" || reply=="YES" || reply=="Yes" || reply=="y" || reply=="Y")
    {
        //system("CLS");
        system("color AF");
        cout<<"\n\n\t\t\t\tYAAAAAAAAAAAAAAAAAAAH!!! I found out, Huraaaaay"<<endl;
        cout<<"\t\t\t\t\t      Thanks for playing"<<endl;
        replay();
    }
    else if(reply=="no" || reply=="NO" || reply=="No" || reply=="n" || reply=="N")
        updatetree(root, prev);
    else
    {
        cout<<"Sorry, please enter a valid answer Yes or No"<<endl;
        finalquestion(root,prev);
    }
}

void question(Node* root, Node* prev)
{
    string reply;
    system("color 0A");
    if(root->left!=NULL && root->right!=NULL)
    {
        cout<<root->ans<<endl;
        cin>>reply;
        if(reply=="yes" || reply=="YES" || reply=="Yes" || reply=="y" || reply=="Y")
            question(root->left,root);
        else if(reply=="no" || reply=="NO" || reply=="No" || reply=="n" || reply=="N")
            question(root->right,root);
        else
        {
            cout<<"Sorry, please enter a valid answer Yes or No"<<endl;
            question(root,prev);
        }
    }
    else
    {
        finalquestion(root,prev);
    }
}

void dot(int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<".";
        Sleep(900);
    }
    cout<<endl;
}

int main()
{
    //char value,str[100];
    //int i=0;
    fstream file;
    system("color 0A");
    file.open("Data.txt",ios::in);
    Deserialize(start,file);
    file.close();
    //cout<<"Deserialize ends"<<endl;
    gameReady();
    cout<<"Initiating the GAME";
    dot(5);
    system("CLS");
    question(start,NULL);
    //preorder(start);
    file.open("Data.txt",ios::out);
    Serialize(start,file);
    //cout<<"Serialize ends"<<endl;
    file.close();
    return 0;
}
