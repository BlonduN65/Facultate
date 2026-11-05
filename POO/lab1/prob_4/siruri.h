#ifndef SIRURI_H_
#define SIRURI_H_
namespace siruri{
    int str_length(const char *s);
    bool eq_mask(const char *sir ,const char *mask);
    bool eq_cuv(const char *cuv , const char *tablou[]);
    char *strdel(char *s,int pos , int n);
    char *strins(char *s1,int pos,const char *s2);
}




#endif