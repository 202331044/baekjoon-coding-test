#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;
int cnt = 0;

void bfs(int x, int y, vector<vector<pair<int, int>>>& islands, vector<vector<bool>>& visited, vector<vector<bool>>& map)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (visited[nx][ny] == false && map[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				islands[cnt].push_back({ nx, ny });
				bfs(nx, ny, islands, visited, map);
			}
		}
	}
}

int prim(vector<vector<pair<int, int>>>& vec)
{
	int total = 0;
	priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<>> pq;
	vector<bool> visited(cnt, false);
	pq.push({ 0, 0 });

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();
		int dist = curr.first;
		int land = curr.second;

		if (visited[land]) continue;
		visited[land] = true;
		total += dist;

		for (auto next : vec[land])
		{
			int nextLand = next.first;
			int nextDist = next.second;
			if (visited[nextLand] == false)
				pq.push({nextDist, nextLand});
		}
	}

	for (auto visit : visited)
	{
		if (visit == false)
			return -1;
	}
	return total;
}

int main()
{
	bool tmp;
	cin >> n >> m;
	vector<vector<bool>> map(n, vector<bool>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<pair<int, int>>> islands(6);
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < m; ++c)
		{
			if (map[r][c] == 1 && visited[r][c] == false)
			{
				visited[r][c] = true;
				islands[cnt].push_back({ r, c });
				bfs(r, c, islands, visited, map);
				cnt++;
			}
		}
	}

	vector<vector<pair<int, int>>> vec(cnt);
	bool check = false;
	for(int i = 0; i < cnt - 1; ++i)
	{
		for (auto p1 : islands[i])
		{
			for (int j = i + 1; j < cnt; ++j)
			{
				for (auto p2 : islands[j])
				{
					check = false;
					int dist, minVal, maxVal;
					if (p1.first == p2.first)
					{
						minVal = p1.second;
						maxVal = p2.second;
						if (minVal > maxVal) swap(minVal, maxVal);
						for (int k = minVal + 1; k < maxVal; ++k)
						{							
							if (map[p1.first][k] == 1)
							{
								check = true;
								break;
							}
						}

						if (check == false)
						{
							dist = maxVal - minVal - 1;
							if (dist > 1)
							{
								vec[i].push_back({ j, dist });
								vec[j].push_back({ i, dist });
							}
						}
					}
					else if (p1.second == p2.second)
					{
						minVal = p1.first;
						maxVal = p2.first;
						if (minVal > maxVal) swap(minVal, maxVal);
						for (int k = minVal + 1; k < maxVal; ++k)
						{					
							if (map[k][p1.second] == 1)
							{
								check = true;
								break;
							}
						}
						
						if (check == false)
						{
							dist = maxVal - minVal - 1;
							if (dist > 1)
							{
								vec[i].push_back({ j, dist });
								vec[j].push_back({ i, dist });
							}
						}
					}
				}
			}
		}
	}

	cout << prim(vec);

	return 0;
}
