void Closeness_Centrality(vector<vector<int>> adj_matrix, int numOfver, int Src,long double &value )
{
	int* distance = new int[numOfver];
	bool* ShortpassSet = new bool[numOfver];
	int sumpass = 0;
	 value = (double) (numOfver - 1);
	for (int i = 0; i < numOfver; i++)
	{
		distance[i] = int_max;
		ShortpassSet[i] = false;
	}
	Dijkstra(adj_matrix, distance, ShortpassSet, numOfver, Src);
	sumpass = sumMinDist(distance, numOfver);
	value = value / (double)sumpass;
	delete[] distance;
	delete[] ShortpassSet;
 
}
