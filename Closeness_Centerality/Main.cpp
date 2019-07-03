int main()
{
	int n, m, start, end, weight;
	cin >> n >> m;
	vector<vector<int>> adj_matrix;
	adj_matrix.resize(n);
	for (int i = 0; i < n; i++) {
		adj_matrix[i].resize(n);
	}
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> weight;
		adj_matrix[start][end] = weight;
		adj_matrix[end][start] = weight;
	}
	long double * clos_centrality_value = new long double [n];
	for(int i = 0 ; i < n ; i++)
    Closeness_Centrality(adj_matrix, n,i,clos_centrality_value[i]);
	for (int i = 0; i < n; i++)
	{
		cout << fixed << setprecision (10) <<clos_centrality_value[i] << "\n";
 
	}
	//system("pause");
	return 0;
}
