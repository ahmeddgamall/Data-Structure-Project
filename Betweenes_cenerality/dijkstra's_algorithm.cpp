void  Dijkstra(vector<vector<int>> adj_matrix, int distance[], bool ShortpassSet[], int numOfver, int Src)
{
	distance[Src] = 0;
	for (int i = 0; i < numOfver; i++)
	{
		int VerOfMinDist = minDistance(ShortpassSet, distance, numOfver);
 
		ShortpassSet[VerOfMinDist] = true;
		for (int v = 0;v < numOfver; v++)
		{
			if (!ShortpassSet[v] && adj_matrix[VerOfMinDist][v] && distance[VerOfMinDist] != int_max
				&& distance[VerOfMinDist] + adj_matrix[VerOfMinDist][v] < distance[v])
				distance[v] = distance[VerOfMinDist] + adj_matrix[VerOfMinDist][v];
		}
	}
