
		#include <iostream>
		#include <vector>
		#include <list>
		#include <iomanip>
		using namespace std;
		 
		#define int_max 2147483647
		class node {
			int weight;
			int id;
		public:
			void set_weight(int w) { weight = w; }
			void set_id(int i) { id = i; }
			int get_weight() { return weight; }
			int get_id() { return id; }
		};
		 
		//this function return the node that have minimum distance which is not
		//included in shortpassSet yet 
		int minDistance(bool ShortpassSet[], int distance[], int numOfver)
		{
			int indexOfmin;
			int min = int_max;
			for (int i = 0; i < numOfver; i++)
			{
				if (distance[i] < min && ShortpassSet[i] == false)
				{
					min = distance[i];
					indexOfmin = i;
				}
			}
			return indexOfmin;
		}
		 
		int sumMinDist(int distance[], int numOfver)
		{
			int sum = 0;
			for (int i = 0; i < numOfver; i++)
				sum += distance[i];
			return sum;
		}
		
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
		 
		}
		 
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
