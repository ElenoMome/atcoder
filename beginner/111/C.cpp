#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	//入力処理
	vector<int> count1, count2, vec1, vec2;
	int n;

	cin >> n;

	int v[n];

	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	//ここまで


	//本処理
	for(int i = 0; i < n/2; i++)
	{

		if(i == 0)
		{
			vec1.push_back(v[i*2]);
			count1.push_back(1);
			vec2.push_back(v[i*2 + 1]);
			count2.push_back(1);
			continue;
		}
		for(auto j = 0; j < vec1.size(); j++)
		{
			if(vec1[j] == v[i*2])
			{
				count1[j] += 1;
				break;
			}

			if(j == vec1.size() - 1)
			{
				vec1.push_back(v[i*2]);
				count1.push_back(1);
				break;
			}
		}

		for(auto j = 0; j < vec2.size(); j++)
		{
			if(vec2[j] == v[i*2 + 1])
			{
				count2[j] += 1;
				//デバッグ用
				cout << "count2:";
				for(auto i = 0; i < count2.size(); i++)
					{
						cout << count2[i] << ',';
					}

				cout << endl;
				//デバッグ用

				break;
			}

			if(j == vec2.size() - 1)
			{
				vec2.push_back(v[i*2 + 1]);
				count2.push_back(1);

				//デバッグ用

				cout << "count2:";
				for(auto i = 0; i < count2.size(); i++)
					{
						cout << count2[i] << ',';
					}

				cout << endl;
				//デバッグ用
				break;

			}
		}

	}

	//デバッグ用コード
	for(auto i = 0; i < vec1.size(); i++)
		{
			cout << vec1[i] << ',';
		}
	cout << endl;

	for(auto i = 0; i < vec2.size(); i++)
		{
			cout << vec2[i] << ',';
		}

	cout << endl;
	for(auto i = 0; i < count1.size(); i++)
		{
			cout << count1[i] << ',';
		}

	cout << endl;
	for(auto i = 0; i < count2.size(); i++)
		{
			cout << count2[i] << ',';
		}

	cout << endl;


	vector<int>::iterator iter1_1 = max_element(count1.begin(), count1.end());
	vector<int>::iterator iter2_1 = max_element(count2.begin(), count2.end());

    size_t index1_1 = distance(count1.begin(), iter1_1);
    size_t index2_1 = distance(count2.begin(), iter2_1);

	int obj1_1 = vec1[index1_1];
	int obj2_1 = vec2[index2_1];

    count1[index1_1] = 0;
    count2[index2_1] = 0;
    int maxkouho1_1 = *iter1_1;
    cout << "maxkouho1_1:" << maxkouho1_1 <<endl;
    int maxkouho2_1 = *iter2_1;

	vector<int>::iterator iter1_2 = max_element(count1.begin(), count1.end());
	vector<int>::iterator iter2_2 = max_element(count2.begin(), count2.end());

    size_t index1_2 = distance(count1.begin(), iter1_1);
    size_t index2_2 = distance(count2.begin(), iter2_1);

    cout << "maxkouho1_1:" << maxkouho1_1 <<endl;

	int obj1_2 = vec1[index1_2];
	int obj2_2 = vec2[index2_2];

	if(obj1_1 != obj2_1)
	{
		cout << maxkouho1_1 + maxkouho2_1;
	}
	else{
		cout << ((maxkouho1_1 + *iter2_2) > (*iter1_2 + maxkouho2_1) ? (maxkouho1_1 + *iter2_2) : (*iter1_2 + maxkouho2_1)) << endl;
	}



	return 0;
}
