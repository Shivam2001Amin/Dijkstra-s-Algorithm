#include<iostream>
#include<climits>
using namespace std;

int minimumDistance(int distance[], bool Tset[])
{
	int min=INT_MAX,index;
	for(int i=0;i<6;i++)
	{
		if(Tset[i]==false && distance[i]<=min)
		{
			min=distance[i];
			index=i;
		}
	}
	return index;
}
void dijkstraFunction(int graph[6][6],int src) 
{
	int distance[6]; 
	bool Tset[6];
	
	for(int i = 0; i<6; i++)
	{
		distance[i] = INT_MAX;
		Tset[i] = false;
	}
	distance[src] = 0;

	for(int i = 0; i<6; i++)
	{
		int m=minimumDistance(distance,Tset); 
		Tset[m]=true;
		for(int i = 0; i<6; i++)
		{
			if(!Tset[i] && graph[m][i] && distance[m]!=INT_MAX && distance[m]+graph[m][i]<distance[i])
				distance[i]=distance[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tDistance from source(A)"<<endl;
	for(int i = 0; i<6; i++)
	{ 
		char str=65+i; 
		cout<<str<<"\t\t\t"<<distance[i]<<endl;
	}
}
int main()
{
    cout << "Enter graph values for 6x6 matrix: ";
    int graph[6][6];
    for(int i=0;i<6;i++)
    {
      for(int j=0;j<6;j++)
      {
        cin>>graph[i][j];
      }
    }
	dijkstraFunction(graph,0);
	return 0;
}
