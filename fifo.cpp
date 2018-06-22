	
#include <iostream>
 
using namespace std;
 
int getReplaceposition(int counter[],int n)
{
    int max = counter[0];
    int pos=0;
    for(int i=0;i<n;i++) { if(counter[i]>max)
       {
           pos=i;
           max = counter[i];
       }
    }
 
    return pos;
}
 
int main()
{
    int pages[20],frames[10],counter[10];
    int nPages,nFrames,pageFault=0;
     
    cout<<"Enter the number of pages(MAX 20): "; cin>>nPages;
     
    cout<<"Enter the number of frames(MAX 10): "; cin>>nFrames;
     
    cout<<"Enter the Page reference string: ";
    for(int i=0;i<nPages;i++){ cin>>pages[i];
    }
     
     for(int i=0;i<nFrames;i++)
    {
        frames[i] = 0; 
        counter[i] = 0; //here 0 referes an empty space in frame
    }
      
    for(int i=0;i<nPages;i++)
    {int flag =0;
        for(int j=0;j<nFrames;j++)
        {
         if(frames[j] == pages[i])
           {flag=1;  //if page is present in frame (flag=1)
            break;
           }
        }
         //if page is not present in frame (flag=0)
        if(flag == 0)
         {
             pageFault++;
             for(int j=0;j<nFrames;j++)
             {
                if(frames[j] == 0)
                {   frames[j] = pages[i];
                    flag=1;
                    counter[j]++;
                    break;
                }
                  
             }
         }
          
         //if there is no empty frame
          
         if(flag == 0)
         {
          int pos = getReplaceposition(counter,nFrames); 
          frames[pos] = pages[i];
          counter[pos] = 1;
          for(int k=0;k<nFrames;k++)
           {  if(k!=pos)
               counter[k]++;
                      }
         }
          
          cout<<endl;
      for(int j=0;j<nFrames;j++)
      {
          cout<<frames[j]<<" ";
      }
          
             
    }    
     
     cout<<"\nPage Fault: "<<pageFault;
     
        
    return 0;
}
