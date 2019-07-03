void Degree_Centrality() {
	for (int i = 0; i < adj_list.size(); i++) {
		list<int>::iterator itr = adj_list[i].begin();
		while (itr != adj_list[i].end()) {
			centrality[i]++;
			itr++;
		}
		cout << centrality[i] << "\n";
	}
}
