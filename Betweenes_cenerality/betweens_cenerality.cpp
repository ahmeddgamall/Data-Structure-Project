void printAllPathsUtil(int u, int d, bool visited[], 
                            int path[], int &path_index , int numOfver) 
{ 
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
    if (u == d) 
    { 
    	int sum=0;
        for (int i = 0; i<path_index-1; i++)
        {
        	sum=sum+adj_matrix[path[i]][path[i+1]];
        } 
        if(sum==short_pathes[u][d])
        {
        	count_1++;
        	for(int j=0 ; j<numOfver ; j++)
        	{
        		for(int y=0 ; y<path_index ; y++)
        		{
        			if(y==0 || y==path_index-1) continue;
        			else
        			{
        				if(j==path[y])
        				{
        					final_centrality[j]++;
        				}
        			}
        		}
        	}
        }

                   
    } 
    else 
    { 
        list<int>::iterator i; 
        for (i = adj_list[u].begin(); i != adj_list[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(*i, d, visited, path, path_index , numOfver); 
    } 
    path_index--; 
    visited[u] = false;
}
