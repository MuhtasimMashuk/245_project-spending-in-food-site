
#include<bits/stdc++.h>
using namespace std;

/* ---------------------------- definig restaurant --------------------------- */

struct resturent{
    int id;
    int price;
    int discount;
    int deliveryCost;
    int vat;
    int off_price;
    int value;
  
    



}database[100];

/* ----------------------------- globalvariables ---------------------------- */

int n;
int given;
int dp[10500][10500];
int remain,numb;

/* ----------------------------- makingDatabase ----------------------------- */
void initializeDp()
{
    for(int i=0; i<10500;i++)
    {
        for(int j=0;j<10500;j++)
        {
            dp[i][j]=-1;
        }


    }
    


}

void input_cal()
{

  for(int i=0;i<n;i++)
  {
     // printf("\nOriginal_price discount(%) delivaryCost vat\n");
      scanf("%d%d%d%d",&database[i].price,&database[i].discount,&database[i].deliveryCost,&database[i].vat);
      
      database[i].id=i;
      int calcu;
      if(database[i].vat == 0){
           
           calcu= database[i].price+database[i].deliveryCost-((database[i].price*database[i].discount/100));
                
                //vat was included with original price. No vat calculation needed
      }
      else{
        int vat_cal=(database[i].price*15/100);
        calcu= database[i].price+database[i].deliveryCost+vat_cal-((database[i].price*database[i].discount/100));
      //vat was not included with original price. 15% vat with original price added here.
       //printf("\n%d\n",vat_cal);

      }
      database[i].off_price=calcu;
      printf("offer_Price:%d\t",calcu);

      database[i].value=database[i].price-calcu;
      printf("value:%d\n\n",database[i].value);



  }




}

/* --------------------------------- KnapSack-hishab --------------------------------- */

int finding_best(int num, int remaining)
{

   int earn;
  
   if(num==n){
       return 0;
   }
   int max=finding_best(num+1,remaining);
   if(dp[num][remaining]!=-1){
       return dp[num][remaining];
   }

   if(remaining>=database[num].off_price)
   {
       earn=database[num].value+finding_best(num+1,remaining-database[num].off_price);
       if(earn>max)
       { 
           max=earn;


       }


   }
   
   
    remain=remaining;//assigning to global variable remain and numb
    numb=num;
    dp[num][remaining]=max;
  /* printf("\n%d\t%d",num,remaining);
   printf("\t%d\n",dp[num][remaining]);*///used for debugging purpose
   return dp[num][remaining];
   




 
   




}

/* --------------------------------path-printing -------------------------------- */
void selected_restaurants()
{
    {
    
    int res=dp[numb][remain];
    int w = remain; 
    for (int i = numb; i < n; i++) { 
          
       
        if (res == dp[i+1][w])  
            continue;         
        else { 
  
             
            printf("Selected %d no.Id resturent with value %d\n", database[i].id,database[i].value); 
              
         
            res = res - database[i].value; 
            w = w -database[i].off_price; 
        }


        if(res==0) 
        {
            break;
        }




}
}
 
}


/* ---------------------------------- main ---------------------------------- */

int main()
{
printf("\nEnter Number of Restaurant:");    
scanf("%d",&n);

printf("\nInsert your amount: ");
scanf("%d",&given);
    
initializeDp();

printf("\nInput restaurant Values:\n");
input_cal();



int x=finding_best(0,given);



printf("Total value:%d\n",x);

/*int y=dp[numb][remain];
printf("%d\n",y);
printf("%d\t%d\t%d\n",numb,remain,n);*///used for debuging purpose

selected_restaurants();







}