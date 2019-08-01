#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    vector<double> res;
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;

    double median = 0;

    for (int i=0; i<a.size(); i++) {
            if (a[i] <= median) {
                    maxheap.push(a[i]);
            } else {
                    minheap.push(a[i]);
            }

            if (minheap.size() > maxheap.size()+1) {
                    maxheap.push(minheap.top());
                    minheap.pop();
            }
            if (maxheap.size() > minheap.size()+1) {
                    minheap.push(maxheap.top());
                    maxheap.pop();
            }

            if (minheap.size() == maxheap.size()) {
                    median = (maxheap.top() + minheap.top())/2.0;
            } else if(minheap.size() > maxheap.size()) {
                    median = (double)minheap.top();
            } else if (minheap.size() < maxheap.size()) {
                    median = (double)maxheap.top();
            }
            res.push_back(median);
    }
    return res;
}

int main()
{
    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << fixed << setprecision(1) << result[result_itr];

        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
