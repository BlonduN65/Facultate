#include "siruri.h"
namespace siruri{
    int str_length(const char *s){
        if(s==nullptr)
            return 0;
        const char *p=s;
        int lungime=0;
        while(*p!='\0'){
            lungime++;
            p++;
        }
        return lungime;

    }
}