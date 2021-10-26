#include <iostream>
#include <string>
using namespace std;
struct TextPaper {
    int stdnum;
    char answer1[20];
    char answer2[20];
    char answer3[20];
};

bool judge(char *&pA, char *&pB){
    int flag = 0,len = 0;
    while (*pA!='\0' && *pB !='\0')
    {
        if(*pA==*pB)
            flag++;
        pA++,pB++,len++;
    }
    return flag >= 0.9 * len;
}

int compare(TextPaper *A, TextPaper *B){
    char *pa = A->answer1, *pb = B->answer1;
    if (judge(pa, pb))
        return 1;
    pa = A->answer2;
    pb = B->answer2;
    if (judge(pa, pb))
        return 2;
    pa = A->answer3;
    pb = B->answer3;
    if (judge(pa, pb))
        return 3;
    return 0;
}

int main(){
    int t;
    cin >> t;
    TextPaper *TP = new TextPaper[t];
    for (int i = 0; i < t; i++)
    {
        cin >> TP[i].stdnum >> TP[i].answer1 >> TP[i].answer2 >> TP[i].answer3;
    }
    for(int i=0;i<t-1;i++)
    {
        for(int j=i+1;j<t;j++)
        {
            int res = compare(TP+i,TP+j);
            if(res!=0)
                cout<<TP[i].stdnum<<" "<<TP[j].stdnum<<" "<<res<<endl;
        }
    }
    return 0;
}