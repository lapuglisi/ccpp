#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector<vector<string>> queries) {
  /*
  * Write your code here.
  */
  vector<int> result;
  unordered_map<string, int> entries;
  unordered_map<string, int>::iterator mit;
  
  string action;
  string value;

  for (vector<vector<string>>::const_iterator it = queries.begin(); it != queries.end(); it++) {
      action = (*it)[0];
      value = (*it)[1];

      if (action.compare("add") == 0) {

        printf("[contacts] add [%s]\n", value.c_str());
        
        // add entry
        string::const_iterator it = value.begin();
        for (int si = 0; (it + si) != value.end(); si++) {
            
            string key(it, it + si + 1);
            printf("  [key] %s\n", key.c_str());

            mit = entries.find(key);
            if (mit != entries.end())
            {
                mit->second += 1;
            }
            else
            {
                entries.insert(make_pair(key, 1));
            }
        }

        // Dump map
        for (mit = entries.begin(); mit != entries.end(); mit++)
        {
            printf("  [mit] %s => %d\n", mit->first.c_str(), mit->second);
        }
      } else if (action.compare("find") == 0) {
        
        printf("[contacts] find '%s'\n", value.c_str());

        int count = 0;
        mit = entries.find(value);
        if (mit != entries.end()) {
            count = mit->second;
        }
        
        result.push_back(count);
      }
  }

  return result;
}

int main()
{
    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];

        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
