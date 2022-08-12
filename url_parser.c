#include "stdio.h"
#include "string.h"
#include "ctype.h"
int main() {
    int n;
    char company[100],url[100],country[100],service[100],prev[100];
    const char s[2] = ".";
    char *token;
    scanf("%d %s",&n,company);
    company[0]=tolower(company[0]);
    for(int i=0; i<n; ++i) {
        int flag=0;
        scanf("%s",url);
        token = strtok(url, s);
        //keeping track of previous tokens as service name comes right before the company name
        strcpy(prev,token);
        if(strlen(token)==2)
            strcpy(country,token);
        while( 1) {
            token = strtok(NULL, s);
            if(token==NULL)
                break;
            if(strcmp(token,company)==0){//company giving service
                strcpy(service,prev);
                flag=1;
            }
            if(strlen(token)==2)
                strcpy(country,token);
            strcpy(prev,token);
        }
        if(flag==1){
            if(strcmp(country,"tr")==0)
                strcpy(country,"Turkey");
            else if(strcmp(country,"de")==0)
                strcpy(country,"Germany");
            else if(strcmp(country,"fr")==0)
                strcpy(country,"France");
            else if(strcmp(country,"uk")==0)
                strcpy(country,"United Kingdom");
            service[0]=toupper(service[0]);
            printf("%s - %s\n",country,service);
        }
    }
    return 0;
}