void printAllPaths(int src, int dst,int numOfver) 
{  
    bool *visited = new bool[numOfver];  
    int *path = new int[numOfver]; 
    int path_index = 0;  
    for (int i = 0; i < numOfver; i++) 
        visited[i] = false;  
    printAllPathsUtil(src, dst, visited, path, path_index , numOfver); 
} 
