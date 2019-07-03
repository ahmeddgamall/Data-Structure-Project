count_1=0;
	short_pathes.resize(n);
	for (int i = 0; i < n; i++) {
		short_pathes[i].resize(n);
	}
	
	final_centrality.resize(n);
	final_centrality.assign(n,0);
	original_centrality.assign(n,0);
	long double * clos_centrality_value = new long double [n];
	for(int i = 0 ; i < n ; i++){
		Closeness_Centrality(adj_matrix, n,i,clos_centrality_value[i]);
	}
	vector<vector<bool>> visited(n,vector<bool>(n,false));
	   	for(int source=0 ; source<n ; source++)
	   	{
	   		for(int destnation=0 ; destnation<n ; destnation++)
	   		{
	   			if(!visited[source][destnation])
	   			{
	   				visited[source][destnation]=true;
	   				visited[destnation][source]=true;
	   				printAllPaths(source,destnation,n);
	   				for(int u=0 ; u<n ; u++)
	   				{
	   					final_centrality[u]=final_centrality[u]/count_1;
	   				}
	   				count_1=0;
	   				for(int t=0 ; t< n ; t++)
	   				{
	   					original_centrality[t]=original_centrality[t]+final_centrality[t];
	   				}
	   				final_centrality.assign(n,0);
	   			}
	   		}
	   	}



for(int i=0; i<n ; i++)
{
	cout<<original_centrality[i]<<"\n";
}
	return 0;
}
