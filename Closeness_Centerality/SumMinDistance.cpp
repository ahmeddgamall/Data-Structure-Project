int sumMinDist(int distance[], int numOfver)
{
	int sum = 0;
	for (int i = 0; i < numOfver; i++)
		sum += distance[i];
	return sum;
}
