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
 
