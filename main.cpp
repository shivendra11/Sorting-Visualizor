#include "graphics.h" 
#include <bits/stdc++.h> 

using namespace std;

vector<int> numbers; 

int size=100; // size of array

int gap = 10; // gap between two histogram

void swap_colors(int i, int j, int x, int y) 
{ 
    delay(100); 
    setcolor(GREEN); 
    line(j, size, j, size - y); 
    delay(100);
    setcolor(BLACK); 
    line(j, size, j, size - y); 
    delay(100); 
    setcolor(WHITE); 
    line(j, size, j, size - x); 
    delay(100); 
    setcolor(BLACK); 
    line(i, size, i, size - x); 
    delay(100); 
    setcolor(GREEN); 
    line(i, size, i, size - y); 
    delay(100); 
    setcolor(WHITE); 
    line(i, size, i, size - y);  
	delay(100);
} 

void swap(int* xp, int* yp) 
{ 

    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selection_Sort() 
{ 

    for (int i = 0; i < size - 1; i++) { 
        int min_idx = i; 

        for (int j = i + 1; j < size; j++) { 

            if (numbers[j] < numbers[min_idx]) { 

                min_idx = j; 
                
            } 

        } 
        swap(&numbers[min_idx], &numbers[i]); 

        swap_colors(gap * i + 1, gap * (min_idx) + 1, numbers[min_idx], numbers[i]); 

    } 
} 


void insertion_Sort() 
{ 
    for (int i = 1; i <= size; i++)
	 { 
            if (numbers[i] < numbers[i-1]) 
			{ 
                int j=i;
                while(j>0&&numbers[j-1]>numbers[j])
  				{
  					swap(numbers[j-1],numbers[j]);
  					swap_colors(gap * (j-1) + 1, gap * (j) + 1, numbers[j], numbers[j-1]);  
  					j--;
				  }               
            } 
    } 
} 



void bubble_Sort() 
{ 
    int temp, i, j; 
  
    for (i = 1; i < size; i++) { 
        for (j = 0; j < size - i; j++) { 
            if (numbers[j] > numbers[j + 1]) { 
                temp = numbers[j]; 
                numbers[j] = numbers[j + 1]; 
                numbers[j + 1] = temp; 
  
                swap_colors(gap * j + 1, gap * (j + 1) + 1, numbers[j + 1], numbers[j]); 
            } 
        } 
    } 
} 


int partition( int s, int e)
{
	int i=s-1;
	int j=s;
	int pivot=numbers[e];
	for(;j<e;j++)
	{
		if(numbers[j]<=pivot)
		{
			i++;
			swap(numbers[i],numbers[j]);
			swap_colors(gap * i + 1, gap * (j) + 1, numbers[j], numbers[i]); 
		}
	}
	swap(numbers[i+1],numbers[e]);
	swap_colors(gap * (i+1) + 1, gap * (e) + 1, numbers[e], numbers[i+1]); 
	return i+1;
}

void quick_Sort(int s, int e)
{
	if(s>=e)
	{
		return;
	}
	
	int p=partition(s,e);
	quick_Sort(s,p-1);
	quick_Sort(p+1,e);
}

int main() 
{ 

    int gd = DETECT, gm;
    
    initgraph(&gd, &gm, NULL); 
    
    for (int i = 1; i <= size; i++) 
        numbers.push_back(i); 
 

 
    random_shuffle(numbers.begin(), numbers.end());
  
    for (int i = 1; i <= gap * size; i =i+ gap) { 
        
		setlinestyle(0, 0, 5);  
        line(i, size, i, (size - numbers[i / gap])); 
    }
    delay(100);
    
    
    
    
    cout<<"\n\n";
    cout<<"****************************************************************"<<endl;
    
    int srt_tech=-1;
    
    cout<<"press 1 for SELECTION SORT"<<endl;
    cout<<"press 2 for INSERTION SORT"<<endl;
    cout<<"press 3 for BUBBLE SORT"<<endl;
    cout<<"press 4 for QUICK SORT"<<endl;
    cout<<endl;
    cout<<"****************************************************************"<<endl;
    
    

    
    while(srt_tech==-1)
    {
    cin>>srt_tech;
    if(srt_tech==1)
    	{
    	cout<<"You chose SELCTION SORT \nNow see the BGI Window\n"<<endl;
    	cout<<"****************************************************************"<<endl;
    	cout<<"INPUTS"<<endl;
    	for(int i = 0; i < size; i++) 
        	cout << numbers[i] << " ";   	
    	selection_Sort(); 
    	break;
    	}
    else if(srt_tech==2)
    {
    	cout<<"You chose INSERTION SORT \nNow see the BGI Window\n"<<endl;
    	cout<<"****************************************************************"<<endl;
    	cout<<"INPUTS"<<endl;
    	for(int i = 0; i < size; i++) 
        	cout << numbers[i] << " "; 
    	insertion_Sort();
    	break;
    }
    else if(srt_tech==3)
    {
    	cout<<"You chose BUBBLE SORT \nNow see the BGI Window\n"<<endl;
    	cout<<"****************************************************************"<<endl;
    	cout<<"INPUTS"<<endl;
    	for(int i = 0; i < size; i++) 
        	cout << numbers[i] << " "; 
    	bubble_Sort();
    	break;
    }
    else if(srt_tech==4)
    {
    	cout<<"You chose QUICK SORT \nNow see the BGI Window\n"<<endl;
    	cout<<"****************************************************************"<<endl;
    	cout<<"INPUTS"<<endl;
    	for(int i = 0; i < size; i++) 
        	cout << numbers[i] << " "; 
    	quick_Sort(0,size-1);
    	break;
    }
    else
    {
    	srt_tech=-1;
    	cout<<"You're not a good person, try again"<<endl;
    	continue;
    }
    }
    
    cout<<"\n\n";
   
    cout<<"RESULT"<<endl;
    for (int i = 0; i < size; i++) { 

        cout << numbers[i] << " "; 

    } 
    cout<<"\n\n****************************************************************"<<endl;

    delay(100);
    closegraph(); 
    
    return 0; 
} 
